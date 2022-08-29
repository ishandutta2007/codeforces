#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, k, p;
  cin >> n >> m >> k >> p;
  vector<vector<long long>> binom(n, vector<long long>(n, 1));
  for (int i = 2; i < n; i++){
    for (int j = 1; j < i; j++){
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % p;
    }
  }
  vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(k + 2, 0)));
  for (int i = 0; i <= n; i++){
    dp[0][i][0] = 1;
  }
  for (int i = 1; i <= n; i++){
    for (int j = 0; j <= n - i; j++){
      for (int l = 0; l < i; l++){
        int X = min(k, l);
        for (int L = 0; L <= X; L++){
          int Y = min(k - L, i - 1 - l);
          for (int R = 0; R <= Y; R++){
            if (j == m - 1){
              dp[i][j][L + R + 1] += dp[l][j + 1][L] * dp[i - 1 - l][j + 1][R] % p * binom[i - 1][l] % p;
              if (dp[i][j][L + R + 1] >= p){
                dp[i][j][L + R + 1] -= p;
              }
            } else {
              dp[i][j][L + R] += dp[l][j + 1][L] * dp[i - 1 - l][j + 1][R] % p * binom[i - 1][l] % p;
              if (dp[i][j][L + R] >= p){
                dp[i][j][L + R] -= p;
              }
            }
          }
        }
      }
    }
  }
  cout << dp[n][0][k] << endl;
}