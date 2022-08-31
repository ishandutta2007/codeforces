#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  int V = n * m;
  vector<vector<int>> E1(V);
  for (int i = 0; i < n; i++){
    map<int, vector<int>> mp;
    for (int j = 0; j < m; j++){
      mp[a[i][j]].push_back(j);
    }
    for (auto P : mp){
      vector<int> id = P.second;
      int cnt = id.size();
      for (int j = 0; j < cnt - 1; j++){
        int v = i * m + id[j];
        int w = i * m + id[j + 1];
        E1[v].push_back(w);
        E1[w].push_back(v);
      }
    }
  }
  for (int i = 0; i < m; i++){
    map<int, vector<int>> mp;
    for (int j = 0; j < n; j++){
      mp[a[j][i]].push_back(j);
    }
    for (auto P : mp){
      vector<int> id = P.second;
      int cnt = id.size();
      for (int j = 0; j < cnt - 1; j++){
        int v = id[j] * m + i;
        int w = id[j + 1] * m + i;
        E1[v].push_back(w);
        E1[w].push_back(v);
      }
    }
  }
  vector<int> c(V, -1);
  int cnt = 0;
  for (int i = 0; i < V; i++){
    if (c[i] == -1){
      c[i] = cnt;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E1[v]){
          if (c[w] == -1){
            c[w] = c[v];
            Q.push(w);
          }
        }
      }
      cnt++;
    }
  }
  vector<vector<int>> E2(cnt);
  for (int i = 0; i < n; i++){
    vector<pair<int, int>> P;
    for (int j = 0; j < m; j++){
      P.push_back(make_pair(a[i][j], c[i * m + j]));
    }
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    int sz = P.size();
    for (int j = 0; j < sz - 1; j++){
      int v = P[j].second;
      int w = P[j + 1].second;
      E2[v].push_back(w);
    }
  }
  for (int i = 0; i < m; i++){
    vector<pair<int, int>> P;
    for (int j = 0; j < n; j++){
      P.push_back(make_pair(a[j][i], c[j * m + i]));
    }
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    int sz = P.size();
    for (int j = 0; j < sz - 1; j++){
      int v = P[j].second;
      int w = P[j + 1].second;
      E2[v].push_back(w);
    }
  }
  vector<int> deg(cnt, 0);
  for (int i = 0; i < cnt; i++){
    for (int j : E2[i]){
      deg[j]++;
    }
  }
  vector<int> dp(cnt, -1);
  queue<int> Q;
  for (int i = 0; i < cnt; i++){
    if (deg[i] == 0){
      Q.push(i);
      dp[i] = 1;
    }
  }
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E2[v]){
      deg[w]--;
      if (deg[w] == 0){
        Q.push(w);
        dp[w] = dp[v] + 1;
      }
    }
  }
  vector<vector<int>> ans(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      ans[i][j] = dp[c[i * m + j]];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << ans[i][j];
      if (j < m - 1){
        cout << ' ';
      }
    }
    cout << "\n";
  }
}