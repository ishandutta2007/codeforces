#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  long long sx, sy, fx, fy;
  cin >> sx >> sy >> fx >> fy;
  vector<long long> x(m), y(m);
  for (int i = 0; i < m; i++){
    cin >> x[i] >> y[i];
  }
  x.push_back(sx);
  y.push_back(sy);
  m++;
  vector<pair<long long, int>> X(m);
  for (int i = 0; i < m; i++){
    X[i] = make_pair(x[i], i);
  }
  sort(X.begin(), X.end());
  vector<pair<int, int>> Y(m);
  for (int i = 0; i < m; i++){
    Y[i] = make_pair(y[i], i);
  }
  sort(Y.begin(), Y.end());
  vector<vector<pair<long long, int>>> E(m);
  for (int i = 0; i < m - 1; i++){
    long long d = X[i + 1].first - X[i].first;
    int u = X[i].second;
    int v = X[i + 1].second;
    E[u].push_back(make_pair(d, v));
    E[v].push_back(make_pair(d, u));
  }
  for (int i = 0; i < m - 1; i++){
    long long d = Y[i + 1].first - Y[i].first;
    int u = Y[i].second;
    int v = Y[i + 1].second;
    E[u].push_back(make_pair(d, v));
    E[v].push_back(make_pair(d, u));
  }
  vector<long long> d(m, -1);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  pq.push(make_pair(0, m - 1));
  while (!pq.empty()){
    long long d2 = pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if (d[v] == -1){
      d[v] = d2;
      for (auto P : E[v]){
        int w = P.second;
        if (d[w] == -1){
          pq.push(make_pair(d2 + P.first, w));
        }
      }
    }
  }
  long long ans = n * 2;
  for (int i = 0; i < m; i++){
    ans = min(ans, d[i] + abs(fx - x[i]) + abs(fy - y[i]));
  }
  cout << ans << endl;
}