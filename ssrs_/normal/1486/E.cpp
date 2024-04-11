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
  vector<vector<long long>> d(51, vector<long long>(n, -1));
  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
  pq.push(make_tuple(0, 0, 0));
  while (!pq.empty()){
    long long dd = get<0>(pq.top());
    int v = get<1>(pq.top());
    int p = get<2>(pq.top());
    pq.pop();
    if (d[p][v] == -1){
      d[p][v] = dd;
      for (auto P : E[v]){
        int c = P.first;
        int w = P.second;
        int p2;
        if (p == 0){
          p2 = c;
        } else {
          p2 = 0;
        }
        if (d[p2][w] == -1){
          pq.push(make_tuple(dd + c * c + p * c * 2, w, p2));
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << d[0][i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}