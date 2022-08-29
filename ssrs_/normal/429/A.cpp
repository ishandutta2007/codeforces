#include <bits/stdc++.h>
using namespace std;
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
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  for (int i = 0; i < n; i++){
    int g;
    cin >> g;
    if (g == 1){
      c[i] = 1 - c[i];
    }
  }
  vector<int> p(n, -1);
  vector<int> d(n, 0);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
  }
  int cnt = 0;
  vector<int> ans;
  for (int i = 0; i < n; i++){
    if (d[i] <= 1){
      if (c[i] == 1){
        cnt++;
        ans.push_back(i);
      }
    } else {
      if (c[i] != c[p[p[i]]]){
        cnt++;
        ans.push_back(i);
      }
    }
  }
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++){
    cout << ans[i] + 1 << endl;
  }
}