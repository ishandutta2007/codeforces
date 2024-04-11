#include <bits/stdc++.h>
using namespace std;
const int LOG = 18;
struct lowest_common_ancestor{
  vector<int> d;
  vector<vector<int>> pp;
  lowest_common_ancestor(vector<int> &p, vector<vector<int>> &c){
    int N = p.size();
    d = vector<int>(N, 0);
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : c[v]){
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
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
  int la(int u, int x){
    for (int i = 0; i < LOG; i++){
      if ((x >> i & 1) == 1){
        u = pp[i][u];
        if (u == -1){
          return -1;
        }
      }
    }
    return u;
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
  int dist(int u, int v){
    return d[u] + d[v] - 2 * d[lca(u, v)];
  }
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int u, v;
      cin >> u >> v;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    vector<int> p(n, -1);
    vector<vector<int>> c(n);
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
          Q.push(w);
        }
      }
    }
    reverse(bfs.begin(), bfs.end());
    vector<int> dp(n, 1);
    for (int v : bfs){
      for (int w : c[v]){
        dp[v] += dp[w];
      }
    }
    lowest_common_ancestor T(p, c);
    vector<long long> cnt(n + 2, 0);
    cnt[0] = (long long) n * (n - 1) / 2;
    cnt[1] = cnt[0];
    for (int j : c[0]){
      cnt[1] -= (long long) dp[j] * (dp[j] - 1) / 2;
    }
    int p1 = 0, p2 = 0;
    for (int j = 1; j < n; j++){
      int d1 = T.dist(p1, p2);
      int d2 = T.dist(p1, j);
      int d3 = T.dist(p2, j);
      if (d1 == d2 + d3){
      } else if (d1 == d3 - d2){
        p1 = j;
      } else if (d1 == d2 - d3){
        p2 = j;
      } else {
        break;
      }
      int d = T.dist(p1, p2);
      if (T.la(p1, d) == p2){
        int v = T.la(p1, d - 1);
        cnt[j + 1] = (long long) dp[p1] * (n - dp[v]);
      } else if (T.la(p2, d) == p1){
        int v = T.la(p2, d - 1);
        cnt[j + 1] = (long long) dp[p2] * (n - dp[v]);
      } else {
        cnt[j + 1] = dp[p1] * dp[p2];
      }
    }
    for (int j = 0; j <= n; j++){
      cout << cnt[j] - cnt[j + 1];
      if (j < n){
        cout << ' ';
      }
    }
    cout << endl;
  }
}