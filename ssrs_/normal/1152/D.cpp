#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1000000000;
int main(){
  int n;
  cin >> n;
  vector<vector<vector<long long>>> dp(n * 2 + 1, vector<vector<long long>>(n + 1, vector<long long>(2, -INF)));
  dp[0][0][0] = 0;
  dp[0][0][1] = 0;
  for (int i = 1; i <= n * 2; i++){
    for (int j = 0; j <= min(i, n * 2 - i); j++){
      if (j == 0 ){
        dp[i][j][0] = max(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1] + 1);
        dp[i][j][1] = dp[i - 1][j + 1][0];
      } else if (j == n){
        dp[i][j][0] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1] + 1);
        dp[i][j][1] = dp[i - 1][j - 1][0];
      } else if (dp[i - 1][j - 1][0] == -INF){
        dp[i][j][0] = max(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1] + 1);
        dp[i][j][1] = dp[i - 1][j + 1][0];
      } else if (dp[i - 1][j + 1][0] == -INF){
        dp[i][j][0] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1] + 1);
        dp[i][j][1] = dp[i - 1][j - 1][0];
      } else {
        dp[i][j][0] = max({dp[i - 1][j - 1][1] + dp[i - 1][j + 1][0] + 1, dp[i - 1][j - 1][0] + dp[i - 1][j + 1][1] + 1, dp[i - 1][j - 1][0] + dp[i - 1][j + 1][0]});
        dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j + 1][0];
      }
      dp[i][j][0] %= MOD;
      dp[i][j][1] %= MOD;
    }
  }
  cout << dp[n * 2][0][0] << endl;
}