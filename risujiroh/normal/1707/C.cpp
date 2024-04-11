#include <bits/stdc++.h>

void solve(std::istream&, std::ostream&);

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve(std::cin, std::cout);
}

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

struct Graph {
  struct Edge {
    int src, dst;
    int64_t cost;

    int other(int v) const {
      __glibcxx_assert(v == src or v == dst);
      return src ^ dst ^ v;
    }
  };

  std::vector<Edge> edges;
  std::vector<std::vector<std::pair<int, int>>> adj;

  Graph() {}
  explicit Graph(int n) : adj(n) {}

  int n() const { return std::size(adj); }
  int m() const { return std::size(edges); }
  int add_edge(const Edge& e, bool directed) {
    __glibcxx_assert(0 <= e.src and e.src < n());
    __glibcxx_assert(0 <= e.dst and e.dst < n());
    int id = m();
    edges.push_back(e);
    adj[e.src].emplace_back(e.dst, id);
    if (not directed) adj[e.dst].emplace_back(e.src, id);
    return id;
  }
};

struct DfsTree : Graph {
  using T = decltype(Edge::cost);

  std::vector<int> root;
  std::vector<int> pv;
  std::vector<int> pe;
  std::vector<int> order;
  std::vector<int> in;
  std::vector<int> out;
  std::vector<int> sub;
  std::vector<int> depth;
  std::vector<int> min_depth;
  std::vector<T> dist;
  std::vector<int> last;
  int num_trials;

  DfsTree() {}
  explicit DfsTree(int n)
      : Graph(n),
        root(n, -1),
        pv(n, -1),
        pe(n, -1),
        in(n, -1),
        out(n, -1),
        sub(n, -1),
        depth(n, -1),
        min_depth(n, -1),
        dist(n, std::numeric_limits<T>::max()),
        last(n, -1),
        num_trials(0) {}

  int add_edge(const Edge& e) { return Graph::add_edge(e, false); }
  void dfs(int r, bool clear_order = true) {
    __glibcxx_assert(0 <= r and r < n());
    root[r] = r;
    pv[r] = -1;
    pe[r] = -1;
    if (clear_order) order.clear();
    depth[r] = 0;
    dist[r] = T{};
    dfs_impl(r);
    ++num_trials;
  }
  void dfs_all() {
    std::fill(std::begin(root), std::end(root), -1);
    for (int v = 0; v < n(); ++v)
      if (root[v] == -1) dfs(v, v == 0);
  }

  int deeper(int id) const {
    __glibcxx_assert(0 <= id and id < m());
    int a = edges[id].src;
    int b = edges[id].dst;
    return depth[a] < depth[b] ? b : a;
  }
  bool is_tree_edge(int id) const {
    __glibcxx_assert(0 <= id and id < m());
    return id == pe[deeper(id)];
  }
  bool is_ancestor(int u, int v) const {
    __glibcxx_assert(0 <= u and u < n());
    __glibcxx_assert(0 <= v and v < n());
    return in[u] <= in[v] and out[v] <= out[u];
  }

 private:
  void dfs_impl(int v) {
    in[v] = std::size(order);
    order.push_back(v);
    sub[v] = 1;
    min_depth[v] = depth[v];
    last[v] = num_trials;
    for (auto&& [u, id] : adj[v]) {
      if (id == pe[v]) continue;
      if (last[u] == num_trials) {
        min_depth[v] = std::min(min_depth[v], depth[u]);
        continue;
      }
      root[u] = root[v];
      pv[u] = v;
      pe[u] = id;
      depth[u] = depth[v] + 1;
      dist[u] = dist[v] + edges[id].cost;
      dfs_impl(u);
      sub[v] += sub[u];
      min_depth[v] = std::min(min_depth[v], min_depth[u]);
    }
    out[v] = std::size(order);
  }
};

struct HldTree : DfsTree {
  std::vector<int> head;

  HldTree() {}
  explicit HldTree(int n) : DfsTree(n), head(n, -1) {}

  void build(int r, bool clear_order = true) {
    __glibcxx_assert(0 <= r and r < n());
    dfs(r, clear_order);
    order.erase(std::end(order) - sub[r], std::end(order));
    head[r] = r;
    build_impl(r);
  }
  void build_all() {
    std::fill(std::begin(root), std::end(root), -1);
    for (int v = 0; v < n(); ++v)
      if (root[v] == -1) build(v, v == 0);
  }

