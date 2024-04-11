#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> x(m), y(m), w(m);
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    cin >> x[i] >> y[i] >> w[i];
    x[i]--;
    y[i]--;
    E[x[i]].push_back(make_pair(w[i], y[i]));
    E[y[i]].push_back(make_pair(w[i], x[i]));
  }
  vector<int> a(k), b(k);
  for (int i = 0; i < k; i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vector<vector<int>> d(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, i));
    while (!pq.empty()){
      int cd = pq.top().first;
      int v = pq.top().second;
      pq.pop();
      if (d[i][v] == INF){
        d[i][v] = cd;
        for (auto P : E[v]){
          int w = P.second;
          if (d[i][w] == INF){
            pq.push(make_pair(cd + P.first, w));
          }
        }
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < m; i++){
    int sum = 0;
    for (int j = 0; j < k; j++){
      int tmp = d[a[j]][b[j]];
      tmp = min(tmp, d[a[j]][x[i]] + d[y[i]][b[j]]);
      tmp = min(tmp, d[a[j]][y[i]] + d[x[i]][b[j]]);
      sum += tmp;
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
}