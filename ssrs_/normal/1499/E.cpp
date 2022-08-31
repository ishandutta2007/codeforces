#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  string x;
  cin >> x;
  string y;
  cin >> y;
  int n = x.size(), m = y.size();
  set<int> stx;
  stx.insert(-1);
  for (int i = 0; i < n - 1; i++){
    if (x[i] == x[i + 1]){
      stx.insert(i);
    }
  }
  set<int> sty;
  sty.insert(-1);
  for (int i = 0; i < m - 1; i++){
    if (y[i] == y[i + 1]){
      sty.insert(i);
    }
  }
  vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(n, vector<long long>(m, 0)));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (x[i] != y[j]){
        dp[0][i][j] = j - *prev(sty.lower_bound(j));
        dp[1][i][j] = i - *prev(stx.lower_bound(i));
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (i < n - 1){
        if (x[i] != x[i + 1]){
          dp[0][i + 1][j] += dp[0][i][j];
        }
        if (y[j] != x[i + 1]){
          dp[0][i + 1][j] += dp[1][i][j];
        }
        dp[0][i + 1][j] %= MOD;
      }
      if (j < m - 1){
        if (x[i] != y[j + 1]){
          dp[1][i][j + 1] += dp[0][i][j];
        }
        if (y[j] != y[j + 1]){
          dp[1][i][j + 1] += dp[1][i][j];
        }
        dp[1][i][j + 1] %= MOD;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      ans += dp[0][i][j];
      ans += dp[1][i][j];
    }
  }
  ans %= MOD;
  cout << ans << endl;
}