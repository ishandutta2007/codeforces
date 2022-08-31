#include <bits/stdc++.h>
using namespace std;
const int LOG = 18;
struct lowest_common_ancestor{
  vector<int> d;
  vector<vector<int>> pp;
  lowest_common_ancestor(vector<int> &p, vector<int> &d): d(d){
    int N = p.size();
    pp = vector<vector<int>>(LOG, vector<int>(N, -1));
    pp[0] = p;
    for (int i = 0; i < LOG - 1; i++){
      for (int j = 0; j < N; j++){
        if (pp[i][j] != -1){
          pp[i + 1][j] = pp[i][pp[i][j]];
        }
      }
    }
  }
  int la(int v, int x){
    for (int i = 0; i < LOG; i++){
      if ((x >> i & 1) == 1){
        v = pp[i][v];
      }
    }
    return v;
  }
  int lca(int u, int v){
    if (d[u] > d[v]){
      swap(u, v);
    }
    v = la(v, d[v] - d[u]);
    if (u == v){
      return u;
    }
    for (int i = LOG - 1; i >= 0; i--){
      if (pp[i][u] != pp[i][v]){
        u = pp[i][u];
        v = pp[i][v];
      }
    }
    return pp[0][u];
  }
};
void dfs(vector<int> &in, vector<int> &out, vector<vector<int>> &c, int &cnt, int v = 0){
  in[v] = cnt;
  if (c[v].empty()){
    cnt++;
  }
  for (int w : c[v]){
    dfs(in, out, c, cnt, w);
  }
  out[v] = cnt;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> x(k);
    for (int j = 0; j < k; j++){
      cin >> x[j];
      x[j]--;
    }
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int v, u;
      cin >> v >> u;
      v--;
      u--;
      E[v].push_back(u);
      E[u].push_back(v);
    }
    vector<int> p(n, -1);
    vector<vector<int>> c(n);
    vector<int> d(n, 0);
    queue<int> Q;
    Q.push(0);
    vector<int> bfs;
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      bfs.push_back(v);
      for (int w : E[v]){
        if (w != p[v]){
          p[w] = v;
          c[v].push_back(w);
          d[w] = d[v] + 1;
          Q.push(w);
        }
      }
    }
    lowest_common_ancestor T(p, d);
    for (int j = 0; j < k; j++){
      x[j] = T.la(x[j], d[x[j]] / 2);
    }
    vector<int> in(n), out(n);
    int cnt = 0;
    dfs(in, out, c, cnt);
    vector<int> L(k), R(k);
    for (int j = 0; j < k; j++){
      L[j] = in[x[j]];
      R[j] = out[x[j]];
    }
    vector<vector<pair<int, int>>> E2(cnt + 1);
    for (int j = 0; j < k; j++){
      E2[L[j]].push_back(make_pair(1, R[j]));
    }
    for (int j = 0; j < cnt; j++){
      E2[j + 1].push_back(make_pair(0, j));
    }
    vector<int> d2(cnt + 1, -1);
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(0, 0));
    while (!dq.empty()){
      int dd = dq.front().first;
      int v = dq.front().second;
      dq.pop_front();
      if (d2[v] == -1){
        d2[v] = dd;
        for (auto e : E2[v]){
          int w = e.second;
          if (e.first == 0){
            dq.push_front(make_pair(dd, w));
          } else {
            dq.push_back(make_pair(dd + 1, w));
          }
        }
      }
    }
    cout << d2[cnt] << endl;
  }
}