#include <bits/stdc++.h>

template <uint32_t Modulus>
class ModularInt {
  using M = ModularInt;

 public:
  static_assert(int(Modulus) >= 1, "Modulus must be in the range [1, 2^31)");
  static constexpr int modulus() { return Modulus; }
  static M raw(uint32_t v) {
    M res;
    res.v_ = v;
    return res;
  }

  ModularInt() : v_(0) {}
  ModularInt(int64_t v) : v_(v % Modulus) {
    v_ = int(v_) < 0 ? v_ + Modulus : v_;
  }

  template <class T>
  explicit operator T() const {
    return v_;
  }
  M& operator++() { return v_ = ++v_ == Modulus ? 0 : v_, *this; }
  M& operator--() { return --(v_ ? v_ : v_ = Modulus), *this; }
  M operator+() const { return *this; }
  M operator-() const { return raw(v_ ? Modulus - v_ : 0); }
  M& operator*=(M o) { return v_ = uint64_t(v_) * o.v_ % Modulus, *this; }
  M& operator/=(M o) {
    auto [inv, gcd] = extgcd(o.v_, Modulus);
    assert(gcd == 1);
    return *this *= inv;
  }
  M& operator+=(M o) {
    return v_ = int(v_ += o.v_ - Modulus) < 0 ? v_ + Modulus : v_, *this;
  }
  M& operator-=(M o) {
    return v_ = int(v_ -= o.v_) < 0 ? v_ + Modulus : v_, *this;
  }

  friend M operator++(M& a, int) { return std::exchange(a, ++M(a)); }
  friend M operator--(M& a, int) { return std::exchange(a, --M(a)); }
  friend M operator*(M a, M b) { return a *= b; }
  friend M operator/(M a, M b) { return a /= b; }
  friend M operator+(M a, M b) { return a += b; }
  friend M operator-(M a, M b) { return a -= b; }
  friend std::istream& operator>>(std::istream& is, M& x) {
    int64_t v;
    return is >> v, x = v, is;
  }
  friend std::ostream& operator<<(std::ostream& os, M x) { return os << x.v_; }
  friend bool operator==(M a, M b) { return a.v_ == b.v_; }
  friend bool operator!=(M a, M b) { return a.v_ != b.v_; }

 private:
  static std::array<int, 2> extgcd(int a, int b) {
    std::array x{1, 0};
    while (b) {
      int q = a / b;
      std::swap(x[0] -= q * x[1], x[1]);
      std::swap(a -= q * b, b);
    }
    return {x[0], a};
  }

  uint32_t v_;
};

struct graph {
  struct edge {
    int64_t cost;
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

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l, r;
  Rep(int _l, int _r) : l(_l), r(_r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l}; }
  I end() const { return {r}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l, r;
  Per(int _l, int _r) : l(_l), r(_r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r - 1}; }
  I end() const { return {l - 1}; }
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
  return std::cin >> res, res;
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

template <class Node, class G, class F>
auto tree_dp(G& g, F add_root, int r = 0) {
  g.build_hld(r);
  vector<Node> lower(g.n - 1), upper(g.n - 1), all(g.n);
  vector<vector<Node>> cum(g.n);
  for_each(rbegin(g.order), rend(g.order), [&](int v) {
    int m = size(g.adj[v]) - (v != r);
    cum[v].resize(m + 1);
    for (int i = m; i--;) cum[v][i] = lower[g.adj[v][i].first] + cum[v][i + 1];
    if (v != r) lower[g.pe[v]] = add_root(cum[v][0], v, g.pe[v]);
  });
  for (int v : g.order) {
    Node cur = v != r ? upper[g.pe[v]] : Node();
    for (int i = 0; i < (int)size(cum[v]) - 1; ++i) {
      upper[g.adj[v][i].first] =
          add_root(cur + cum[v][i + 1], v, g.adj[v][i].first);
      cur = cur + lower[g.adj[v][i].first];
    }
    all[v] = add_root(cur, v, -1);
  }
  return make_tuple(lower, upper, all);
}

using Mint = ModularInt<int(1e9) + 7>;

struct Node {
  array<Mint, 3> sum{};
  friend Node operator+(Node a, const Node& b) {
    for (int d : Rep(3)) a.sum[d] += b.sum[d];
    return a;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  hld_forest g(n);
  for (int _ = n - 1; _--;) {
    int u = scan() - 1, v = scan() - 1, c = scan();
    g.add({c, u, v});
  }
  g.build_hld();
  auto add_root = [&](Node e, int, int id) {
    if (id == -1) return e;
    Mint c = g.edges[id].cost;
    e.sum[0] += 1;
    e.sum[2] += c * c * e.sum[0] + 2 * c * e.sum[1];
    e.sum[1] += c * e.sum[0];
    return e;
  };
  auto [lower, upper, all] = tree_dp<Node>(g, add_root);

  for (int q = scan(); q--;) {
    int u = scan() - 1, v = scan() - 1;
    Mint ans;
    if (g.is_ancestor(v, u)) {
      auto&& s = v ? upper[g.pe[v]].sum : Node{}.sum;
      Mint c = g.distance(v, u);
      ans += s[2];
      ans += s[1] * 2 * c;
      ans += s[0] * c * c;
      ans = all[u].sum[2] - ans;
    } else {
      auto&& s = lower[g.pe[v]].sum;
      Mint c = g.distance(u, g.pv[v]);
      ans += s[2];
      ans += s[1] * 2 * c;
      ans += s[0] * c * c;
    }
    ans *= 2;
    ans -= all[u].sum[2];
    cout << ans << '\n';
  }
}