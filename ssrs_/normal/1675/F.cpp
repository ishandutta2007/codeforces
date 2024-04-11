#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &c, vector<int> &in, int &t, int v = 0){
  in[v] = t;
  t++;
  for (int w : c[v]){
    dfs(c, in, t, w);
  }
}
struct heavy_light_decomposition{
  vector<int> p, d, sz, in, next;
  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c, vector<int> &d): p(p), d(d){
    int N = p.size();
    sz = vector<int>(N, 0);
    dfs1(c);
    in = vector<int>(N, 0);
    next = vector<int>(N, 0);
    int t = 0;
    dfs2(c, t);
  }
  void dfs1(vector<vector<int>> &c, int v = 0){
    sz[v] = 1;
    for (int &w : c[v]){
      dfs1(c, w);
      sz[v] += sz[w];
      if (sz[w] > sz[c[v][0]]){
        swap(w, c[v][0]);
      }
    }
  }
  void dfs2(vector<vector<int>> &c, int &t, int v = 0){
    in[v] = t;
    t++;
    for (int w : c[v]){
      if (w == c[v][0]){
        next[w] = next[v];
      } else {
        next[w] = w;
      }
      dfs2(c, t, w);
    }
  }
  int lca(int u, int v){
    while (true){
      if (in[u] > in[v]){
        swap(u, v);
      }
      if (next[u] == next[v]){
        return u;
      }
      v = p[next[v]];
    }
  }
  int dist(int u, int v){
    return d[u] + d[v] - 2 * d[lca(u, v)];
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    vector<int> a(k);
    for (int j = 0; j < k; j++){
      cin >> a[j];
      a[j]--;
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
    queue<int> q;
    q.push(0);
    while (!q.empty()){
      int v = q.front();
      q.pop();
      for (int w : E[v]){
        if (w != p[v]){
          p[w] = v;
          c[v].push_back(w);
          d[w] = d[v] + 1;
          q.push(w);
        }
      }
    }
    vector<int> in(n, 0);
    int t = 0;
    dfs(c, in, t);
    heavy_light_decomposition T(p, c, d);
    vector<pair<int, int>> P(k + 2);
    for (int j = 0; j < k; j++){
      P[j] = make_pair(in[a[j]], a[j]);
    }
    P[k] = make_pair(in[x], x);
    P[k + 1] = make_pair(in[y], y);
    sort(P.begin(), P.end());
    vector<int> b(k + 2);
    for (int j = 0; j < k + 2; j++){
      b[j] = P[j].second;
    }
    int sum = 0;
    for (int j = 0; j < k + 2; j++){
      int u = b[j];
      int v = b[(j + 1) % (k + 2)];
      sum += T.dist(u, v);
    }
    sum -= T.dist(x, y);
    cout << sum << endl;
  }
}