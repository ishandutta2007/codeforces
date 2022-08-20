#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  vector<vector<int>> lcp(n, vector<int>(n));
  for (int i = n - 1; ~i; --i) {
    for (int j = i + 1; j < n; ++j) {
      if (s[i] == s[j]) {
        lcp[i][j] = 1 + (j == n - 1 ? 0 : lcp[i + 1][j + 1]);
      }
    }
  }
  vector<int> dp(n + 1, n * a);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = min(dp[i + 1], dp[i] + a);
    int len = 0;
    for (int j = 0; j < i; ++j) {
      len = max(len, min(i - j, lcp[j][i]));
    }
    dp[i + len] = min(dp[i + len], dp[i] + b);
  }
  cout << dp[n] << "\n";
  return 0;
}