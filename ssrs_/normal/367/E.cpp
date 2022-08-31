#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int n, m, x;
  cin >> n >> m >> x;
  x--;
  if (n > m){
    cout << 0 << endl;
  } else {
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= m; i++){
      vector<vector<long long>> dp2(n + 1, vector<long long>(n + 1, 0));
      for (int j = 0; j <= n; j++){
        for (int k = 0; k <= n; k++){
          if (i != x){
            dp2[j][k] += dp[j][k];
            dp2[j][k] %= MOD;
            if (j + 1 <= k){
              dp2[j + 1][k] += dp[j][k];
              dp2[j + 1][k] %= MOD;
            }
          }
          if (k < n){
            dp2[j][k + 1] += dp[j][k];
            dp2[j][k + 1] %= MOD;
          }
          if (k > j && k < n){
            dp2[j + 1][k + 1] += dp[j][k];
            dp2[j + 1][k + 1] %= MOD;
          }
        }
      }
      swap(dp, dp2);
    }
    long long ans = dp[n][n];
    for (int i = 1; i <= n; i++){
      ans *= i;
      ans %= MOD;
    }
    cout << ans << endl;
  }
}