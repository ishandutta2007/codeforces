// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt")
// #define NDEBUG

#include <bits/extc++.h>
#include <x86intrin.h>

struct rep {
  struct iter {
    int i;
    constexpr void operator++() { ++i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr rep(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr rep(int n) : rep(0, n) {}
  constexpr iter begin() const { return {l}; }
  constexpr iter end() const { return {r}; }
};
struct per {
  struct iter {
    int i;
    constexpr void operator++() { --i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr per(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr per(int n) : per(0, n) {}
  constexpr iter begin() const { return {r - 1}; }
  constexpr iter end() const { return {l - 1}; }
};
template <class T, class U>
constexpr bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

struct graph {
  struct edge {
    static inline bool cost;  // dummy
    int src, dst;

    int operator-(int v) const {
      assert(v == src or v == dst);
      return src ^ dst ^ v;
    }
  };

  int n, m = 0;
  std::vector<edge> edges;
  std::vector<std::vector<std::pair<int, int>>> adj;
  std::function<bool(int)> ignore = [](int) { return false; };

  graph() : n(0) {}
  explicit graph(int _n) : n(_n), adj(n) {}

  int add(const edge& e, bool directed) {
    assert(0 <= e.src), assert(e.src < n);
    assert(0 <= e.dst), assert(e.dst < n);
    edges.push_back(e);
    adj[e.src].emplace_back(m, e.dst);
    if (not directed) adj[e.dst].emplace_back(m, e.src);
    return m++;
  }
};

struct dfs_forest : graph {
  using cost_t = decltype(edge::cost);

  std::vector<int> root, pv, pe, sz, depth, min_depth, last, order, in, out;
  std::vector<cost_t> dist;
  int trials;

  dfs_forest(int _n = 0) : graph(_n), dist(n), trials(0) {
    for (auto p : {&root, &pv, &pe, &sz, &depth, &min_depth, &last, &in, &out})
      p->assign(n, -1);
  }

  int add(const edge& e) { return graph::add(e, false); }
  void build(int r, bool clear_order = true) {
    assert(0 <= r), assert(r < n);
    root[r] = r, pv[r] = pe[r] = -1, depth[r] = 0, dist[r] = cost_t{};
    if (clear_order) order.clear();
    dfs(r);
    ++trials;
  }
  void build() {
    fill(begin(root), end(root), -1);
    for (int v = 0; v < n; ++v)
      if (root[v] == -1) build(v, v == 0);
  }
  int deeper(int id) const {
    assert(0 <= id), assert(id < m), assert(not ignore(id));
    int u = edges[id].src, v = edges[id].dst;
    return depth[u] < depth[v] ? v : u;
  }
  bool is_tree_edge(int id) const {
    assert(0 <= id), assert(id < m), assert(not ignore(id));
    return id == pe[deeper(id)];
  }
  bool is_ancestor(int u, int v) const {
    assert(0 <= u), assert(u < n);
    assert(0 <= v), assert(v < n);
    return in[u] <= in[v] and out[v] <= out[u];
  }

 private:
  void dfs(int v) {
    sz[v] = 1, min_depth[v] = depth[v], last[v] = trials;
    in[v] = size(order), order.push_back(v);
    for (auto [id, u] : adj[v]) {
      if (ignore(id) or id == pe[v]) continue;
      if (last[u] == trials) {
        min_depth[v] = std::min(min_depth[v], depth[u]);
        continue;
      }
      root[u] = root[v], pv[u] = v, pe[u] = id, depth[u] = depth[v] + 1;
      dist[u] = dist[v] + edges[id].cost;
      dfs(u);
      sz[v] += sz[u], min_depth[v] = std::min(min_depth[v], min_depth[u]);
    }
    out[v] = size(order);
  }
};

struct hld_forest : dfs_forest {
  std::vector<int> head;

  hld_forest(int _n = 0) : dfs_forest(_n), head(n) {}

  void build_hld(int r, bool clear_order = true) {
    assert(0 <= r), assert(r < n);
    build(r, clear_order);
    order.erase(end(order) - sz[r], end(order));
    head[r] = r;
    dfs_hld(r);
  }
  void build_hld() {
    fill(begin(root), end(root), -1);
    for (int v = 0; v < n; ++v)
      if (root[v] == -1) build_hld(v, v == 0);
  }
  int lca(int u, int v) const {
    assert(0 <= u), assert(u < n);
    assert(0 <= v), assert(v < n);
    assert(root[u] == root[v]);
    while (true) {
      if (in[u] > in[v]) std::swap(u, v);
      if (head[u] == head[v]) return u;
      v = pv[head[v]];
    }
  }
  int d(int u, int v) const {
    assert(0 <= u), assert(u < n);
    assert(0 <= v), assert(v < n);
    assert(root[u] == root[v]);
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }
  cost_t distance(int u, int v) const {
    assert(0 <= u), assert(u < n);
    assert(0 <= v), assert(v < n);
    assert(root[u] == root[v]);
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
  }
  int la(int v, int d) const {
    assert(0 <= v), assert(v < n);
    assert(0 <= d), assert(d <= depth[v]);
    while (depth[head[v]] > d) v = pv[head[v]];
    return order[in[head[v]] + (d - depth[head[v]])];
  }
  int next(int src, int dst) const {
    assert(0 <= src), assert(src < n);
    assert(0 <= dst), assert(dst < n);
    assert(root[src] == root[dst]);
    assert(src != dst);
    if (not is_ancestor(src, dst)) return pv[src];
    return la(dst, depth[src] + 1);
  }
  int next(int src, int dst, int k) const {
    assert(0 <= src), assert(src < n);
    assert(0 <= dst), assert(dst < n);
    assert(root[src] == root[dst]);
    assert(k >= 0);
    int v = lca(src, dst);
    if (k <= depth[src] - depth[v]) return la(src, depth[src] - k);
    k -= depth[src] - depth[v];
    assert(k <= depth[dst] - depth[v]);
    return la(dst, depth[v] + k);
  }
  template <class Function>
  void apply(int src, int dst, bool vertex, Function func) const {
    assert(0 <= src), assert(src < n);
    assert(0 <= dst), assert(dst < n);
    assert(root[src] == root[dst]);
    int v = lca(src, dst);
    for (auto [a, b] : ascend(src, v)) func(a + 1, b);
    if (vertex) func(in[v], in[v] + 1);
    for (auto [a, b] : descend(v, dst)) func(a, b + 1);
  }

 private:
  void dfs_hld(int v) {
    in[v] = size(order), order.push_back(v);
    sort(begin(adj[v]), end(adj[v]), [&](auto a, auto b) {
      int au = a.second, bu = b.second;
      return (a.first == pe[au]) * sz[au] > (b.first == pe[bu]) * sz[bu];
    });
    for (auto [id, u] : adj[v]) {
      if (ignore(id) or id == pe[v] or not is_tree_edge(id)) continue;
      head[u] = u == adj[v][0].second ? head[v] : u;
      dfs_hld(u);
    }
    out[v] = size(order);
  }
  auto ascend(int src, int dst) const {
    std::vector<std::pair<int, int>> res;
    while (head[src] != head[dst]) {
      res.emplace_back(in[src], in[head[src]]);
      src = pv[head[src]];
    }
    if (src != dst) res.emplace_back(in[src], in[dst] + 1);
    return res;
  }
  std::vector<std::pair<int, int>> descend(int src, int dst) const {
    if (src == dst) return {};
    if (head[src] == head[dst]) return {{in[src] + 1, in[dst]}};
    auto res = descend(src, pv[head[dst]]);
    res.emplace_back(in[head[dst]], in[dst]);
    return res;
  }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  hld_forest g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add({u, v});
  }
  g.build_hld();
  vector<int> x(n + 1), y(n + 1);
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (g.root[u] != g.root[v]) {
      cout << "No\n";
      exit(0);
    }
    g.apply(u, v, false, [&](int l, int r) {
      if (l < r) {
        ++x[l];
        --x[r];
      } else {
        ++y[r];
        --y[l];
      }
    });
  }
  for (int i : rep(n)) {
    x[i + 1] += x[i];
    y[i + 1] += y[i];
  }
  for (int v : rep(n)) {
    if (g.root[v] == v) continue;
    if (g.min_depth[v] < g.depth[v]) continue;
    if (x[g.in[v]] and y[g.in[v]]) {
      cout << "No\n";
      exit(0);
    }
  }
  cout << "Yes\n";
}