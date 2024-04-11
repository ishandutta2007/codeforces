#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int n, k;
  cin >> n >> k;
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
  reverse(bfs.begin(), bfs.end());
  vector<int> d(n, 0);
  for (int v : bfs){
    d[v] = 1;
    for (int &w : c[v]){
      d[v] = max(d[v], d[w] + 1);
      if (d[w] > d[c[v][0]]){
        swap(w, c[v][0]);
      }
    }
  }
  reverse(bfs.begin(), bfs.end());
  vector<int> L(n, 1);
  for (int v : bfs){
    for (int w : c[v]){
      if (w == c[v][0]){
        L[w] = L[v] + 1;
      } else {
        L[w] = 1;
      }
    }
  }
  vector<int> L2;
  for (int v : bfs){
    if (c[v].empty()){
      L2.push_back(L[v]);
    } else {
      L2.push_back(0);
    }
  }
  sort(L2.begin(), L2.end(), greater<int>());
  long long ans = -INF;
  int sum = 0;
  for (int i = 0; i <= k; i++){
    int b = min(n - sum, n / 2);
    ans = max(ans, (long long) (n - i - b) * (i - b));
    if (i < n){
      sum += L2[i];
    }
  }
  cout << ans << endl;
}