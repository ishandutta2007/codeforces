#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
void dfs(vector<int> &ans, vector<vector<int>> &c, vector<bool> &path, vector<bool> &use, int v = 0){
  ans.push_back(v);
  for (int w : c[v]){
    if (use[w] && !path[w]){
      dfs(ans, c, path, use, w);
      ans.push_back(v);
    }
  }
  for (int w : c[v]){
    if (path[w]){
      dfs(ans, c, path, use, w);
    }
  }
}
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n, k;
    cin >> n >> k;
    vector<int> p(n, -1);
    for (int j = 1; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    vector<vector<int>> c(n);
    for (int j = 1; j < n; j++){
      c[p[j]].push_back(j);
    }
    vector<int> d(n);
    d[0] = 0;
    for (int j = 1; j < n; j++){
      d[j] = d[p[j]] + 1;
    }
    int t = 0;
    for (int j = 0; j < n; j++){
      if (d[j] <= k - 1 && d[j] > d[t]){
        t = j;
      }
    }
    vector<bool> path(n, false);
    for (int v = t; v != 0; v = p[v]){
      path[v] = true;
    }
    path[0] = true;
    vector<bool> use = path;
    int cnt = k - d[t] - 1;
    for (int j = 1; j < n; j++){
      if (!path[j] && cnt > 0){
        cnt--;
        use[j] = true;
      }
    }
    vector<int> ans;
    dfs(ans, c, path, use);
    int l = ans.size() - 1;
    cout << l << endl;
    for (int j = 0; j <= l; j++){
      cout << ans[j] + 1;
      if (j < l){
        cout << ' ';
      }
    }
    cout << endl;
  }
}