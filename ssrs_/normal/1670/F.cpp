#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long solve(int n, long long r, long long z){
  vector<vector<long long>> binom(n + 1, vector<long long>(n + 1, 0));
  for (int i = 0; i <= n; i++){
    binom[i][0] = 1;
    for (int j = 1; j < i; j++){
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
    }
    binom[i][i] = 1;
  }
  vector<vector<vector<long long>>> dp(61, vector<vector<long long>>(2, vector<long long>(n + 1, 0)));
  dp[0][0][0] = 1;
  for (int i = 0; i < 60; i++){
    for (int j = 0; j < 2; j++){
      for (int k = 0; k <= n; k++){
        for (int l = 0; l <= n; l++){
          if (l % 2 == (z >> i & 1)){
            int j2 = j;
            if ((k + l) % 2 == 1 && (r >> i & 1) == 0){
              j2 = 1;
            }
            if ((k + l) % 2 == 0 && (r >> i & 1) == 1){
              j2 = 0;
            }
            int k2 = (k + l) / 2;
            dp[i + 1][j2][k2] += dp[i][j][k] * binom[n][l] % MOD;
            dp[i + 1][j2][k2] %= MOD;
          }
        }
      }
    }
  }
  return dp[60][0][0];
}
int main(){
  int n;
  long long l, r, z;
  cin >> n >> l >> r >> z;
  cout << (solve(n, r, z) - solve(n, l - 1, z) + MOD) % MOD << endl;
}