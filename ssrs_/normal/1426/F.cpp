#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<long long>> dp(n + 1, vector<long long>(4, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++){
    dp[i + 1] = dp[i];
    if (s[i] == 'a'){
      dp[i + 1][1] += dp[i][0];
      dp[i + 1][1] %= MOD;
    }
    if (s[i] == 'b'){
      dp[i + 1][2] += dp[i][1];
      dp[i + 1][2] %= MOD;
    }
    if (s[i] == 'c'){
      dp[i + 1][3] += dp[i][2];
      dp[i + 1][3] %= MOD;
    }
    if (s[i] == '?'){
      dp[i + 1][0] = dp[i][0] * 3;
      dp[i + 1][0] %= MOD;
      dp[i + 1][1] = dp[i][1] * 3 + dp[i][0];
      dp[i + 1][1] %= MOD;
      dp[i + 1][2] = dp[i][2] * 3 + dp[i][1];
      dp[i + 1][2] %= MOD;
      dp[i + 1][3] = dp[i][3] * 3 + dp[i][2];
      dp[i + 1][3] %= MOD;
    }
  }
  cout << dp[n][3] << endl;
}