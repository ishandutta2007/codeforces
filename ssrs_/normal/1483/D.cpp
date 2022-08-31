#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<tuple<int, int, int>>> E1(n);
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E1[u].push_back(make_tuple(w, i, v));
    E1[v].push_back(make_tuple(w, i, u));
  }
  int q;
  cin >> q;
  vector<vector<pair<int, int>>> E2(n);
  for (int i = 0; i < q; i++){
    int u, v, l;
    cin >> u >> v >> l;
    u--;
    v--;
    E2[u].push_back(make_pair(l, v));
    E2[v].push_back(make_pair(l, u));
  }
  vector<vector<long long>> d(n, vector<long long>(n, INF));
  for (int i = 0; i < n; i++){
    d[i][i] = 0;
    for (auto e : E1[i]){
      int w = get<2>(e);
      d[i][w] = get<0>(e);
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
      }
    }
  }
  vector<bool> useful(m, false);
  for (int u = 0; u < n; u++){
    for (int t = 0; t < n; t++){
      long long mx = -INF;
      for (auto P : E2[u]){
        int l = P.first;
        int v = P.second;
        mx = max(mx, l - d[t][v]);
      }
      for (auto e : E1[t]){
        int w = get<0>(e);
        int id = get<1>(e);
        int s = get<2>(e);
        if (d[s][u] + w <= mx){
          useful[id] = true;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++){
    if (useful[i]){
      ans++;
    }
  }
  cout << ans << endl;
}