#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++){
    char c;
    cin >> c;
    if (c == '-'){
      A[i] = -1;
    } else {
      cin >> A[i];
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++){
    if (A[i] > 0){
      vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
      dp[0][0] = 1;
      for (int j = 0; j < n; j++){
        for (int k = 0; k <= j; k++){
          dp[j + 1][k] += dp[j][k];
          dp[j + 1][k] %= MOD;
          if (j != i){
            if (A[j] > 0){
              if ((j < i && A[j] == A[i]) || A[j] < A[i]){
                dp[j + 1][k + 1] += dp[j][k];
                dp[j + 1][k + 1] %= MOD;
              } else {
                dp[j + 1][k] += dp[j][k];
                dp[j + 1][k] %= MOD;
              }
            } else {
              if (k > 0){
                dp[j + 1][k - 1] += dp[j][k];
                dp[j + 1][k - 1] %= MOD;
              } else if (j < i){
                dp[j + 1][k] += dp[j][k];
                dp[j + 1][k] %= MOD;
              }
            }
          }
        }
      }
      for (int j = 0; j <= n; j++){
        ans += A[i] * dp[n][j] % MOD;
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
}