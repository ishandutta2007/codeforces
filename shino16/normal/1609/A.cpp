#line 2 "lib/prelude.hpp"
#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define repr2(i, m, n) for (auto i = (n); i-- > (m);)
#define repr(i, n) repr2(i, 0, n)
#define all(x) begin(x), end(x)
#line 3 "lib/bit/ctz.hpp"

template <class T>
__attribute__ ((target ("bmi"))) int ctz(T x) {
    using uint = unsigned int;
    using ull = unsigned long long;
    if (!x) return sizeof(T) * 8;
    if constexpr (sizeof(T) <= sizeof(uint)) {
        return __builtin_ctz((uint)x);
    } else if constexpr (sizeof(T) <= sizeof(ull)) {
        return __builtin_ctzll((ull)x);
    } else if constexpr (sizeof(T) <= sizeof(ull) * 2) {
        int l = ctz((ull)x);
        return l != sizeof(ull) * 8 ? l : l + ctz((ull)(x >> sizeof(ull) * 8));
    }
}
#line 3 "main.cpp"

int t, n, a[15], k;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    rep(i, n) scanf("%d", a+i);
    k = 0;
    rep(i, n) k += ctz(a[i]), a[i] >>= ctz(a[i]);
    int mx = *max_element(a, a+n);
    printf("%lld\n", (ll(mx) << k) + accumulate(a, a+n, 0LL) - mx);
  }
}