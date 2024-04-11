#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> pr(n, -1);
  vector<vector<int>> ch(n);
  queue<int> Q;
  Q.push(0);
  vector<int> bfs;
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    bfs.push_back(v);
    for (int w : E[v]){
      if (w != pr[v]){
        pr[w] = v;
        ch[v].push_back(w);
        Q.push(w);
      }
    }
  }
  reverse(bfs.begin(), bfs.end());
  vector<int> dp(n, 0);
  for (int v : bfs){
    dp[v] = c[v];
    for (int w : ch[v]){
      dp[v] += dp[w];
    }
  }
  vector<vector<int>> E2(n);
  for (int i = 1; i < n; i++){
    if (dp[i] >= 2){
      E2[i].push_back(pr[i]);
    }
    if (dp[0] - dp[i] >= 2){
      E2[pr[i]].push_back(i);
    }
  }
  vector<bool> used(n, false);
  queue<int> Q2;
  for (int i = 0; i < n; i++){
    if (c[i] == 1){
      if (!used[i]){
        used[i] = true;
        Q2.push(i);
      }
      for (int j : E[i]){
        if (!used[j]){
          used[j] = true;
          Q2.push(j);
        }
      }
    }
  }
  while (!Q2.empty()){
    int v = Q2.front();
    Q2.pop();
    for (int w : E2[v]){
      if (!used[w]){
        used[w] = true;
        Q2.push(w);
      }
    }
  }
  for (int i = 0; i < n; i++){
    if (used[i]){
      cout << 1;
    } else {
      cout << 0;
    }
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}