#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

struct graph {
  struct edge {
    int src, dst;
    char col;
    int operator-(int v) const { return src ^ dst ^ v; }
  };
  int n, m;
  vector<edge> edges;
  vector<vector<pair<int, int>>> adj;
  graph(int _n = 0) : n(_n), m(0), adj(n) {}
  int add(const edge& e, bool directed = false) {
    edges.push_back(e);
    adj[e.src].emplace_back(m, e.dst);
    if (not directed) adj[e.dst].emplace_back(m, e.src);
    return m++;
  }
};

struct dsu {
  int cc;
  vector<int> p, sz;
  dsu(int n = 0) : cc(n), p(n, -1), sz(n, 1) {}
  int root(int v) {
    if (p[v] == -1) return v;
    return p[v] = root(p[v]);
  }
  bool unite(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return false;
    --cc;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    return true;
  }
  bool same(int u, int v) { return root(u) == root(v); }
  int size(int v) { return sz[root(v)]; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  graph g(n);
  while (m--) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    --u, --v;
    g.add({u, v, c});
  }
  constexpr int inf = 1e9;
  int mn = inf;
  vector<int> res;
  for (char c : string("BR")) {
    dsu d(n), b(2 * n);
    bool ok = true;
    for (auto&& e : g.edges) {
      d.unite(e.src, e.dst);
      if (e.col == c) {
        if (b.same(e.src, n + e.dst)) {
          ok = false;
          break;
        }
        b.unite(e.src, e.dst);
        b.unite(n + e.src, n + e.dst);
      } else {
        if (b.same(e.src, e.dst)) {
          ok = false;
          break;
        }
        b.unite(e.src, n + e.dst);
        b.unite(n + e.src, e.dst);
      }
    }
    if (not ok) continue;
    vector<vector<int>> vs(n);
    for (int v = 0; v < n; ++v) {
      vs[d.root(v)].push_back(v);
    }
    vector<int> cur;
    for (int r = 0; r < n; ++r) {
      if (empty(vs[r])) continue;
      int x = 0, y = 0;
      for (int v : vs[r]) {
        ++(b.same(r, v) ? x : y);
      }
      if (x < y) {
        for (int v : vs[r])
          if (b.same(r, v)) cur.push_back(v);
      } else {
        for (int v : vs[r])
          if (not b.same(r, v)) cur.push_back(v);
      }
    }
    if ((int)size(cur) < mn) {
      mn = size(cur);
      res = cur;
    }
  }
  if (mn == inf) {
    cout << "-1\n";
    exit(0);
  }
  cout << mn << '\n';
  for (int i = 0; i < mn; ++i) {
    cout << res[i] + 1 << " \n"[i == mn - 1];
  }
}