#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
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
    vector<int> dp(n, 1);
    vector<bool> used(n, false);
    queue<int> Q;
    for (int j = 0; j < n; j++){
      if (d[j] <= 1){
        used[j] = true;
        Q.push(j);
      }
    }
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E[v]){
        if (!used[w]){
          d[w]--;
          dp[w] = max(dp[w], dp[v] + 1);
          if (d[w] == 1){
            used[w] = true;
            Q.push(w);
          }
        }
      }
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (dp[j] > k){
        ans++;
      }
    }
    cout << ans << endl;
  }
}