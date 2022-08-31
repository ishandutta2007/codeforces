#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2, 0)));
  for (int i = 0; i < n; i++){
    int x = s[i] - '0';
    dp[i + 1] = dp[i];
    dp[i + 1][0][x] = max(dp[i + 1][0][x], dp[i][0][1 - x] + 1);
    dp[i + 1][1][1 - x] = max(dp[i + 1][1][1 - x], dp[i][1][x] + 1);
    dp[i + 1][1][1 - x] = max(dp[i + 1][1][1 - x], dp[i][0][x] + 1);
    dp[i + 1][2][x] = max(dp[i + 1][2][x], dp[i][2][1 - x] + 1);
    dp[i + 1][2][x] = max(dp[i + 1][2][x], dp[i][1][1 - x] + 1);
  }
  int ans = 0;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 2; j++){
      ans = max(ans, dp[n][i][j]);
    }
  }
  cout << ans << endl;
}