  int lca(int u, int v) const {
    __glibcxx_assert(0 <= u and u < n());
    __glibcxx_assert(0 <= v and v < n());
    __glibcxx_assert(root[u] == root[v]);
    while (true) {
      if (in[u] > in[v]) std::swap(u, v);
      if (head[u] == head[v]) return u;
      v = pv[head[v]];
    }
  }
  int d(int u, int v) const {
    __glibcxx_assert(0 <= u and u < n());
    __glibcxx_assert(0 <= v and v < n());
    __glibcxx_assert(root[u] == root[v]);
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }
  T distance(int u, int v) const {
    __glibcxx_assert(0 <= u and u < n());
    __glibcxx_assert(0 <= v and v < n());
    __glibcxx_assert(root[u] == root[v]);
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
  }
  int la(int v, int d) const {
    __glibcxx_assert(0 <= v and v < n());
    __glibcxx_assert(0 <= d and d <= depth[v]);
    while (depth[head[v]] > d) v = pv[head[v]];
    return order[in[head[v]] + (d - depth[head[v]])];
  }
  int next(int src, int dst) const {
    __glibcxx_assert(0 <= src and src < n());
    __glibcxx_assert(0 <= dst and dst < n());
    __glibcxx_assert(root[src] == root[dst]);
    __glibcxx_assert(src != dst);
    if (not is_ancestor(src, dst)) return pv[src];
    return la(dst, depth[src] + 1);
  }
  int next(int src, int dst, int k) const {
    __glibcxx_assert(0 <= src and src < n());
    __glibcxx_assert(0 <= dst and dst < n());
    __glibcxx_assert(root[src] == root[dst]);
    __glibcxx_assert(k >= 0);
    int v = lca(src, dst);
    if (k <= depth[src] - depth[v]) return la(src, depth[src] - k);
    k -= depth[src] - depth[v];
    __glibcxx_assert(k <= depth[dst] - depth[v]);
    return la(dst, depth[v] + k);
  }
  template <class Function>
  void apply(int src, int dst, bool vertex, Function f) const {
    __glibcxx_assert(0 <= src and src < n());
    __glibcxx_assert(0 <= dst and dst < n());
    __glibcxx_assert(root[src] == root[dst]);
    int v = lca(src, dst);
    while (head[src] != head[v]) {
      f(in[src] + 1, in[head[src]]);
      src = pv[head[src]];
    }
    if (vertex)
      f(in[src] + 1, in[v]);
    else if (src != v)
      f(in[src] + 1, in[v] + 1);
    auto rec = [&](auto self, int to) -> void {
      if (head[v] == head[to]) {
        if (v != to) f(in[v] + 1, in[to] + 1);
        return;
      }
      self(self, pv[head[to]]);
      f(in[head[to]], in[to] + 1);
    };
    rec(rec, dst);
  }
  template <class Searcher>
  int search(int src, int dst, bool vertex, Searcher f) const {
    __glibcxx_assert(0 <= src and src < n());
    __glibcxx_assert(0 <= dst and dst < n());
    __glibcxx_assert(root[src] == root[dst]);
    int res = -1;
    apply(src, dst, vertex, [&](int l, int r) {
      if (res != -1) return;
      int i = f(l, r);
      if (l > r) std::swap(l, r);
      if (l <= i and i < r) res = vertex ? order[i] : pe[order[i]];
    });
    return res;
  }

 private:
  void build_impl(int v) {
    in[v] = std::size(order);
    order.push_back(v);
    auto pos =
        std::partition(std::begin(adj[v]), std::end(adj[v]),
                       [&](auto&& e) { return e.second == pe[e.first]; });
    auto it = std::max_element(
        std::begin(adj[v]), pos,
        [&](auto&& a, auto&& b) { return sub[a.first] < sub[b.first]; });
    if (it != std::begin(adj[v])) std::iter_swap(std::begin(adj[v]), it);
    std::partition(pos, std::end(adj[v]),
                   [&](auto&& e) { return e.second == pe[v]; });
    for (auto&& [u, id] : adj[v]) {
      if (id != pe[u]) break;
      head[u] = u == adj[v].front().first ? head[v] : u;
      build_impl(u);
    }
    out[v] = std::size(order);
  }
};

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  int n, m;
  is >> n >> m;

  atcoder::dsu d(n);
  HldTree g(n);
  std::vector<std::array<int, 2>> bad_edges;
  for (int e = 0; e < m; ++e) {
    int u, v;
    is >> u >> v;
    --u;
    --v;

    if (d.same(u, v)) {
      bad_edges.push_back({u, v});
      continue;
    }

    d.merge(u, v);
    g.add_edge({u, v, 1});
  }
  g.build(0);

  std::vector<int> f(n + 1);
  for (auto [u, v] : bad_edges) {
    for (int _ = 2; _--; std::swap(u, v)) {
      if (g.is_ancestor(v, u)) {
        int w = g.la(u, g.depth[v] + 1);
        ++f[0];
        --f[g.in[w]];
        ++f[g.out[w]];
        --f[n];
      } else {
        ++f[g.in[v]];
        --f[g.out[v]];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    f[i + 1] += f[i];
  }

  for (int v = 0; v < n; ++v) {
    os << (f[g.in[v]] == int(bad_edges.size()));
  }
  os << '\n';
}