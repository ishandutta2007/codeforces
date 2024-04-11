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

int a[1<<16], b[1<<16];

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  rep(i, n/2) a[i] = i, b[i] = n-1-i;
  if (k == n - 1) {
    if (n == 4) return printf("-1\n"), void();
    b[0] = n-4;
    b[1] = 3;
    a[3] = n-2, b[3] = n-1;
  } else {
    int &v = k < n/2 ? a[k] : b[n-1-k];
    swap(a[0], v);
  }
  rep(i, n/2) printf("%d %d\n", a[i], b[i]);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}