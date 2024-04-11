#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int r, g, b;
  cin >> r >> g >> b;
  vector dp(r + 1, vector(g + 1, vector<int>(b + 1)));
  vector<int> x(r), y(g), z(b);
  for (auto&& e : x) cin >> e;
  for (auto&& e : y) cin >> e;
  for (auto&& e : z) cin >> e;
  sort(begin(x), end(x), greater<>());
  sort(begin(y), end(y), greater<>());
  sort(begin(z), end(z), greater<>());
  int res = 0;
  for (int i = 0; i <= r; ++i) {
    for (int j = 0; j <= g; ++j) {
      for (int k = 0; k <= b; ++k) {
        if (i < r and j < g)
          dp[i + 1][j + 1][k] =
              max(dp[i + 1][j + 1][k], dp[i][j][k] + x[i] * y[j]);
        if (i < r and k < b)
          dp[i + 1][j][k + 1] =
              max(dp[i + 1][j][k + 1], dp[i][j][k] + x[i] * z[k]);
        if (j < g and k < b)
          dp[i][j + 1][k + 1] =
              max(dp[i][j + 1][k + 1], dp[i][j][k] + y[j] * z[k]);
        res = max(res, dp[i][j][k]);
      }
    }
  }
  cout << res << '\n';
}