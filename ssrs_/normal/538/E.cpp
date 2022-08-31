#include <bits/stdc++.h>
using namespace std;
int INF = 10000000;
void dfs1(vector<vector<int>> &c, vector<int> &d, int v = 0){
  for (int w : c[v]){
    d[w] = d[v] + 1;
    dfs1(c, d, w);
  }
}
int dfs2(vector<vector<int>> &c, vector<int> &sz, int v = 0){
  if (c[v].empty()){
    sz[v] = 1;
  } else {
    for (int w : c[v]){
      sz[v] += dfs2(c, sz, w);
    }
  }
  return sz[v];
}
int dfs3(vector<vector<int>> &c, vector<int> &dp, vector<int> &d, vector<int> &sz, int v = 0){
  if (c[v].empty()){
    dp[v] = 1;
    return dp[v];
  }
  if (d[v] % 2 == 0){
    dp[v] = 0;
    int tmp = INF;
    for (int w : c[v]){
      dp[v] += sz[w];
      tmp = min(tmp, sz[w] - dfs3(c, dp, d, sz, w));
    }
    dp[v] -= tmp;
    return dp[v];
  } else {
    dp[v] = 1;
    for (int w : c[v]){
      dp[v] += dfs3(c, dp, d, sz, w) - 1;
    }
    return dp[v];
  }
}
int dfs4(vector<vector<int>> &c, vector<int> &dp, vector<int> &d, vector<int> &sz, int v = 0){
  if (c[v].empty()){
    dp[v] = 1;
    return dp[v];
  }
  if (d[v] % 2 == 0){
    dp[v] = 0;
    for (int w : c[v]){
      dp[v] += dfs4(c, dp, d, sz, w);
    }
    return dp[v];
  } else {
    dp[v] = INF;
    for (int w : c[v]){
      dp[v] = min(dp[v], dfs4(c, dp, d, sz, w));
    }
    return dp[v];
  }
}
int main(){
  int n;
  cin >> n;
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
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  vector<int> d(n, 0);
  dfs1(c, d);
  vector<int> sz(n, 0);
  dfs2(c, sz);
  vector<int> dp1(n);
  dfs3(c, dp1, d, sz);
  int ans1 = dp1[0];
  vector<int> dp2(n);
  dfs4(c, dp2, d, sz);
  int ans2 = dp2[0];
  cout << ans1 << ' ' << ans2 << endl;
}