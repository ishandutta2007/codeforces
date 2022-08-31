#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int v;
      cin >> v;
      v--;
      E[j + 1].push_back(v);
      E[v].push_back(j + 1);
    }
    vector<long long> a(n);
    for (int j = 1; j < n; j++){
      cin >> a[j];
    }
    vector<int> p(n, -1);
    vector<vector<int>> c(n);
    vector<int> d(n, 0);
    int D = 0;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E[v]){
        if (w != p[v]){
          p[w] = v;
          c[v].push_back(w);
          d[w] = d[v] + 1;
          D = max(D, d[w]);
          Q.push(w);
        }
      }
    }
    vector<vector<int>> g(D + 1);
    for (int j = 0; j < n; j++){
      g[d[j]].push_back(j);
    }
    vector<long long> dp(n, 0);
    for (int j = 0; j < D; j++){
      long long ap_max = 0, ap_min = INF;
      for (int w : g[j + 1]){
        ap_max = max(ap_max, a[w]);
        ap_min = min(ap_min, a[w]);
      }
      for (int v : g[j]){
        for (int w : c[v]){
          dp[w] = max(dp[w], dp[v] + a[w] - ap_min);
          dp[w] = max(dp[w], dp[v] + ap_max - a[w]);
        }
      }
      long long add_max = -INF, sub_max = -INF;
      for (int v : g[j]){
        for (int w : c[v]){
          add_max = max(add_max, dp[v] + a[w]);
          sub_max = max(sub_max, dp[v] - a[w]);
        }
      }
      for (int w : g[j + 1]){
        dp[w] = max(dp[w], add_max - a[w]);
        dp[w] = max(dp[w], sub_max + a[w]);
      }
    }
    long long ans = 0;
    for (int j = 0; j < n; j++){
      ans = max(ans, dp[j]);
    }
    cout << ans << "\n";
  }
}