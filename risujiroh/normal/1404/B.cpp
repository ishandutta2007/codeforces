#include <bits/extc++.h>

using namespace std;

struct graph {
  struct edge {
    static bool inline cost;
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

struct dfs_forest : graph {
  using T = decltype(edge::cost);
  vector<int> root, pv, pe, sz, dep, min_dep, last, ord, in, out;
  vector<T> dist;
  int trials;
  dfs_forest(int _n = 0) : graph(_n), dist(n), trials(0) {
    for (auto p : {&root, &pv, &pe, &sz, &dep, &min_dep, &last, &in, &out})
      p->assign(n, -1);
  }
  int add(const edge& e) { return graph::add(e); }
  void dfs(int v) {
    sz[v] = 1, min_dep[v] = dep[v], last[v] = trials;
    in[v] = size(ord), ord.push_back(v);
    for (auto [id, u] : adj[v]) {
      if (id == pe[v]) continue;
      if (last[u] == trials) {
        min_dep[v] = min(min_dep[v], dep[u]);
        continue;
      }
      root[u] = root[v], pv[u] = v, pe[u] = id, dep[u] = dep[v] + 1;
      dist[u] = dist[v] + edges[id].cost;
      dfs(u);
      sz[v] += sz[u], min_dep[v] = min(min_dep[v], min_dep[u]);
    }
    out[v] = size(ord);
  }
  void build(int r, bool clear_ord = true) {
    root[r] = r, pv[r] = pe[r] = -1, dep[r] = 0, dist[r] = T{};
    if (clear_ord) ord.clear();
    dfs(r);
    ++trials;
  }
  void build() {
    fill(begin(root), end(root), -1);
    for (int v = 0; v < n; ++v)
      if (root[v] == -1) build(v, v == 0);
  }
  int farther(int id) const {
    int u = edges[id].src, v = edges[id].dst;
    return dep[u] < dep[v] ? v : u;
  }
  bool spans(int id) const { return id == pe[farther(id)]; }
  bool anc(int u, int v) const { return in[u] <= in[v] and out[v] <= out[u]; }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    --a, --b;
    dfs_forest g(n);
    for (int _ = n - 1; _--;) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g.add({u, v});
    }

    bool can = [&] {
      g.build(a);
      if (g.dep[b] <= da) return true;

      int diam = [&] {
        int x = max_element(begin(g.dep), end(g.dep)) - begin(g.dep);
        g.build(x);
        return *max_element(begin(g.dep), end(g.dep));
      }();
      if (diam <= 2 * da) return true;

      return db <= 2 * da;
    }();

    cout << (can ? "Alice\n" : "Bob\n");
  }
}