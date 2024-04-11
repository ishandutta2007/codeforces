#include <bits/stdc++.h>
using namespace std;
int dfs1(vector<int> &dp, vector<vector<int>> &c, int v = 0){
  dp[v] = 1;
  for (int w : c[v]){
    dp[v] += dfs1(dp, c, w);
  }
  return dp[v];
}
void dfs2(vector<int> &pr, vector<vector<int>> &c, int v = 0){
  pr.push_back(v);
  for (int w : c[v]){
    dfs2(pr, c, w);
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  for (int i = 1; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<vector<int>> c(n);
  for (int i = 1; i < n; i++){
    c[p[i]].push_back(i);
  }
  for (int i = 0; i < n; i++){
    sort(c[i].begin(), c[i].end());
  }
  vector<int> dp(n);
  dfs1(dp, c);
  vector<vector<int>> S(n);
  for (int i = 0; i < n; i++){
    int cnt = c[i].size();
    S[i] = vector<int>(cnt + 1);
    S[i][0] = 0;
    for (int j = 0; j < cnt; j++){
      S[i][j + 1] = S[i][j] + dp[c[i][j]];
    }
  }
  vector<int> pr;
  dfs2(pr, c);
  vector<int> t(n);
  for (int i = 0; i < n; i++){
    t[pr[i]] = i;
  }
  for (int i = 0; i < q; i++){
    int u, k;
    cin >> u >> k;
    u--;
    if (dp[u] < k){
      cout << -1 << endl;
    } else {
      cout << pr[t[u] + k - 1] + 1 << endl;
    }
  }
}