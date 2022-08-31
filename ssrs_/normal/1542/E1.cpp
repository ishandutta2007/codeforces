#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, mod;
  cin >> n >> mod;
  vector<long long> perm(n + 1);
  perm[0] = 1;
  for (int i = 0; i < n; i++){
    perm[i + 1] = perm[i] * (n - i) % mod;
  }
  int mx = n * (n - 1) / 2;
  vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(mx + 1, 0)));
  dp[0][0][0] = 1;
  for (int i = 0; i < n - 1; i++){
    for (int j = 0; j <= i; j++){
      for (int k = 0; k <= i * (i + 1) / 2; k++){
        for (int l = 0; l <= i + 1; l++){
          if (l <= j){
            dp[i + 1][j + 1][k + i + 1 - l] += dp[i][j][k];
            dp[i + 1][j + 1][k + i + 1 - l] %= mod;
          } else {
            dp[i + 1][j][k + i + 1 - l] += dp[i][j][k];
            dp[i + 1][j][k + i + 1 - l] %= mod;
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 3; i < n; i++){
    for (int j = 0; j <= i; j++){
      for (int k = j + 1; k <= i; k++){
        long long sum = 0;
        for (int l = 0; l <= mx; l++){
          ans += sum * dp[i][j][l] % mod * perm[n - 1 - i];
          ans %= mod;
          sum += dp[i][k][l];
          sum %= mod;
        }
      }
    }
  }
  cout << ans << endl;
}