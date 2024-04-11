#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<vector<long long>> dp(n + 1, vector<long long>(11));
  long long ans = 0;
  for (int i = n - 1; ~i; --i) {
    int digit = s[i] - '0';
    for (int j = digit + 1; j < 11; ++j) {
      dp[i][j] += dp[i + 1][(j * (j - 1) / 2 + digit + 10) % 11] + 1;
    }
    if (digit) {
      ans += dp[i + 1][digit] + 1;
    }
  }
  cout << ans << "\n";
  return 0;
}