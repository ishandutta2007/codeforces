#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n, x;
  cin >> n >> x;
  vector<vector<long long>> binom(n + 1, vector<long long>(n + 1, 1));
  for (int i = 2; i <= n; i++){
    for (int j = 1; j < i; j++){
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
    }
  }
  vector<vector<long long>> POW(n + 1, vector<long long>(n + 1, 1));
  for (int i = 0; i <= n; i++){
    for (int j = 0; j < n; j++){
      POW[i][j + 1] = POW[i][j] * i % MOD;
    }
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
  for (int i = 2; i <= n; i++){
    for (int j = 1; j <= x; j++){
      int j2 = max(j - i + 1, 0);
      if (j < i){
        dp[i][j] = POW[j][i];
      } else {
        dp[i][j] = POW[i - 1][i];
        for (int k = 0; k < i; k++){
          dp[i][j] += dp[i - k][j2] * POW[i - 1][k] % MOD * binom[i][k];
          dp[i][j] %= MOD;
        }
      }
    }
  }
  cout << dp[n][x] << endl;
}