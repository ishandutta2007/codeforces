#include <bits/stdc++.h>
using namespace std;
int main(){
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
    vector<vector<int>> d(n, vector<int>(n, -1));
    for (int j = 0; j < n; j++){
      queue<int> Q;
      Q.push(j);
      d[j][j] = 0;
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (d[j][w] == -1){
            d[j][w] = d[j][v] + 1;
            Q.push(w);
          }
        }
      }
    }
    vector<int> mn_x(n + 1, 0);
    for (int j = 0; j <= n; j++){
      vector<int> id;
      for (int k = 0; k < n; k++){
        if (d[0][k] > j){
          id.push_back(k);
        }
      }
      if (id.empty()){
        mn_x[j] = n;
      } else {
        int cnt = id.size();
        int s = id[0];
        int s2 = id[0];
        for (int k = 1; k < cnt; k++){
          if (d[s][s2] < d[s][id[k]]){
            s2 = id[k];
          }
        }
        int s3 = id[0];
        for (int k = 1; k < cnt; k++){
          if (d[s2][s3] < d[s2][id[k]]){
            s3 = id[k];
          }
        }
        int D = d[s2][s3];
        int r = (D + 1) / 2;
        if (r <= j){
          mn_x[j] = j - r;
        }
      }
    }
    vector<int> ans(n);
    for (int j = 0; j < n; j++){
      for (int k = mn_x[j]; k < mn_x[j + 1]; k++){
        ans[k] = j + 1;
      }
    }
    for (int j = 0; j < n; j++){
      cout << ans[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}