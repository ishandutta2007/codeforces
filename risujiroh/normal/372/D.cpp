#include <bits/stdc++.h>

struct Graph {
  struct Edge {
    int src, dst;
    int64_t cost;

    int other(int v) const {
      assert(v == src or v == dst);
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
    assert(0 <= e.src), assert(e.src < n());
    assert(0 <= e.dst), assert(e.dst < n());
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
  std::vector<int> sz;
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
        sz(n, -1),
        depth(n, -1),
        min_depth(n, -1),
        dist(n, std::numeric_limits<T>::max()),
        last(n, -1),
        num_trials(0) {}

  int add_edge(const Edge& e) { return Graph::add_edge(e, false); }

  void dfs(int r, bool clear_order = true) {
    assert(0 <= r), assert(r < n());
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
    assert(0 <= id), assert(id < m());
    int a = edges[id].src;
    int b = edges[id].dst;
    return depth[a] < depth[b] ? b : a;
  }
  bool is_tree_edge(int id) const {
    assert(0 <= id), assert(id < m());
    return id == pe[deeper(id)];
  }
  bool is_ancestor(int u, int v) const {
    assert(0 <= u), assert(u < n());
    assert(0 <= v), assert(v < n());
    return in[u] <= in[v] and out[v] <= out[u];
  }

 private:
  void dfs_impl(int v) {
    in[v] = std::size(order);
    order.push_back(v);
    sz[v] = 1;
    min_depth[v] = depth[v];
    last[v] = num_trials;
    for (auto [u, id] : adj[v]) {
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
      sz[v] += sz[u];
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
    assert(0 <= r), assert(r < n());
    dfs(r, clear_order);
    order.erase(std::end(order) - sz[r], std::end(order));
    head[r] = r;
    build_impl(r);
  }
  void build_all() {
    std::fill(std::begin(root), std::end(root), -1);
    for (int v = 0; v < n(); ++v)
      if (root[v] == -1) build(v, v == 0);
  }

  int lca(int u, int v) const {
    assert(0 <= u), assert(u < n());
    assert(0 <= v), assert(v < n());
    assert(root[u] == root[v]);
    while (true) {
      if (in[u] > in[v]) std::swap(u, v);
      if (head[u] == head[v]) return u;
      v = pv[head[v]];
    }
  }
  int d(int u, int v) const {
    assert(0 <= u), assert(u < n());
    assert(0 <= v), assert(v < n());
    assert(root[u] == root[v]);
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }
  T distance(int u, int v) const {
    assert(0 <= u), assert(u < n());
    assert(0 <= v), assert(v < n());
    assert(root[u] == root[v]);
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
  }
  int la(int v, int d) const {
    assert(0 <= v), assert(v < n());
    assert(0 <= d), assert(d <= depth[v]);
    while (depth[head[v]] > d) v = pv[head[v]];
    return order[in[head[v]] + (d - depth[head[v]])];
  }
  int next(int src, int dst) const {
    assert(0 <= src), assert(src < n());
    assert(0 <= dst), assert(dst < n());
    assert(root[src] == root[dst]);
    assert(src != dst);
    if (not is_ancestor(src, dst)) return pv[src];
    return la(dst, depth[src] + 1);
  }
  int next(int src, int dst, int k) const {
    assert(0 <= src), assert(src < n());
    assert(0 <= dst), assert(dst < n());
    assert(root[src] == root[dst]);
    assert(k >= 0);
    int v = lca(src, dst);
    if (k <= depth[src] - depth[v]) return la(src, depth[src] - k);
    k -= depth[src] - depth[v];
    assert(k <= depth[dst] - depth[v]);
    return la(dst, depth[v] + k);
  }
  template <class Function>
  void apply(int src, int dst, bool vertex, Function f) const {
    assert(0 <= src), assert(src < n());
    assert(0 <= dst), assert(dst < n());
    assert(root[src] == root[dst]);
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
    assert(0 <= src), assert(src < n());
    assert(0 <= dst), assert(dst < n());
    assert(root[src] == root[dst]);
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
    auto pos = std::partition(std::begin(adj[v]), std::end(adj[v]),
                              [&](auto e) { return e.second == pe[e.first]; });
    auto it = std::max_element(std::begin(adj[v]), pos, [&](auto a, auto b) {
      return sz[a.first] < sz[b.first];
    });
    if (it != std::begin(adj[v])) std::iter_swap(std::begin(adj[v]), it);
    std::partition(pos, std::end(adj[v]),
                   [&](auto e) { return e.second == pe[v]; });
    for (auto [u, id] : adj[v]) {
      if (id != pe[u]) break;
      head[u] = u == adj[v].front().first ? head[v] : u;
      build_impl(u);
    }
    out[v] = std::size(order);
  }
};

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l_, r_;
  Rep(int l, int r) : l_(l), r_(r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l_}; }
  I end() const { return {r_}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l_, r_;
  Per(int l, int r) : l_(l), r_(r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r_ - 1}; }
  I end() const { return {l_ - 1}; }
};

template <class F>
struct Fix : private F {
  Fix(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <class T = int>
T scan() {
  T res;
  std::cin >> res;
  return res;
}

template <class T, class U = T>
bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U = T>
bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

#ifndef LOCAL
#define DUMP(...) void(0)
template <int OnlineJudge, int Local>
constexpr int OjLocal = OnlineJudge;
#endif

using namespace std;

#define ALL(c) begin(c), end(c)

#pragma endregion

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  int k = scan();
  HldTree g(n);
  for (int _ = n - 1; _--;) g.add_edge({scan() - 1, scan() - 1, 1});
  g.build_all();

  auto cmp = [&](int u, int v) -> bool { return g.in[u] < g.in[v]; };

  set<int, decltype(cmp)> se(cmp);
  int sum = 0;
  auto add = [&](int v) {
    se.insert(v);
    if (size(se) == 1) return;
    auto prv = se.lower_bound(v);
    if (prv == begin(se))
      prv = prev(end(se));
    else
      --prv;
    auto nxt = se.upper_bound(v);
    if (nxt == end(se)) nxt = begin(se);
    sum += g.d(*prv, v);
    sum += g.d(v, *nxt);
    sum -= g.d(*prv, *nxt);
  };
  auto remove = [&](int v) {
    se.erase(v);
    if (empty(se)) return;
    auto prv = se.lower_bound(v);
    if (prv == begin(se))
      prv = prev(end(se));
    else
      --prv;
    auto nxt = se.upper_bound(v);
    if (nxt == end(se)) nxt = begin(se);
    sum -= g.d(*prv, v);
    sum -= g.d(v, *nxt);
    sum += g.d(*prv, *nxt);
  };

  int ans = 0;
  int r = 0;
  for (int l : Rep(n)) {
    while (r < n) {
      add(r);
      if (sum / 2 + 1 > k) {
        remove(r);
        break;
      }
      ++r;
    }
    chmax(ans, r - l);
    remove(l);
  }
  cout << ans << '\n';
}