#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> x(k);
    for (int j = 0; j < k; j++){
      cin >> x[j];
      x[j]--;
    }
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int v, u;
      cin >> v >> u;
      v--;
      u--;
      E[v].push_back(u);
      E[u].push_back(v);
    }
    vector<int> p(n, -1);
    vector<vector<int>> c(n);
    vector<int> d(n, 0);
    queue<int> Q;
    Q.push(0);
    vector<int> bfs;
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      bfs.push_back(v);
      for (int w : E[v]){
        if (w != p[v]){
          p[w] = v;
          c[v].push_back(w);
          d[w] = d[v] + 1;
          Q.push(w);
        }
      }
    }
    vector<int> d2(n, -1);
    queue<int> Q2;
    for (int j = 0; j < k; j++){
      d2[x[j]] = 0;
      Q2.push(x[j]);
    }
    while (!Q2.empty()){
      int v = Q2.front();
      Q2.pop();
      for (int w : E[v]){
        if (d2[w] == -1){
          d2[w] = d2[v] + 1;
          Q2.push(w);
        }
      }
    }
    vector<bool> dp(n, false);
    for (int j = 0; j < n; j++){
      if (c[j].empty()){
        if (d2[j] > d[j]){
          dp[j] = true;
        }
      }
    }
    reverse(bfs.begin(), bfs.end());
    for (int v : bfs){
      if (d2[v] > d[v]){
        for (int w : c[v]){
          if (dp[w]){
            dp[v] = true;
          }
        }
      }
    }
    if (dp[0]){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}