#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> d(n);
  for (int i = 0; i < n; i++){
    d[i] = E[i].size();
  }
  int r = max_element(d.begin(), d.end()) - d.begin();
  vector<bool> used(n, false);
  used[r] = true;
  queue<int> Q;
  Q.push(r);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (!used[w]){
        cout << v + 1 << ' ' << w + 1 << endl;
        used[w] = true;
        Q.push(w);
      }
    }
  }
}