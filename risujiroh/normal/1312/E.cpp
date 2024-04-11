#include <bits/stdc++.h>
using namespace std;

auto chmin = [](auto&& l, auto r) { return r < l ? l = r, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  vector<vector<int>> dp(n, vector<int>(n + 1, n + 1));
  vector<vector<int>> v(n, vector<int>(n + 1, -1));
  for (int r = 1; r <= n; ++r) {
    for (int l = r; l--; ) {
      if (r - l == 1) {
        dp[l][r] = 1;
        v[l][r] = a[l];
        continue;
      }
      for (int m = l + 1; m < r; ++m) {
        chmin(dp[l][r], dp[l][m] + dp[m][r]);
        if (dp[l][m] == 1 and dp[m][r] == 1) {
          if (v[l][m] == v[m][r]) {
            dp[l][r] = 1;
            v[l][r] = v[l][m] + 1;
          }
        }
      }
    }
  }
  cout << dp[0][n] << '\n';
}