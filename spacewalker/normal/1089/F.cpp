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

typedef long long ll;

//typedef __int128_t lint;

typedef vector<ll> vll;

#define rep(i,x,y) for (int i = (x); i < (y); i++)
#define sz(A) (int)(A.size())
#define pb push_back
#define int long long
ll _sieve_size;
bitset<10000010> bs;                             // 10^7 is the rough limit
vll p;                                           // compact list of primes

void sieve(ll upperbound) {                      // range = [0..upperbound]
  _sieve_size = upperbound+1;                    // to include upperbound
  bs.set();                                      // all 1s
  bs[0] = bs[1] = 0;                             // except index 0+1
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    // cross out multiples of i starting from i*i
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    p.push_back(i);                              // add prime i to the list
  }
}

// second part
int getprimeFactors(ll N) {                         // pre-condition, N >= 1
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    if (N%p[i] == 0) {                        // found a prime for N
      return p[i];                                 // remove it from N
    }
  return N;             // remaining N is a prime
}


void solve() {
    int n;cin>>n;
    int pr = getprimeFactors(n);
    int num1 = 1;
    int num2 = n;
    while (num2%pr == 0) {
        num1 *= pr;
        num2 /= pr;
    }
    if (num1 == n) {
        cout<<"NO\n";return;
    }
    if (num1 > num2) {
        swap(num1, num2);
    }
    rep(i, 1, num1) {
        int a = i*num2;
        int rem = n-1 - a;
        if (rem%num1 == 0) {
            cout<<"YES\n";
            cout<<2<<"\n";
            int b = rem/num1;
            cout<<i<<" "<<num1<<"\n";
            cout<<b<<" "<<num2<<"\n";
            return;
        }
    }
}


signed main() {
    sieve(10000000);
    solve();
}