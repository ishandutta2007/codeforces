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

int main() {
  int h, w; scanf("%d%d", &h, &w);
  int C[h][w];
  rep(i, h) rep(j, w) scanf("%d", &C[i][j]);

  ll ans = 0;
  vector<ll> s(100001), d(100001);
  rep(i, h) {
    rep(j, w) {
      ans += 1LL * d[C[i][j]] * i - s[C[i][j]];
      s[C[i][j]] += i, d[C[i][j]]++;
    }
  }
  fill(all(s), 0);
  fill(all(d), 0);
  rep(j, w) {
    rep(i, h) {
      ans += 1LL * d[C[i][j]] * j - s[C[i][j]];
      s[C[i][j]] += j, d[C[i][j]]++;
    }
  }
  printf("%lld\n", ans);
}