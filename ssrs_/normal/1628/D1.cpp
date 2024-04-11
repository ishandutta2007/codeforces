#include <bits/stdc++.h>
using namespace std;
const long long HALF = 500000004;
const long long MOD = 1000000007;
int main(){
  vector<vector<long long>> dp(2001, vector<long long>(2001, 0));
  for (int i = 1; i <= 2000; i++){
    dp[i][0] = i;
  }
  for (int i = 1; i <= 2000; i++){
    for (int j = 1; j <= 2000; j++){
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * HALF % MOD;
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    cout << dp[m][n - m] * k % MOD << endl;
  }
}