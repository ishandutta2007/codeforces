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

int n, p[200000], l[200000], r[200000];
ll dp[200000];

void solve() {
  scanf("%d", &n);
  rep(i, n-1) scanf("%d", p+1+i), p[i+1]--;
  p[0] = 0;
  rep(i, n) scanf("%d%d", &l[i], &r[i]);
  fill(dp, dp+n, 0);
  int ans = 0;
  repr(i, n) {
    ll d = max(0LL, l[i] - dp[i]);
    if (d > 0) {
      dp[i] = r[i];
      ans++;
    }
    dp[i] = min<ll>(dp[i], r[i]);
    dp[p[i]] += dp[i];
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}