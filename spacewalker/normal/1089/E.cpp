#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
 
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
using i64 = long long;
//using i128 = __int128;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i,x,y) for (int i = (x); i < (y); i++)
#define sz(A) (int)(A.size())
#define pb push_back
#define int long long
    
void printans(vii &vec) {
    for (auto [a,b]: vec) {
        cout<<(char)('a' + a)<<b+1<<" ";
    }cout<<"\n";
}
                                  // compact list of primes
void solve() {
    int n;cin>>n;
    n++;
    vii ss;
    set<ii> canremove;
    auto addcol = [&](int x, bool up) {
        rep(i, 0, 8) {
            ss.push_back({x, up? i : 7-i});
            if (i != 0 && i!= 7) {
                canremove.insert({x,i});
            }
        }
    };
    if (n <= 15) {
        addcol(0, true);
        rep(i,1, 8) {
            ss.push_back({i, 7});
            if (i != 7) {
                canremove.insert({i,7});
            }
        }
    } else if ( n <= 33) {
        addcol(0, true);
        addcol(1, false);
        addcol(2, true);
        addcol(3, false);
        addcol(4, true);
        rep(i, 5, 8) {
            ss.push_back({i, 7});
        }
    } else {
       addcol(0, true);
        addcol(1, false);
        addcol(2, true);
        addcol(3, false);
        addcol(4, true);
        ss.push_back({6,7});
        ss.push_back({5,7});
        for (int i = 6; i >=0; i--) {
            if (i%2==0) {
                ss.push_back({5, i});
                ss.push_back({6,i});
            } else {
                ss.push_back({6,i});
                ss.push_back({5,i});
            }
        }
        addcol(7, true); 
    }
    int torem = ss.size() - n;
    vii fans;
    for (auto p:ss) {
        if (torem != 0 && canremove.find(p)!= canremove.end()) {
            torem--;
        } else {
            fans.push_back(p);
        }
    }
    printans(fans);
}


signed main() {
    solve();
}