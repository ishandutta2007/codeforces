#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> c(3, vector<int>(n));
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < n; j++){
      cin >> c[i][j];
    }
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
  int l = -1;
  for (int i = 0; i < n; i++){
    if (E[i].size() == 1){
      l = i;
    }
    if (E[i].size() >= 3){
      cout << -1 << endl;
      return 0;
    }
  }
  vector<int> id(n, -1);
  id[l] = 0;
  while (1){
    for (int v : E[l]){
      if (id[v] == -1){
        id[v] = id[l] + 1;
        l = v;
        break;
      }
    }
    if (id[l] == n - 1){
      break;
    }
  }
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    p[id[i]] = i;
  }
  long long ans = INF;
  vector<int> b(n);
  vector<int> q = {0, 1, 2};
  while (1){
    long long cost = 0;
    for (int i = 0; i < n; i++){
      cost += c[q[i % 3]][p[i]];
    }
    if (cost < ans){
      ans = cost;
      for (int i = 0; i < n; i++){
        b[p[i]] = q[i % 3];
      }
    }
    if (!next_permutation(q.begin(), q.end())){
      break;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++){
    cout << b[i] + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}