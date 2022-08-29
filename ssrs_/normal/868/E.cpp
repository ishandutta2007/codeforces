#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E[u].push_back(make_pair(w, v));
    E[v].push_back(make_pair(w, u));
  }
  int s;
  cin >> s;
  s--;
  int m;
  cin >> m;
  vector<int> x(m);
  for (int i = 0; i < m; i++){
    cin >> x[i];
    x[i]--;
  }
  vector<vector<int>> p(n, vector<int>(n, -1));
  vector<vector<int>> d(n, vector<int>(n, 0));
  vector<vector<int>> bfs(n);
  vector<vector<vector<int>>> c(n, vector<vector<int>>(n));
  for (int i = 0; i < n; i++){
    queue<int> Q;
    Q.push(i);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      bfs[i].push_back(v);
      for (auto P : E[v]){
        int w = P.second;
        if (w != p[i][v]){
          p[i][w] = v;
          c[i][v].push_back(w);
          d[i][w] = d[i][v] + P.first;
          Q.push(w);
        }
      }
    }
    reverse(bfs[i].begin(), bfs[i].end());
  }
  vector<vector<int>> dp(m + 1, vector<int>(n, INF));
  for (int i = 0; i < n; i++){
    dp[0][i] = 0;
  }
  for (int i = 1; i <= m; i++){
    for (int j = 0; j < n; j++){
      if (E[j].size() == 1){
        int tv = INF, fv = 0;
        while (tv - fv > 1){
          int mid = (tv + fv) / 2;
          vector<int> dp2(n, 0);
          for (int v : bfs[j]){
            if (c[j][v].empty()){
              if (mid < d[j][v]){
                dp2[v] = INF;
              } else {
                for (int k = 0; k < i; k++){
                  if (d[j][v] + dp[k][v] > mid){
                    dp2[v] = i - k;
                    break;
                  }
                }      
              }
            } else {
              for (int w : c[j][v]){
                dp2[v] += dp2[w];
              }
            }
          }
          if (dp2[j] < i){
            tv = mid;
          } else {
            fv = mid;
          }
        }
        dp[i][j] = tv;
      }
    }
  }
  vector<int> X(n, 0);
  for (int i = 0; i < m; i++){
    X[x[i]]++;
  }
  for (int v : bfs[s]){
    for (int w : c[s][v]){
      X[v] += X[w];
    }
  }
  int tv = INF, fv = 0;
  while (tv - fv > 1){
    int mid = (tv + fv) / 2;
    vector<int> dp2(n, 0);
    for (int v : bfs[s]){
      if (c[s][v].empty()){
        if (mid < d[s][v]){
          dp2[v] = INF;
        } else {
          for (int i = 0; i < m; i++){
            if (d[s][v] + dp[i][v] > mid){
              dp2[v] = m - i;
              break;
            }
          }
        }
      } else {
        for (int w : c[s][v]){
          if (v == s){
            dp2[w] = min(dp2[w], X[w]);
          }
          dp2[v] += dp2[w];
        }
      }
    }
    if (dp2[s] < m){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}