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
template <class T>
auto ndvec(size_t n, T&& x) { return vector(n, forward<T>(x)); }
template <class... Ts>
auto ndvec(size_t n, Ts&&... xs) { return vector(n, forward<Ts>(xs)...); }
#line 2 "main.cpp"

int h, w;
char S[400][401];
int sums[401][401];
int cm[401];

int ones(int l, int r, int u, int d) {
  return sums[u][l] - sums[d][l] - sums[u][r] + sums[d][r];
}
int zeros(int l, int r, int u, int d) {
  return (r - l) * (d - u) - ones(l, r, u, d);
}

void solve() {
  scanf("%d%d", &h, &w);
  rep(i, h) scanf("%s", S[i]);
  rep(i, h) rep(j, w) sums[i + 1][j + 1] = S[i][j] == '1';
  rep(i, h) rep(j, w + 1) sums[i + 1][j] += sums[i][j];
  rep(i, h + 1) rep(j, w) sums[i][j + 1] += sums[i][j];

  int ans = INT_MAX;
  rep(u, h) rep2(d, u + 4, h) {
    fill(cm, cm + w + 1, INT_MIN);
    int cost = 0;
    rep(i, w) {
      cost += ones(i, i + 1, u + 1, d) + (S[u][i] == '0') + (S[d][i] == '0');
      int fi = ones(0, i + 1, u + 1, d) + zeros(0, i + 1, u, u + 1) +
               zeros(0, i + 1, d, d + 1) - zeros(i, i + 1, u + 1, d);
      cm[i + 1] = max(cm[i], fi);
      if (i - 1 > 0 && i + 1 < w)
        ans = min(ans, cost - cm[i - 1] + zeros(i + 1, i + 2, u + 1, d));
    }
  }
  printf("%d\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}