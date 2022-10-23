#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<vector<int>> &E, int S){
  int N = E.size();
  vector<int> d(N, -1);
  d[S] = 0;
  queue<int> Q;
  Q.push(S);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (d[w] == -1){
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
  }
  return d;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> E(n);
    for (int j = 0; j < m; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    int f;
    cin >> f;
    vector<int> h(f);
    for (int j = 0; j < f; j++){
      cin >> h[j];
      h[j]--;
    }
    int k;
    cin >> k;
    vector<int> p(k);
    for (int j = 0; j < k; j++){
      cin >> p[j];
      p[j]--;
    }
    vector<int> d = bfs(E, 0);
    vector<pair<int, int>> P(k);
    for (int j = 0; j < k; j++){
      P[j] = make_pair(d[h[p[j]]], p[j]);
    }
    sort(P.begin(), P.end());
    vector<int> pos(k);
    for (int j = 0; j < k; j++){
      pos[j] = P[j].second;
    }
    vector<int> p2(k);
    for (int j = 0; j < k; j++){
      p2[j] = h[pos[j]];
    }
    vector<vector<int>> d2(k, vector<int>(n, -1));
    for (int j = 0; j < k; j++){
      d2[j] = bfs(E, p2[j]);
    }
    vector<bool> dp(1 << k, false);
    dp[0] = true;
    for (int j = 0; j < k; j++){
      dp[1 << j] = true;
    }
    for (int j = 1; j < k; j++){
      for (int l = 1; l < (1 << j); l++){
        if (dp[l]){
          int pr = 31 - __builtin_clz(l);
          if (d[p2[pr]] + d2[pr][p2[j]] == d[p2[j]]){
            dp[l | (1 << j)] = true;
          }
        }
      }
    }
    vector<bool> c(f, true);
    for (int j = 0; j < k; j++){
      c[p[j]] = false;
    }
    vector<bool> dp2(1 << k, false);
    dp2[0] = true;
    for (int j = 0; j < f; j++){
      if (c[j]){
        vector<bool> ok(1 << k, false);
        ok[0] = true;
        for (int l = 1; l < (1 << k); l++){
          if (dp[l]){
            int pr = 31 - __builtin_clz(l);
            if (d[p2[pr]] + d2[pr][h[j]] == d[h[j]]){
              ok[l] = true;
            }
          }
        }
        for (int x = (1 << k) - 1; x >= 0; x--){
          if (dp2[x]){
            for (int y = 0; y < (1 << k); y++){
              if (ok[y]){
                dp2[x | y] = true;
              }
            }
          }
        }       
      }
    }
    int ans = k;
    for (int j = 0; j < (1 << k); j++){
      if (dp2[j]){
        ans = min(ans, k - __builtin_popcount(j));
      }
    }
    cout << ans << endl;
  }
}