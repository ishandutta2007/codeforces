#include <bits/stdc++.h>
using namespace std;
int dfs1(vector<int> &dp, vector<vector<int>> &c, int v = 0){
  dp[v] = 1;
  for (int w : c[v]){
    dp[v] += dfs1(dp, c, w);
  }
  return dp[v];
}
void dfs2(vector<int> &ans, vector<int> &dp, vector<int> &p, vector<vector<int>> &c, int v = 0){
  for (int w : c[v]){
    dfs2(ans, dp, p, c, w);
  }
  ans[v] = v;
  for (int w : c[v]){
    if (dp[w] * 2 > dp[v]){
      ans[v] = ans[w];
      while ((dp[v] - dp[ans[v]]) * 2 > dp[v]){
        ans[v] = p[ans[v]];
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> p(n, -1);
  for (int i = 1; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<vector<int>> c(n);
  for (int i = 1; i < n; i++){
    c[p[i]].push_back(i);
  }
  vector<int> dp(n, 0);
  dfs1(dp, c);
  vector<int> ans(n, -1);
  dfs2(ans, dp, p, c);
  for (int i = 0; i < q; i++){
    int v;
    cin >> v;
    cout << ans[v - 1] + 1 << "\n";
  }
}