#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const long long INF2 = 1000000000000000;
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
    vector<vector<int>> d(n, vector<int>(n, INF));
    for (int j = 0; j < n; j++){
      d[j][j] = 0;
    }
    for (int j = 0; j < m; j++){
      d[u[j]][v[j]] = 1;
      d[v[j]][u[j]] = 1;
    }
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        for (int l = 0; l < n; l++){
          d[k][l] = min(d[k][l], d[k][j] + d[j][l]);
        }
      }
    }
    vector<int> mn(n, INF);
    for (int j = 0; j < m; j++){
      mn[u[j]] = min(mn[u[j]], w[j]);
      mn[v[j]] = min(mn[v[j]], w[j]);
    }
    long long ans = INF2;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        ans = min(ans, (long long) (d[j][0] + d[j][n - 1] + d[j][k] + 2) * mn[k]);
      }
    }
    for (int j = 0; j < m; j++){
      ans = min(ans, (long long) (d[u[j]][0] + d[v[j]][n - 1] + 1) * w[j]);
      ans = min(ans, (long long) (d[v[j]][0] + d[u[j]][n - 1] + 1) * w[j]);
    }
    cout << ans << endl;
  }
}