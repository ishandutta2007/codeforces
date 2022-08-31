#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E[u].push_back(make_pair(w, v));
    E[v].push_back(make_pair(w, u));
  }
  vector<vector<long long>> d(n, vector<long long>(4, -1));
  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
  pq.push(make_tuple(0, 0, 0));
  while (!pq.empty()){
    long long dd = get<0>(pq.top());
    int v = get<1>(pq.top());
    int s = get<2>(pq.top());
    pq.pop();
    if (d[v][s] == -1){
      d[v][s] = dd;
      for (auto P : E[v]){
        int c = P.first;
        int w = P.second;
        if (d[w][s] == -1){
          pq.push(make_tuple(dd + c, w, s));
        }
        if (s == 0 || s == 2){
          if (d[w][s + 1] == -1){
            pq.push(make_tuple(dd, w, s + 1));
          }
        }
        if (s == 0 || s == 1){
          if (d[w][s + 2] == -1){
            pq.push(make_tuple(dd + c * 2, w, s + 2));
          }
        }
        if (s == 0){
          if (d[w][s + 3] == -1){
            pq.push(make_tuple(dd + c, w, s + 3));
          }
        }
      }
    }
  }
  for (int i = 1; i < n; i++){
    cout << d[i][3];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}