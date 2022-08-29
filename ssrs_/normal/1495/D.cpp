#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int INF = 100000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vector<vector<int>> d(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++){
    d[i][i] = 0;
    for (int j : E[i]){
      d[i][j] = 1;
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
      }
    }
  }
  vector<vector<long long>> ans(n, vector<long long>(n, 1));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i != j){
        int cnt = 0;
        for (int k : E[j]){
          if (d[i][k] == d[i][j] - 1){
            cnt++;
          }
        }
        ans[i][i] *= cnt;
        ans[i][i] %= MOD;
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      int D = d[i][j];
      vector<int> p(n), r(n);
      for (int k = 0; k < n; k++){
        p[k] = (d[i][k] - d[j][k] + d[i][j]) / 2;
        r[k] = (d[i][k] + d[j][k] - d[i][j]) / 2;
      }
      vector<int> cnt(D + 1, 0);
      for (int k = 0; k < n; k++){
        if  (r[k] == 0){
          cnt[p[k]]++;
        }
      }
      for (int k = 0; k <= D; k++){
        if (cnt[k] != 1){
          ans[i][j] = 0;
        }
      }
      if (ans[i][j] == 1){
        for (int k = 0; k < n; k++){
          if (r[k] != 0){
            int cnt = 0;
            for (int l : E[k]){
              if (p[k] == p[l] && r[l] == r[k] - 1){
                cnt++;
              }
            }
            ans[i][j] *= cnt;
            ans[i][j] %= MOD;
          }
        }
      }
      ans[j][i] = ans[i][j];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << ans[i][j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}