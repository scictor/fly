/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                    _______    _                                     *
 *                   (  ____ \  ( \     |\     /|                      * 
 *                   | (    \/  | (     ( \   / )                      *
 *                   | (__      | |      \ (_) /                       *
 *                   |  __)     | |       \   /                        *
 *                   | (        | |        ) (                         *
 *                   | )        | (____/\  | |                         *
 *                   |/         (_______/  \_/                         *
 *                                                                     *
 *                                                                     *
 *     fly is an awesome c++11 network library.                        *
 *                                                                     *
 *   @author: lichuan                                                  *
 *   @qq: 308831759                                                    *
 *   @email: 308831759@qq.com                                          *
 *   @github: https://github.com/lichuan/fly                           *
 *   @date: 2015-06-10 13:33:17                                        *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <cstdint>
#include <atomic>
#include <functional>

#ifndef FLY__BASE__COMMON
#define FLY__BASE__COMMON

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

namespace fly {
namespace base {

static void __void_cb__() {}

class Scope_CB
{
public:
    Scope_CB(std::function<void()> cb0, std::function<void()> cb1 = __void_cb__, std::function<void()> cb2 = __void_cb__, \
             std::function<void()> cb3 = __void_cb__, std::function<void()> cb4 = __void_cb__, std::function<void()> cb5 = __void_cb__, \
             std::function<void()> cb6 = __void_cb__, std::function<void()> cb7 = __void_cb__);
    void set_cur_cb(uint8 index);
    ~Scope_CB();
    std::function<void()> m_cbs[8];
    uint8 m_index = 0;
};

class ID_Allocator
{
public:
    uint64 new_id();

private:
    std::atomic<uint64> m_id {1};
};

uint32 random_between(uint32 min, uint32 max);
uint32 random_32();
uint64 random_64();
bool rate_by_percent(uint32 rate);    
bool rate_by_thousand(uint32 rate);

}
}

#endif
