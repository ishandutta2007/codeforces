#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n;
  cin >> n;
  vector<int> c(26);
  for (int i = 0; i < 26; i++){
    cin >> c[i];
  }
  long long ans = 26 * 26;
  for (int i = 2; i < n; i++){
    ans *= 25;
    ans %= MOD;
  }
  vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(4, 0)));
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= i; j++){
      for (int k = 0; k < 4; k++){
        int a = (k & 1) << 1;
        if ((k & 2) == 0 && i >= 2){
          dp[i + 1][j][a] += dp[i][j][k] * 24;
        } else {
          dp[i + 1][j][a] += dp[i][j][k] * 25;
        }
        dp[i + 1][j][a] %= MOD;
        if ((k & 2) == 0){
          dp[i + 1][j + 1][a + 1] += dp[i][j][k];
          dp[i + 1][j + 1][a + 1] %= MOD;
        }
      }
    }
  }

  vector<vector<vector<long long>>> dp2(1, vector<vector<long long>>(1, vector<long long>(9, 0)));
  dp2[0][0][0] = 1;
  for (int i = 0; i < n; i++){
    vector<vector<vector<long long>>> dp3(i + 2, vector<vector<long long>>(i + 2, vector<long long>(9, 0)));
    for (int j = 0; j <= i; j++){
      for (int k = 0; k <= i - j; k++){
        for (int l = 0; l < 9; l++){
          int x = l / 3, y = l % 3;
          if (x == 0 && i >= 2){
            dp3[j][k][y * 3] += dp2[j][k][l] * 23;
          } else {
            dp3[j][k][y * 3] += dp2[j][k][l] * 24;
          }
          dp3[j][k][y * 3] %= MOD;
          if (x != 1){
            dp3[j + 1][k][y * 3 + 1] += dp2[j][k][l];
            dp3[j + 1][k][y * 3 + 1] %= MOD;
          }
          if (x != 2){
            dp3[j][k + 1][y * 3 + 2] += dp2[j][k][l];
            dp3[j][k + 1][y * 3 + 2] %= MOD;
          }
        }
      }
    }
    swap(dp2, dp3);
  }
  vector<vector<long long>> sum(n + 1, vector<long long>(n + 1, 0));
  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= n; j++){
      for (int k = 0; k < 9; k++){
        sum[i][j] += dp2[i][j][k];
        sum[i][j] %= MOD;
      }
    }
  }
  for (int i = 0; i <= n; i++){
    long long s = 0;
    for (int j = 0; j < 4; j++){
      s += dp[n][i][j];
    }
    s %= MOD;
  }
  for (int i = 0; i <= n; i++){
    for (int j = n - 1; j >= 0; j--){
      sum[i][j] += sum[i][j + 1];
      sum[i][j] %= MOD;
    }
  }
  for (int i = n - 1; i >= 0; i--){
    for (int j = 0; j <= n; j++){
      sum[i][j] += sum[i + 1][j];
      sum[i][j] %= MOD;
    }
  }
  vector<long long> s(26, 0);
  for (int i = 0; i < 26; i++){
    for (int j = c[i] + 1; j <= n; j++){
      for (int k = 0; k < 4; k++){
        s[i] += dp[n][j][k];
        s[i] %= MOD;
      }
    }
  }
  vector<vector<long long>> s2(26, vector<long long>(26, 0));
  for (int i = 0; i < 26; i++){
    for (int j = 0; j < 26; j++){
      if (c[i] < n && c[j] < n){
        s2[i][j] = sum[c[i] + 1][c[j] + 1];
      }
    }
  }
  for (int i = 0; i < 26; i++){
    ans += MOD - s[i];
    ans %= MOD;
  }
  for (int i = 0; i < 26; i++){
    for (int j = i + 1; j < 26; j++){
      ans += s2[i][j];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}