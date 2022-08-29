#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &E, vector<int> &c, int v){
  if (c[v] == 1){
    vector<int> tmp;
    for (int w : E[v]){
      if (c[w] == -1){
        c[w] = 0;
        tmp.push_back(w);
      }
    }
    for (int w : tmp){
      dfs(E, c, w);
    }
  } else {
    for (int w : E[v]){
      if (c[w] == -1){
        c[w] = 1;
        dfs(E, c, w);
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> E(n);
    for (int j = 0; j < m; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    vector<int> c(n, -1);
    c[0] = 1;
    dfs(E, c, 0);
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (c[j] == -1){
        ok = false;
      }
    }
    if (!ok){
      cout << "NO" << "\n";
    } else {
      vector<int> ans;
      for (int j = 0; j < n; j++){
        if (c[j] == 1){
          ans.push_back(j);
        }
      }
      int cnt = ans.size();
      cout << "YES" << "\n";
      cout << cnt << "\n";
      for (int j = 0; j < cnt; j++){
        cout << ans[j] + 1;
        if (j < cnt - 1){
          cout << ' ';
        }
      }
      cout << "\n";
    }
  }
}