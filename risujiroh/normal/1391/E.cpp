#include <bits/stdc++.h>
using namespace std;

struct graph {
  struct edge {
    int src, dst;
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    graph g(n);
    while (m--) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g.add({u, v});
    }
    vector<int> dep(n, -1), pe(n, -1);
    vector<vector<int>> vs(n);
    auto dfs = [&](auto&& self, int v) -> void {
      vs[dep[v]].push_back(v);
      for (auto [id, u] : g.adj[v]) {
        if (dep[u] == -1) {
          dep[u] = dep[v] + 1;
          pe[u] = id;
          self(self, u);
        }
      }
    };
    dep[0] = 0;
    dfs(dfs, 0);
    int mxv = max_element(begin(dep), end(dep)) - begin(dep);
    if (dep[mxv] + 1 >= (n + 1) / 2) {
      vector<int> res;
      for (int v = mxv; ; v = g.edges[pe[v]] - v) {
        res.push_back(v);
        if (v == 0) break;
      }
      cout << "PATH\n";
      int k = size(res);
      cout << k << '\n';
      for (int i = 0; i < k; ++i) {
        cout << res[i] + 1 << " \n"[i == k - 1];
      }
    } else {
      vector<pair<int, int>> res;
      for (int d = 0; d < n; ++d) {
        for (int i = 1; i < (int)size(vs[d]); i += 2) {
          res.emplace_back(vs[d][i - 1], vs[d][i]);
        }
      }
      cout << "PAIRING\n";
      cout << size(res) << '\n';
      for (auto [u, v] : res) {
        cout << u + 1 << ' ' << v + 1 << '\n';
      }
    }
  }
}