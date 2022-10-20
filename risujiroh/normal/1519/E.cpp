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

using P = pair<int64_t, int64_t>;
auto cmp = [](P a, P b) {
  return __int128_t(a.first) * b.second < __int128_t(b.first) * a.second;
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  vector<int64_t> a(n), b(n), c(n), d(n);
  vector<P> slopes;
  for (int i : Rep(n)) {
    a[i] = scan();
    b[i] = scan();
    c[i] = scan();
    d[i] = scan();
    slopes.emplace_back(b[i] * c[i], d[i] * (a[i] + b[i]));
    slopes.emplace_back(b[i] * (c[i] + d[i]), a[i] * d[i]);
  }
  sort(ALL(slopes), cmp);
  for (auto&& [p, q] : slopes) {
    auto g = gcd(p, q);
    p /= g;
    q /= g;
  }
  slopes.erase(unique(ALL(slopes)), end(slopes));
  DUMP(slopes);
  DfsTree g(size(slopes));
  for (int i : Rep(n)) {
    int u =
        lower_bound(ALL(slopes), P{b[i] * c[i], d[i] * (a[i] + b[i])}, cmp) -
        begin(slopes);
    int v =
        lower_bound(ALL(slopes), P{b[i] * (c[i] + d[i]), a[i] * d[i]}, cmp) -
        begin(slopes);
    g.add_edge({u, v, 1});
  }
  g.dfs_all();
  vector used(n, false);
  vector<pair<int, int>> ans;
  for_each(rbegin(g.order), rend(g.order), [&](int v) {
    int t = -1;
    for (auto&& [u, id] : g.adj[v]) {
      if (id == g.pe[v]) continue;
      if (used[id]) continue;
      if (t != -1) {
        ans.emplace_back(t, id);
        used[t] = true;
        used[id] = true;
        t = -1;
      } else {
        t = id;
      }
    }
    if (g.pe[v] != -1) {
      assert(not used[g.pe[v]]);
      if (t != -1) {
        ans.emplace_back(t, g.pe[v]);
        used[t] = true;
        used[g.pe[v]] = true;
      }
    }
  });
  cout << size(ans) << '\n';
  for (auto&& [i, j] : ans) cout << i + 1 << ' ' << j + 1 << '\n';
}