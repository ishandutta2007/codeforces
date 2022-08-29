#include <bits/stdc++.h>
using namespace std;
const long long INF = 200000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
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
        Q.push(w);
      }
    }
  }
  vector<long long> C(n);
  C[0] = 1;
  for (int v : bfs){
    for (int w : c[v]){
      C[w] = min(C[v] * (int) c[v].size(), INF);
    }
  }
  long long L = 1;
  for (int i = 0; i < n; i++){
    L = lcm(L, C[i]);
    L = min(L, INF);
  }
  int m;
  if (L == INF){
    m = 0;
  } else {
    m = INF;
    for (int i = 0; i < n; i++){
      if (c[i].empty()){
        m = min(m, a[i] / (int) (L / C[i]));
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++){
    if (a[i] > 0){
      ans += a[i];
      ans -= (L / C[i]) * m;
    }
  }
  cout << ans << endl;
}