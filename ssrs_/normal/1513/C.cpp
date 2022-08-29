#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int MAX = 200000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<vector<long long>>> dp(MAX + 1, vector<vector<long long>>(10, vector<long long>(10, 0)));
  for (int i = 0; i < 10; i++){
    dp[0][i][i] = 1;
  }
  for (int i = 0; i < MAX; i++){
    for (int j = 0; j < 10; j++){
      for (int k = 0; k < 10; k++){
        if (k < 9){
          dp[i + 1][j][k + 1] += dp[i][j][k];
          dp[i + 1][j][k + 1] %= MOD;
        } else {
          dp[i + 1][j][0] += dp[i][j][k];
          dp[i + 1][j][0] %= MOD;
          dp[i + 1][j][1] += dp[i][j][k];
          dp[i + 1][j][1] %= MOD;
        }
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    while (n > 0){
      int c = n % 10;
      for (int j = 0; j < 10; j++){
        ans += dp[m][c][j];
        ans %= MOD;
      }
      n /= 10;
    }
    cout << ans << "\n";
  }
}