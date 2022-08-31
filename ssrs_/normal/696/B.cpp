#include <bits/stdc++.h>
using namespace std;
int dfs1(vector<int> &sz, vector<vector<int>> &c, int v = 0){
  sz[v] = 1;
  for (int w : c[v]){
    sz[v] += dfs1(sz, c, w);
  }
  return sz[v];
}
void dfs2(vector<double> &dp, vector<int> &sz, vector<vector<int>> &c, int v = 0){
  int deg = c[v].size();
  vector<int> a(deg);
  for (int i = 0; i < deg; i++){
    a[i] = sz[c[v][i]];
  }
  int sum = 0;
  for (int i = 0; i < deg; i++){
    sum += a[i];
  }
  for (int i = 0; i < deg; i++){
    dp[c[v][i]] = dp[v] + (double) (sum - a[i]) / 2 + 1;
    dfs2(dp, sz, c, c[v][i]);
  }
  return;
}
int main(){
  cout << fixed << setprecision(1);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 1; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<vector<int>> c(n);
  for (int i = 1; i < n; i++){
    c[p[i]].push_back(i);
  }
  vector<int> sz(n);
  dfs1(sz, c);
  vector<double> dp(n);
  dp[0] = 1;
  dfs2(dp, sz, c);
  for (int i = 0; i < n; i++){
    cout << dp[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}