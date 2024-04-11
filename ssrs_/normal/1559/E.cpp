#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++){
    cin >> l[i] >> r[i];
    r[i]++;
  }
  vector<long long> C(m + 1, 0);
  for (int i = 1; i <= m; i++){
    vector<vector<long long>> dp(n + 1, vector<long long>(m / i + 1, 0));
    dp[0][0] = 1;
    for (int j = 0; j < n; j++){
      int L = (l[j] + i - 1) / i;
      int R = (r[j] + i - 1) / i;
      for (int k = 0; k <= m / i; k++){
        if (k + L <= m / i){
          dp[j + 1][k + L] += dp[j][k];
        }
        if (k + R <= m / i){
          dp[j + 1][k + R] += MOD - dp[j][k];
        }
      }
      dp[j + 1][0] %= MOD;
      for (int k = 0; k < m / i; k++){
        dp[j + 1][k + 1] += dp[j + 1][k];
        dp[j + 1][k + 1] %= MOD;
      }
    }
    for (int j = 0; j <= m / i; j++){
      C[i] += dp[n][j];
    }
  }
  vector<bool> prime(m + 1, true);
  for (int i = 2; i <= m; i++){
    if (prime[i]){
      for (int j = i * 2; j <= m; j += i){
        prime[j] = false;
      }
    }
  }
  vector<int> mobius(m, 1);
  for (int i = 2; i * i <= m; i++){
    for (int j = i * i; j <= m; j += i * i){
      mobius[j] = 0;
    }
  }
  for (int i = 2; i <= m; i++){
    if (prime[i]){
      for (int j = i; j <= m; j += i){
        mobius[j] *= -1;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= m; i++){
    ans += C[i] * mobius[i] + MOD;
  }
  ans %= MOD;
  cout << ans << endl;
}