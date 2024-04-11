#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, W;
  cin >> n >> m >> W;
  vector<int> w(n);
  for (int i = 0; i < n; i++){
    cin >> w[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  vector<int> g(n, -1);
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (g[i] == -1){
      g[i] = cnt;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (g[w] == -1){
            g[w] = cnt;
            Q.push(w);
          }
        }
      }
      cnt++;
    }
  }
  vector<vector<int>> v(cnt);
  for (int i = 0; i < n; i++){
    v[g[i]].push_back(i);
  }
  vector<int> w_sum(cnt, 0);
  vector<int> b_sum(cnt, 0);
  for (int i = 0; i < n; i++){
    w_sum[g[i]] += w[i];
    b_sum[g[i]] += b[i];
  }
  vector<vector<int>> dp(cnt + 1, vector<int>(W + 1, 0));
  for (int i = 0; i < cnt; i++){
    for (int j = 0; j <= W; j++){
      dp[i + 1][j] = dp[i][j];
    }
    for (int j = w_sum[i]; j <= W; j++){
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w_sum[i]] + b_sum[i]);
    }
    for (int x : v[i]){
      for (int j = w[x]; j <= W; j++){
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w[x]] + b[x]);
      }
    }
  }
  cout << dp[cnt][W] << endl;
}