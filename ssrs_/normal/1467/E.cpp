#include <bits/stdc++.h>
using namespace std;
const int LOG = 20;
struct lowest_common_ancestor{
  vector<int> d;
  vector<vector<int>> pp;
  lowest_common_ancestor(vector<int> p, vector<vector<int>> c){
    int N = p.size();
    d = vector<int>(N, 0);
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : c[v]){
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
    pp = vector<vector<int>>(LOG, vector<int>(N, -1));
    for (int i = 0; i < N; i++){
      pp[0][i] = p[i];
    }
    for (int i = 1; i < LOG; i++){
      for (int j = 0; j < N; j++){
        if (pp[i - 1][j] != -1){
          pp[i][j] = pp[i - 1][pp[i - 1][j]];
        }
      }
    }
  }
  int la(int u, int x){
    for (int i = 0; i < LOG; i++){
      if (x >> i & 1){
        u = pp[i][u];
      }
    }
    return u;
  }
  int lca(int u, int v){
    if (d[u] > d[v]){
      swap(u, v);
    }
    v = la(v, d[v] - d[u]);
    if (u == v){
      return v;
    }
    for (int i = LOG - 1; i >= 0; i--){
      if (pp[i][u] != pp[i][v]){
        u = pp[i][u];
        v = pp[i][v];
      }
    }
    return pp[0][u];
  }
};
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
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
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  queue<int> Q;
  Q.push(0);
  vector<int> b;
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    b.push_back(v);
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  lowest_common_ancestor T(p, c);
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++){
    mp[a[i]].push_back(i);
  }
  vector<int> imos(n, 0);
  for (auto P : mp){
    int M = P.second.size();
    if (M != 1){
      for (int i = 0; i < M; i++){
        int u = P.second[i];
        int v = P.second[(i + 1) % M];
        int w = T.lca(u, v);
        if (w == u){
          int x = T.la(v, T.d[v] - T.d[u] - 1);
          imos[v]++;
          imos[0]++;
          imos[x]--;
        } else if (w == v){
          int x = T.la(u, T.d[u] - T.d[v] - 1);
          imos[u]++;
          imos[0]++;
          imos[x]--;
        } else {
          imos[u]++;
          imos[v]++;
        }
      }
    }
  }
  for (int v : b){
    for (int w : c[v]){
      imos[w] += imos[v];
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (imos[i] == 0){
      cnt++;
    }
  }
  cout << cnt << endl;
}