#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<vector<bool>> ok(10, vector<bool>(10, false));
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    ok[u][v] = true;
    ok[v][u] = true;
  }
  vector<vector<int>> nxt(1 << 10, vector<int>(10));
  for (int i = 0; i < (1 << 10); i++){
    for (int j = 0; j < 10; j++){
      if ((i >> j & 1) == 1){
        nxt[i][j] = i;
        for (int k = 0; k < j; k++){
          if (ok[j][k]){
            nxt[i][j] &= ~(1 << k);
          } else {
            nxt[i][j] |= 1 << k;
          }
        }
        for (int k = j + 1; k < 10; k++){
          if (!ok[j][k]){
            nxt[i][j] |= 1 << k;
          }
        }
      }
    }
  }
  vector<long long> dp(1 << 10, 0);
  dp[(1 << 10) - 1] = 1;
  for (int i = 0; i < n; i++){
    vector<long long> dp2(1 << 10, 0);
    for (int j = 0; j < (1 << 10); j++){
      for (int k = 0; k < 10; k++){
        if ((j >> k & 1) == 1){
          dp2[nxt[j][k]] += dp[j];
          dp2[nxt[j][k]] %= MOD;
        }
      }
    }
    swap(dp, dp2);
  }
  long long ans = 0;
  for (int i = 0; i < (1 << 10); i++){
    ans += dp[i];
  }
  ans %= MOD;
  cout << ans << endl;
}