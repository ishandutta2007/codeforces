#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    vector<int> c(n, -1);
    c[0] = 0;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E[v]){
        if (c[w] == -1){
          c[w] = 1 - c[v];
          Q.push(w);
        }
      }
    }
    vector<vector<int>> C(20);
    for (int j = 1; j <= n; j++){
      int p = 32 - __builtin_clz(j);
      C[p].push_back(j);
    }
    vector<pair<int, int>> P(20);
    for (int j = 0; j < 20; j++){
      P[j] = make_pair(C[j].size(), j);
    }
    sort(P.begin(), P.end(), greater<pair<int, int>>());
    vector<vector<int>> id(2);
    for (int j = 0; j < n; j++){
      id[c[j]].push_back(j);
    }
    vector<int> p(n);
    for (int j = 19; j >= 0; j--){
      if (id[0].size() < id[1].size()){
        swap(id[0], id[1]);
      }
      int cnt = C[j].size();
      for (int k = 0; k < cnt; k++){
        p[id[0].back()] = C[j][k];
        id[0].pop_back();
      }
    }
    for (int j = 0; j < n; j++){
      cout << p[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << "\n";
  }
}