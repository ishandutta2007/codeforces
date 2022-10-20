#include <bits/extc++.h>
using namespace std;

struct graph {
  struct edge {
    int src, dst, w;
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

bool ng[10][9][10][9];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  graph g(n);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g.add({u, v, w}, true);
  }
  vector<vector<pair<int, int>>> p(n);
  for (int v = 0; v < n; ++v) {
    sort(begin(g.adj[v]), end(g.adj[v]), [&](auto a, auto b) {
      return g.edges[a.first].w < g.edges[b.first].w;
    });
    int c = 0;
    for (auto [id, to] : g.adj[v]) {
      p[to].emplace_back(size(g.adj[v]), c);
      ++c;
    }
  }
  for (int v = 0; v < n; ++v) {
    sort(begin(p[v]), end(p[v]));
    int sz = size(p[v]);
    for (int t = 1; t < sz; ++t) {
      auto [i, ci] = p[v][t - 1];
      auto [j, cj] = p[v][t];
      ng[i][ci][j][cj] = true;
    }
    p[v].erase(unique(begin(p[v]), end(p[v])), end(p[v]));
    for (auto [i, ci] : p[v]) {
      for (auto [j, cj] : p[v]) {
        if (pair{i, ci} == pair{j, cj}) continue;
        ng[i][ci][j][cj] = true;
      }
    }
  }
  vector<int> c;
  int res = 0;
  auto dfs = [&](auto&& self) -> void {
    if ((int)size(c) == k) {
      for (int j = 0; j < k; ++j) {
        if (ng[j + 1][c[j]][j + 1][c[j]]) {
          return;
        }
        for (int i = 0; i < j; ++i) {
          if (ng[i + 1][c[i]][j + 1][c[j]]) {
            return;
          }
        }
      }
      ++res;
      return;
    }
    int sz = size(c);
    for (int i = 0; i <= sz; ++i) {
      c.push_back(i);
      self(self);
      c.pop_back();
    }
  };
  dfs(dfs);
  cout << res << '\n';
}