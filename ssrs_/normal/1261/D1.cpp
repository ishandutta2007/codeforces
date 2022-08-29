#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; i++){
    cin >> h[i];
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(n * 2 + 1, 0));
  dp[0][n] = 1;
  for (int i = 0; i < n; i++){
    if (h[i] == h[(i + 1) % n]){
      for (int j = 0; j <= n * 2; j++){
        dp[i + 1][j] = dp[i][j] * k % MOD;
      }
    } else {
      for (int j = 1; j < n * 2; j++){
        dp[i + 1][j - 1] += dp[i][j];
        dp[i + 1][j] += dp[i][j] * (k - 2);
        dp[i + 1][j + 1] += dp[i][j];
      }
      for (int j = 0; j <= n * 2; j++){
        dp[i + 1][j] %= MOD;
      }
    }
  }
  long long ans = 0;
  for (int i = n + 1; i <= n * 2; i++){
    ans += dp[n][i];
    ans %= MOD;
  }
  cout << ans << endl;
}