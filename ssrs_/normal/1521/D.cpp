#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
void dfs(vector<int> &p2, vector<vector<int>> &c, vector<int> &dp1, vector<int> &dp2, vector<int> &r1, vector<pair<int, int>> &r2, int v, int t){
  int a;
  if (t == 1){
    a = 1;
  } else {
    if (dp1[v] <= dp2[v]){
      a = 1;
    } else {
      a = 2;
    }
  }
  if (a == 1){
    if (r1[v] != -1){
      p2[r1[v]] = v;
    }
    for (int w : c[v]){
      if (w == r1[v]){
        dfs(p2, c, dp1, dp2, r1, r2, w, 1);
      } else {
        dfs(p2, c, dp1, dp2, r1, r2, w, 0);
      }
    }
  }
  if (a == 2){
    p2[r2[v].first] = v;
    p2[r2[v].second] = v;
    for (int w : c[v]){
      if (w == r2[v].first || w == r2[v].second){
        dfs(p2, c, dp1, dp2, r1, r2, w, 1);
      } else {
        dfs(p2, c, dp1, dp2, r1, r2, w, 0);
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
    vector<int> bfs;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      bfs.push_back(v);
      for (int w : E[v]){
        if (w != p[v]){
          p[w] = v;
          c[v].push_back(w);
          Q.push(w);
        }
      }
    }
    vector<int> dp1(n), dp2(n);
    vector<int> r1(n);
    vector<pair<int, int>> r2(n);
    reverse(bfs.begin(), bfs.end());
    for (int v : bfs){
      int d = c[v].size();
      vector<vector<int>> dp3(d + 1, vector<int>(3, INF));
      vector<vector<pair<int, int>>> r(d + 1, vector<pair<int, int>>(3));
      dp3[0][0] = 0;
      r[0][0] = make_pair(-1, -1);
      for (int j = 0; j < d; j++){
        int w = c[v][j];
        for (int k = 0; k < 3; k++){
          if (dp3[j + 1][k] > dp3[j][k] + dp2[w]){
            dp3[j + 1][k] = dp3[j][k] + dp2[w];
            r[j + 1][k] = r[j][k];
          }
          int k2 = min(k + 1, 2);
          if (dp3[j + 1][k2] > dp3[j][k] + dp1[w]){
            dp3[j + 1][k2] = dp3[j][k] + dp1[w];
            r[j + 1][k2] = r[j][k];
            if (k == 0){
              r[j + 1][k2].first = w;
            }
            if (k == 1){
              r[j + 1][k2].second = w;
            }
          }
        }
      }
      pair<int, int> P1 = min(make_pair(dp3[d][0] + 1, r[d][0].first), make_pair(dp3[d][1], r[d][1].first));
      dp1[v] = P1.first;
      r1[v] = P1.second;
      pair<int, pair<int, int>> P2 = min({make_pair(dp3[d][0] + 1, r[d][0]), make_pair(dp3[d][1], r[d][1]), make_pair(dp3[d][2] - 1, r[d][2])});
      dp2[v] = P2.first;
      r2[v] = P2.second;
    }
    vector<int> p2(n, -1);
    dfs(p2, c, dp1, dp2, r1, r2, 0, 0);
    int cnt = 0;
    for (int j = 1; j < n; j++){
      if (p2[j] == -1){
        cnt++;
      }
    }
    vector<vector<int>> E2(n);
    for (int j = 1; j < n; j++){
      if (p2[j] != -1){
        E2[j].push_back(p2[j]);
        E2[p2[j]].push_back(j);
      }
    }
    vector<bool> used(n, false);
    vector<int> leaf;
    for (int j = 0; j < n; j++){
      if (!used[j]){
        used[j] = true;
        queue<int> Q;
        Q.push(j);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          if (E2[v].empty()){
            leaf.push_back(v);
            leaf.push_back(v);
          }
          if (E2[v].size() == 1){
            leaf.push_back(v);
          }
          for (int w : E2[v]){
            if (!used[w]){
              used[w] = true;
              Q.push(w);
            }
          }
        }
      }
    }
    vector<pair<int, int>> sub, add;
    for (int j = 1; j < n; j++){
      if (p2[j] == -1){
        sub.push_back(make_pair(j, p[j]));
      }
    }
    for (int j = 0; j < cnt; j++){
      add.push_back(make_pair(leaf[j * 2 + 1], leaf[j * 2 + 2]));
    }
    cout << cnt << "\n";
    for (int j = 0; j < cnt; j++){
      cout << sub[j].first + 1 << ' ' << sub[j].second + 1 << ' ' << add[j].first + 1 << ' ' << add[j].second + 1 << "\n";
    }
  }
}