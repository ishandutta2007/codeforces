#include <bits/stdc++.h>
using namespace std;
struct unionfind{
  vector<int> p;
  unionfind(int N){
    p = vector<int>(N, -1);
  }
  int root(int x){
    if (p[x] < 0){
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  void unite(int x, int y){
    x = root(x);
    y = root(y);
    if (x != y){
      if (p[x] < p[y]){
        swap(x, y);
      }
      p[y] += p[x];
      p[x] = y;
    }
  }
};
struct heavy_light_decomposition{
  vector<int> p, sz, in, id, next;
  void dfs1(vector<vector<int>> &c, int v){
    sz[v] = 1;
    for (int &w : c[v]){
      dfs1(c, w);
      sz[v] += sz[w];
      if (sz[w] > sz[c[v][0]]){
        swap(w, c[v][0]);
      }
    }
  }
  void dfs2(vector<vector<int>> &c, int &t, int v){
    in[v] = t;
    id[t] = v;
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
  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c, int r = 0): p(p){
    int N = p.size();
    sz = vector<int>(N);
    dfs1(c, r);
    in = vector<int>(N);
    next = vector<int>(N, r);
    id = vector<int>(N);
    int t = 0;
    dfs2(c, t, r);
  }
  int la(int u, int x){
    while (true){
      if (x <= in[u] - in[next[u]]){
        return id[in[u] - x];
      }
      x -= in[u] - in[next[u]] + 1;
      u = p[next[u]];
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
    int ans = 0;
    while (true){
      if (in[u] > in[v]){
        swap(u, v);
      }
      if (next[u] == next[v]){
        ans += in[v] - in[u];
        return ans;
      }
      ans += in[v] - in[next[v]] + 1;
      v = p[next[v]];
    }
  }
};
int main(){
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> E1(m);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E1[i] = make_pair(u, v);
  }
  unionfind UF(n);
  vector<bool> used(m, false);
  vector<vector<int>> E2(n);
  for (int i = 0; i < m; i++){
    int u = E1[i].first;
    int v = E1[i].second;
    if (!UF.same(u, v)){
      UF.unite(u, v);
      used[i] = true;
      E2[u].push_back(v);
      E2[v].push_back(u);
    }
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
    for (int w : E2[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  heavy_light_decomposition T(p, c);
  vector<int> imos(n, 0);
  for (int i = 0; i < m; i++){
    if (!used[i]){
      int u = E1[i].first;
      int v = E1[i].second;
      int w = T.lca(u, v);
      if (w != u && w != v){
        imos[0]++;
        imos[u]--;
        imos[v]--;
      } else {
        if (w == v){
          swap(u, v);
        }
        int d = T.dist(u, v);
        int x = T.la(v, d - 1);
        imos[x]++;
        imos[v]--;
      }
    }
  }
  for (int v : bfs){
    for (int w : c[v]){
      imos[w] += imos[v];
    }
  }
  for (int i = 0; i < n; i++){
    if (imos[i] == 0){
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << endl;
}