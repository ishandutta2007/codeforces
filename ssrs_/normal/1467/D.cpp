#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<long long>> dp(k + 1, vector<long long>(n, 0));
  for (int i = 0; i < n; i++){
    dp[0][i] = 1;
  }
  for (int i = 1; i <= k; i++){
    for (int j = 0; j < n; j++){
      if (j > 0){
        dp[i][j] += dp[i - 1][j - 1];
      }
      if (j < n - 1){
        dp[i][j] += dp[i - 1][j + 1];
      }
      dp[i][j] %= MOD;
    }
  }
  vector<long long> S(n, 0);
  for (int i = 0; i <= k; i++){
    for (int j = 0; j < n; j++){
      S[j] += dp[i][j] * dp[k - i][j];
      S[j] %= MOD;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++){
    ans += a[i] * S[i];
    ans %= MOD;
  }
  for (int j = 0; j < q; j++){
    int i, x;
    cin >> i >> x;
    i--;
    ans += (x - a[i] + MOD) % MOD * S[i] % MOD;
    ans %= MOD;
    cout << ans << endl;
    a[i] = x;
  }
}