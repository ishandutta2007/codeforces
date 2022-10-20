#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

struct graph {
  struct edge {
    int src, dst, cost;
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

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  --s, --t;
  graph g(n);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g.add({u, v, w});
  }
  vector<int> dep(n), min_dep(n), pe(n);
  auto dfs_tree = [&](int ignore = -1) {
    auto dfs = [&](auto&& self, int v) -> void {
      min_dep[v] = dep[v];
      for (auto [id, u] : g.adj[v]) {
        if (id == ignore or id == pe[v]) continue;
        if (dep[u] == -1) {
          dep[u] = dep[v] + 1;
          pe[u] = id;
          self(self, u);
          chmin(min_dep[v], min_dep[u]);
        } else {
          chmin(min_dep[v], dep[u]);
        }
      }
    };
    fill(begin(dep), end(dep), -1);
    dep[s] = 0;
    pe[s] = -1;
    dfs(dfs, s);
  };
  dfs_tree();
  if (dep[t] == -1) {
    cout << "0\n0\n";
    exit(0);
  }
  vector<int> st_path;
  for (int v = t; v != s; v = g.edges[pe[v]] - v) {
    st_path.push_back(pe[v]);
  }
  reverse(begin(st_path), end(st_path));
  int mn = numeric_limits<int>::max(), c = -1;
  vector<int> res;
  for (int id : st_path) {
    dfs_tree(id);
    if (dep[t] == -1) {
      if (chmin(mn, g.edges[id].cost)) {
        c = 1;
        res = {id};
      }
    } else {
      for (int v = t; v != s; v = g.edges[pe[v]] - v) {
        if (min_dep[v] < dep[v]) continue;
        if (chmin(mn, g.edges[id].cost + g.edges[pe[v]].cost)) {
          c = 2;
          res = {id, pe[v]};
        }
      }
    }
  }
  if (c == -1) {
    cout << "-1\n";
    exit(0);
  }
  cout << mn << '\n';
  cout << c << '\n';
  for (int i = 0; i < (int)size(res); ++i) {
    cout << res[i] + 1 << " \n"[i == (int)size(res) - 1];
  }
}