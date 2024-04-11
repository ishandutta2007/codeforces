#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, r;
  cin >> n >> r;
  vector<int> f(n), s(n);
  vector<double> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> f[i] >> s[i] >> p[i];
    p[i] /= 100;
  }
  int ss = accumulate(begin(s), end(s), 0);
  auto chk = [&](double m) {
    vector dp(n + 1, vector<double>(ss + 1));
    fill(begin(dp[n]) + r + 1, end(dp[n]), m);
    for (int i = n; i--; ) {
      for (int t = 0; t + s[i] <= ss; ++t) {
        double c = 0;
        c += p[i] * (f[i] + dp[i + 1][t + f[i]]);
        c += (1 - p[i]) * (s[i] + dp[i + 1][t + s[i]]);
        dp[i][t] = min(c, m);
      }
    }
    return dp[0][0] < m;
  };
  double ng = 0, ok = 1e10;
  for (int _ = 100; _--; ) {
    auto mid = (ng + ok) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}