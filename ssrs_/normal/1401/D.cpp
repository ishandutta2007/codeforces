#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int dfs(vector<int> &dp, vector<vector<int>> &c, int v = 0){
  dp[v] = 1;
  for (int w : c[v]){
    dp[v] += dfs(dp, c, w);
  }
  return dp[v];
}
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
    int m;
    cin >> m;
    vector<int> p(m);
    for (int j = 0; j < m; j++){
      cin >> p[j];
    }
    vector<int> pr(n, -1);
    vector<vector<int>> c(n);
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E[v]){
        if (pr[v] != w){
          pr[w] = v;
          c[v].push_back(w);
          Q.push(w);
        }
      }
    }
    vector<int> dp(n, 0);
    dfs(dp, c);
    vector<long long> cnt(n);
    for (int j = 1; j < n; j++){
      cnt[j] = (long long) dp[j] * (n - dp[j]);
    }
    cnt[0] = 0;
    sort(cnt.rbegin(), cnt.rend());
    vector<long long> L(n - 1, 1);
    if (m < n - 1){
      sort(p.rbegin(), p.rend());
      for (int j = 0; j < m; j++){
        L[j] = p[j];
      }
    } else {
      sort(p.begin(), p.end());
      for (int j = 0; j < n - 1; j++){
        L[n - 2 - j] = p[j];
      }
      for (int j = n - 1; j < m; j++){
        L[0] *= p[j];
        L[0] %= MOD;
      }
    }
    long long ans = 0;
    for (int j = 0; j < n - 1; j++){
      ans += cnt[j] * L[j] % MOD;
      ans %= MOD;
    }
    cout << ans << endl;
  }
}