#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int k;
  cin >> k;
  vector<vector<long long>> dp(k, vector<long long>(6, 0));
  for (int i = 0; i < 6; i++){
    dp[0][i] = 1;
  }
  for (int i = 0; i < k - 1; i++){
    for (int j = 0; j < 6; j++){
      for (int l = 0; l < 6; l++){
        for (int m = 0; m < 6; m++){
          if (j != m && j != 5 - m && l != m && l != 5 - m){
            dp[i + 1][m] += dp[i][j] * dp[i][l];
            dp[i + 1][m] %= MOD;
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < 6; i++){
    ans += dp[k - 1][i];
  }
  ans %= MOD;
  cout << ans << endl;
}