#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  vector<int> b;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    b.push_back(v);
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  reverse(b.begin(), b.end());
  vector<vector<int>> dp(n, vector<int>(k + 1, 0));
  for (int v : b){
    if (c[v].empty()){
      dp[v][0] = 1;
    } else {
      int d = c[v].size();
      vector<vector<int>> S(d, vector<int>(k + 2, 0));
      for (int i = 0; i < d; i++){
        for (int j = 0; j <= k; j++){
          S[i][1] += dp[c[v][i]][j];
          if (S[i][1] >= MOD){
            S[i][1] -= MOD;
          }
          if (j < k){
            S[i][j + 2] += dp[c[v][i]][j];
          }
        }
        for (int j = 1; j <= k; j++){
          S[i][j + 1] += S[i][j];
          if (S[i][j + 1] >= MOD){
            S[i][j + 1] -= MOD;
          }
        }
      }
      vector<vector<long long>> dp2(2, vector<long long>(n + 1, 0));
      for (int i = 0; i <= k; i++){
        dp2[0][0] = 1;
        for (int j = 0; j < d; j++){
          dp2[0][j + 1] = dp2[0][j] * S[j][min(i, k + 1 - i)];
          dp2[1][j + 1] = dp2[0][j] * (S[j][i + 1] - S[j][i] + MOD) + dp2[1][j] * S[j][min(i + 1, k + 1 - i)];
          dp2[0][j + 1] %= MOD;
          dp2[1][j + 1] %= MOD;
        }
        dp[v][i] = dp2[1][d];
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= k; i++){
    ans += dp[0][i];
  }
  ans %= MOD;
  cout << ans << endl;
}