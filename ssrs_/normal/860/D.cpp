#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vector<bool> used(n, false);
  vector<int> p(n, -1);
  vector<vector<int>> E2(n);
  for (int i = 0; i < n; i++){
    if (!used[i]){
      used[i] = true;
      queue<int> Q;
      Q.push(i);
      vector<int> bfs;
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        bfs.push_back(v);
        for (int w : E[v]){
          if (!used[w]){
            used[w] = true;
            p[w] = v;
            Q.push(w);
          }
        }
      }
      reverse(bfs.begin(), bfs.end());
      for (int v : bfs){
        for (int w : E[v]){
          if (w > v && w != p[v] && v != p[w]){
            E2[v].push_back(w);
          }
        }
      }
      for (int v : bfs){
        if (v != i){
          if (E2[v].size() % 2 == 1){
            E2[v].push_back(p[v]);
          } else {
            E2[p[v]].push_back(v);
          }
        }
      }
    }
  }
  int w = 0;
  vector<int> x, y, z;
  for (int i = 0; i < n; i++){
    int cnt = E2[i].size();
    for (int j = 0; j < cnt - 1; j += 2){
      w++;
      x.push_back(E2[i][j]);
      y.push_back(i);;
      z.push_back(E2[i][j + 1]);
    }
  }
  cout << w << endl;
  for (int i = 0; i < w; i++){
    cout << x[i] + 1 << ' ' << y[i] + 1 << ' ' << z[i] + 1 << endl;
  }
}