#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<long long>> binom(n, vector<long long>(n, 0));
  for (int i = 0; i < n; i++){
    binom[i][0] = 1;
    for (int j = 1; j < i; j++){
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
    }
    binom[i][i] = 1;
  }
  int m = (n - 1) * (n - 2) / 2;
  vector<vector<long long>> POW(k + 1, vector<long long>(m + 1, 1));
  for (int i = 1; i <= k; i++){
    for (int j = 0; j < m; j++){
      POW[i][j + 1] = POW[i][j] * i % MOD;
    }
  }
  vector<vector<long long>> dp(k + 1, vector<long long>(n, 0));
  dp[0][0] = 1;
  for (int i = 0; i < k; i++){
    for (int j = 0; j < n; j++){
      for (int l = j; l < n; l++){
        long long add = dp[i][j];
        add *= binom[n - 1 - j][l - j];
        add %= MOD;
        int c = (l - j) * (l - j - 1) / 2 + (l - j) * (n - 1 - l);
        add *= POW[i + 1][c];
        add %= MOD;
        dp[i + 1][l] += add;
        dp[i + 1][l] %= MOD;
      }
    }
  }
  cout << dp[k][n - 1] << endl;
}