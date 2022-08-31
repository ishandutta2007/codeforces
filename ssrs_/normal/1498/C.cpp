#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    long long ans = 1;
    if (k > 1){
      vector<vector<long long>> dp(k - 1, vector<long long>(n, 0));
      for (int j = 0; j < n; j++){
        dp[0][j] = 1;
      }
      for (int j = 0; j < k - 2; j++){
        if (j % 2 == 0){
          long long sum = 0;
          for (int l = n - 1; l >= 0; l--){
            dp[j + 1][l] = sum;
            sum += dp[j][l];
            sum %= MOD;
          }
        } else {
          long long sum = 0;
          for (int l = 0; l < n; l++){
            dp[j + 1][l] = sum;
            sum += dp[j][l];
            sum %= MOD;
          }
        }
      }
      for (int j = 0; j < k - 1; j++){
        for (int l = 0; l < n; l++){
          ans += dp[j][l];
        }
      }
      ans %= MOD;
    }
    cout << ans << endl;
  }
}