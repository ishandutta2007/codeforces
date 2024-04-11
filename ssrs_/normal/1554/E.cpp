#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
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
    vector<long long> a(n + 1, 0);
    a[1] = 1;
    for (int j = 0; j < n - 1; j++){
      a[1] *= 2;
      a[1] %= MOD;
    }
    for (int j = 2; j <= n; j++){
      if ((n - 1) % j == 0){
        bool ok = true;
        vector<int> dp(n, 0);
        for (int v : bfs){
          if (dp[v] % j == 0){
            if (v != 0){
              dp[p[v]]++;
            }
          } else if (dp[v] % j == j - 1){
            dp[v]++;
          } else {
            ok = false;
          }
        }
        if (ok){
          a[j] = 1;
        }
      }
    }
    vector<int> mx(n + 1, -1);
    for (int j = 2; j <= n; j++){
      if (mx[j] == -1){
        for (int k = j * 2; k <= n; k += j){
          mx[k] = j;
        }
      }
    }
    vector<int> mobius(n + 1, 1);
    for (int j = 2; j * j <= n; j++){
      for (int k = j * j; k <= n; k += j * j){
        mobius[k] = 0;
      }
    }
    for (int j = 2; j <= n; j++){
      if (mx[j] == -1){
        for (int k = j; k <= n; k += j){
          mobius[k] *= -1;
        }
      }
    }
    vector<long long> ans(n + 1, 0);
    for (int j = 1; j <= n; j++){
      for (int k = j; k <= n; k += j){
        ans[j] += a[k] * mobius[k / j];
        ans[j] += MOD;
        ans[j] %= MOD;
      }
    }
    for (int j = 1; j <= n; j++){
      cout << ans[j];
      if (j < n){
        cout << ' ';
      }
    }
    cout << endl;
  }
}