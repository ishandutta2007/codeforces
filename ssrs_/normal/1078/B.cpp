#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> cnt(101, 0);
  for (int i = 0; i < n; i++){
    cnt[a[i]]++;
  }
  int cnt2 = 0;
  for (int i = 1; i <= 100; i++){
    if (cnt[i] > 0){
      cnt2++;
    }
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(10001, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++){
    vector<vector<long long>> dp2(n + 1, vector<long long>(10001, 0));
    for (int j = 0; j <= n; j++){
      for (int k = 0; k <= 10000; k++){
        dp2[j][k] += dp[j][k];
        if (j < n && k + a[i] <= 10000){
          dp2[j + 1][k + a[i]] += dp[j][k];
        }
      }
    }
    for (int j = 0; j <= n; j++){
      for (int k = 0; k <= 10000; k++){
        dp[j][k] = dp2[j][k] % MOD;
      }
    }
  }
  vector<vector<long long>> binom(101, vector<long long>(101, 0));
  for (int i = 0; i <= 100; i++){
    binom[i][0] = 1;
    binom[i][i] = 1;
  }
  for (int i = 2; i <= 100; i++){
    for (int j = 1; j < i; j++){
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
    }
  }
  int ans = 1;
  for (int i = 1; i <= 100; i++){
    for (int j = 1; j <= cnt[i]; j++){
      if (dp[j][i * j] == binom[cnt[i]][j]){
        ans = max(ans, j);
        if (j == cnt[i] && cnt2 == 2){
          ans = n;
        }
      }
    }
  }
  cout << ans << endl;
}