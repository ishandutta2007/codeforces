#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int>> p(26, vector<int>(n, -1));
  for (int i = 0; i < n - 1; i++){
    for (int j = 0; j < 26; j++){
      p[j][i + 1] = p[j][i];
    }
    p[s[i] - 'a'][i + 1] = i;
  }
  vector<int> prev(n);
  for (int i = 0; i < n; i++){
    prev[i] = p[s[i] - 'a'][i];
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++){
    long long sum = 0;
    for (int j = 0; j <= n; j++){
      sum += dp[i][j];
      dp[i + 1][j] = sum % MOD;
    }
    if (prev[i] != -1){
      long long sum = 0;
      for (int j = 0; j <= n; j++){
        dp[i + 1][j] -= sum % MOD;
        sum += dp[prev[i] + 1][j];
        dp[i + 1][j] += MOD;
        dp[i + 1][j] %= MOD;
      }
    }
  }
  cout << dp[n][n] << endl;
}