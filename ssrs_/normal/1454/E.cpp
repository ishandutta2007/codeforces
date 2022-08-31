#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> E(n);
    for (int j = 0; j < n; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    vector<int> d(n);
    for (int j = 0; j < n; j++){
      d[j] = E[j].size();
    }
    vector<int> c(n, 1);
    queue<int> Q;
    for (int j = 0; j < n; j++){
      if (d[j] == 1){
        Q.push(j);
      }
    }
    int cnt = n;
    while (!Q.empty()){
      int v = Q.front();
      cnt--;
      Q.pop();
      for (int w : E[v]){
        if (d[w] != 1){
          d[w]--;
          if (d[w] == 1){
            Q.push(w);
          }
          c[w] += c[v];
        }
      }
    }
    long long ans = (long long) n * (n - 1);
    for (int j = 0; j < n; j++){
      if (d[j] == 2){
        ans -= (long long) c[j] * (c[j] - 1) / 2;
      }
    }
    cout << ans << endl;
  }
}