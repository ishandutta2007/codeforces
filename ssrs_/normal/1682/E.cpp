#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<int> x(m), y(m);
  for (int i = 0; i < m; i++){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  vector<int> c(n, -1);
  vector<vector<int>> id;
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (c[i] == -1){
      c[i] = cnt;
      int v = i;
      id.push_back(vector<int>(0));
      while (true){
        id.back().push_back(v);
        v = p[v];
        if (c[v] != -1){
          break;
        }
        c[v] = cnt;
      }
      cnt++;
    }
  }
  vector<int> sz(cnt);
  for (int i = 0; i < cnt; i++){
    sz[i] = id[i].size();
  }
  vector<int> pos(n);
  for (int i = 0; i < cnt; i++){
    for (int j = 0; j < sz[i]; j++){
      pos[id[i][j]] = j;
    }
  }
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    E[x[i]].push_back(make_pair(i, y[i]));
    E[y[i]].push_back(make_pair(i, x[i]));
  }
  vector<vector<int>> E2(m);
  for (int i = 0; i < n; i++){
    int d = E[i].size();
    vector<pair<int, int>> P(d);
    for (int j = 0; j < d; j++){
      P[j] = make_pair((pos[E[i][j].second] - pos[i] + sz[c[i]]) % sz[c[i]], E[i][j].first);
    }
    sort(P.begin(), P.end());
    for (int j = 0; j < d - 1; j++){
      E2[P[j].second].push_back(P[j + 1].second);
    }
  }
  vector<int> in(m, 0);
  for (int i = 0; i < m; i++){
    for (int j : E2[i]){
      in[j]++;
    }
  }
  queue<int> Q;
  for (int i = 0; i < m; i++){
    if (in[i] == 0){
      Q.push(i);
    }
  }
  vector<int> ans;
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    ans.push_back(v);
    for (int w : E2[v]){
      in[w]--;
      if (in[w] == 0){
        Q.push(w);
      }
    }
  }
  for (int i = 0; i < m; i++){
    cout << ans[i] + 1;
    if (i < m - 1){
      cout << ' ';
    }
  }
  cout << endl;
}