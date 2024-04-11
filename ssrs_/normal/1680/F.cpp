#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &E, vector<bool> &used, vector<int> &p, vector<int> &in, int v = 0){
  in.push_back(v);
  for (int w : E[v]){
    if (!used[w]){
      used[w] = true;
      p[w] = v;
      dfs(E, used, p, in, w);
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
    vector<bool> used(n, false);
    used[0] = true;
    vector<int> p(n, -1);
    vector<int> in;
    dfs(E, used, p, in);
    vector<int> d(n, 0);
    for (int v : in){
      if (v != 0){
        d[v] = d[p[v]] + 1;
      }
    }
    vector<int> ans;
    int cnt1 = 0;
    for (int j = 0; j < n; j++){
      for (int k : E[j]){
        if (k > j && (d[j] + d[k]) % 2 == 0){
          cnt1++;
        }
      }
    }
    if (cnt1 <= 1){
      ans.resize(n);
      for (int j = 0; j < n; j++){
        ans[j] = d[j] % 2;
      }
    } else {
      vector<int> imos0(n, 0), imos1(n, 0);
      int cnt = 0;
      for (int j = 0; j < n; j++){
        for (int k : E[j]){
          if (d[k] < d[j] - 1){
            if ((d[j] - d[k]) % 2 == 0){
              imos0[j]++;
              imos0[k]--;
              cnt++;
            } else {
              imos1[j]++;
              imos1[k]--;
            }
          }
        }
      }
      reverse(in.begin(), in.end());
      for (int v : in){
        if (v != 0){
          imos0[p[v]] += imos0[v];
          imos1[p[v]] += imos1[v];
        }
      }
      int id = -1;
      for (int j = 1; j < n; j++){
        if (imos0[j] == cnt && imos1[j] == 0){
          id = j;
        }
      }
      if (id != -1){
        ans.resize(n);
        reverse(in.begin(), in.end());
        ans[0] = 0;
        for (int v : in){
          if (v != 0){
            if (v == id){
              ans[v] = ans[p[v]];
            } else {
              ans[v] = 1 - ans[p[v]];
            }
          }
        }
      }
    }
    if (ans.empty()){
      cout << "NO" << endl;
    } else {
      bool ok = true;
      for (int j = 0; j < n; j++){
        for (int k : E[j]){
          if (ans[j] == 0 && ans[k] == 0){
            ok = false;
          }
        }
      }
      if (!ok){
        for (int j = 0; j < n; j++){
          ans[j] = 1 - ans[j];
        }
      }
      cout << "YES" << endl;
      for (int j = 0; j < n; j++){
        cout << ans[j];
      }
      cout << endl;
    }
  }
}