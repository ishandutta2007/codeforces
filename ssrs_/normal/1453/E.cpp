#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
void dfs(vector<int> &dp, vector<vector<int>> &c, int v = 0){
  dp[v] = 0;
  if (!c[v].empty()){
    dp[v] = INF;
    for (int w : c[v]){
      dfs(dp, c, w);
      dp[v] = min(dp[v], dp[w] + 1);
    }
  }
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      E[a].push_back(b);
      E[b].push_back(a);
    }
    vector<int> p(n, -1);
    vector<vector<int>> c(n);
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E[v]){
        if (w != p[v]){
          p[w] = v;
          c[v].push_back(w);
          Q.push(w);
        }
      }
    }
    vector<int> dp(n);
    dfs(dp, c);
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (j == 0){
        ans = max(ans, dp[j]);
      } else {
        ans = max(ans, dp[j] + 1);
      }
      if (c[j].size() >= 2){
        vector<int> dpc;
        for (int k : c[j]){
          dpc.push_back(dp[k]);
        }
        sort(dpc.begin(), dpc.end(), greater<int>());
        if (j == 0){
          ans = max(ans, dpc[1] + 2);
        } else {
          ans = max(ans, dpc[0] + 2);
        }
      }
    }
    cout << ans << endl;
  }
}