#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m), w(m);
    for (int j = 0; j < m; j++){
      cin >> u[j] >> v[j] >> w[j];
      u[j]--;
      v[j]--;
    }
    int ans = 0;
    for (int j = 29; j >= 0; j--){
      vector<vector<int>> E(n);
      for (int k = 0; k < m; k++){
        if (w[k] < (1 << j)){
          E[u[k]].push_back(v[k]);
          E[v[k]].push_back(u[k]);
        }
      }
      vector<bool> used(n, false);
      used[0] = true;
      queue<int> Q;
      Q.push(0);
      while (!Q.empty()){
        int x = Q.front();
        Q.pop();
        for (int y : E[x]){
          if (!used[y]){
            used[y] = true;
            Q.push(y);
          }
        }
      }
      if (used != vector<bool>(n, true)){
        ans |= 1 << j;
        for (int k = 0; k < m; k++){
          if ((w[k] >> j & 1) == 1){
            w[k] ^= 1 << j;
          }
        }
      }
    }
    cout << ans << "\n";
  }
}