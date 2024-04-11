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
#line 2 "main.cpp"

int T, n, a[1000][1000];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    rep(r, n) rep(c, n) scanf("%d", a[r]+c);
    int tot = 0;
    rep(r, n) rep(c, n) if ((r+c) % 2 == 0 && r < n-1 && c < n-1) {
      int d = min({r, c, n-2-r, n-2-c});
      if (d % 4 < 2) tot ^= a[r][c];
    } else if ((r+c) % 2 == 1 && r < n-1 && c > 0) {
      int d = min({r, c-1, n-2-r, n-1-c});
      if (d % 4 < 2) tot ^= a[r][c];
    }
    printf("%d\n", tot);
  }
}