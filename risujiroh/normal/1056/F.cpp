#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    double c, T; cin >> c >> T;
    V<> a(n), p(n); for (int i = 0; i < n; ++i) cin >> a[i] >> p[i];
    V<> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int i, int j) { return a[i] > a[j]; });
    V<double> powm(n + 1);
    for (int j = 1; j <= n; ++j) {
      powm[j] = 1 / pow(0.9, j);
    }
    VV<double> dp(n + 1, V<double>(10 * n + 1, 1e99));
    dp[0][0] = 0;
    for (int i : idx) {
      auto ndp = dp;
      for (int j = 1; j <= n; ++j) for (int x = p[i]; x <= 10 * n; ++x) {
        ndp[j][x] = min(ndp[j][x], dp[j - 1][x - p[i]] + a[i] * powm[j]);
      }
      swap(dp, ndp);
    }
    int res = 0;
    for (int j = 1; j <= n; ++j) for (int x = 0; x <= 10 * n; ++x) {
      double t = (sqrt(c * dp[j][x]) - 1) / c;
      t = max(t, 0.0);
      if (t + 10 * j + dp[j][x] / (1 + c * t) < T - 1e-9) {
        res = max(res, x);
      }
    }
    cout << res << '\n';
  }
}