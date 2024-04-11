#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    int ans = n;
    for (int st = 0; st < 4; ++st) {
      vector<int> dp(4, n);
      dp[st] = 0;
      for (int i = 0; i < n; ++i) {
        vector<int> new_dp(4, n);
        for (int j = 1; j < 7; ++j) {
          new_dp[j % 4] = min(new_dp[j % 4], dp[j / 2] + ((s[i] == 'L') != (j & 1)));
        }
        swap(dp, new_dp);
      }
      ans = min(ans, dp[st]);
    }
    cout << ans << "\n";
  }
  return 0;
}