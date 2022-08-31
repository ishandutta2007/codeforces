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
    vector<int> l(n), r(n);
    for (int j = 0; j < n; j++){
      cin >> l[j] >> r[j];
    }
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
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
    vector<long long> dp1(n, 0), dp2(n, 0);
    for (int v : bfs){
      for (int w : c[v]){
        dp1[v] += max(abs(l[w] - l[v]) + dp1[w], abs(r[w] - l[v]) + dp2[w]);
        dp2[v] += max(abs(l[w] - r[v]) + dp1[w], abs(r[w] - r[v]) + dp2[w]);
      }
    }
    cout << max(dp1[0], dp2[0]) << endl;
  }
}