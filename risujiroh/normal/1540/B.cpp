#include <bits/stdc++.h>

template <class> class GetInverse;
template <uint32_t P> class Fp {
 public:
  static_assert([](int n) -> bool {
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0) return false;
    return 3 <= n and n < 1 << 30;
  }(P));
  static constexpr int mod() { return P; }

  Fp() : v(0) {}
  template <class Int> Fp(const Int& a) : v(a % mod()) { v = (uint64_t(v + P) << 32) % P; }
  int val() const {
    int res = reduce(v) - P;
    return res < 0 ? res + P : res;
  }
  Fp& operator++() { return *this += 1; }
  Fp& operator--() { return *this -= 1; }
  Fp& operator*=(Fp o) { return v = reduce(uint64_t(v) * o.v), *this; }
  Fp& operator/=(Fp o) { return *this *= GetInverse<Fp>{}(o); }
  Fp& operator+=(Fp o) { return v = int(v += o.v - 2 * P) < 0 ? v + 2 * P : v, *this; }
  Fp& operator-=(Fp o) { return v = int(v -= o.v) < 0 ? v + 2 * P : v, *this; }

  friend Fp operator++(Fp& a, int) { return std::exchange(a, ++Fp(a)); }
  friend Fp operator--(Fp& a, int) { return std::exchange(a, --Fp(a)); }
  friend Fp operator+(Fp a) { return a; }
  friend Fp operator-(Fp a) { return Fp{} -= a; }
  friend Fp operator*(Fp a, Fp b) { return a *= b; }
  friend Fp operator/(Fp a, Fp b) { return a /= b; }
  friend Fp operator+(Fp a, Fp b) { return a += b; }
  friend Fp operator-(Fp a, Fp b) { return a -= b; }
  friend bool operator==(Fp a, Fp b) { return a.v == b.v or a.v + P == b.v or a.v == b.v + P; }
  friend bool operator!=(Fp a, Fp b) { return not(a == b); }

 private:
  static constexpr uint32_t R = []() -> uint32_t {
    uint32_t res = -P;
    for (int _ = 4; _--;) res *= P * res + 2;
    return res;
  }();
  static uint32_t reduce(uint64_t x) { return (x + P * uint64_t(R * uint32_t(x))) >> 32; }

  uint32_t v;
};
template <uint32_t P> class GetInverse<Fp<P>> {
 public:
  static void init(int n) {
    inv.reserve(n + 1);
    for (int i = std::size(inv); i <= n;) {
      int q = P / i, j = std::min<int>(P / q, n);
      for (; i <= j; ++i) inv.push_back(-q * inv[P - q * i]);
    }
  }

  Fp<P> operator()(Fp<P> a) const {
    __glibcxx_assert(a.val());
    if ((-a).val() < int(std::size(inv))) return -inv[(-a).val()];
    int y0 = 0, z0 = P, y1 = 1, z1 = a.val();
    while (z1 >= std::max<int>(std::size(inv), 2)) std::swap(y0 -= z0 / z1 * y1, y1), std::swap(z0 %= z1, z1);
    return z1 > 1 ? y1 * inv[z1] : y1;
  }

 private:
  static inline std::vector<Fp<P>> inv{0, 1};
};

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
  template <class Function> void apply(int src, int dst, bool vertex, Function f) const {
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
  template <class Searcher> int search(int src, int dst, bool vertex, Searcher f) const {
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
    auto pos = std::partition(std::begin(adj[v]), std::end(adj[v]), [&](auto&& e) { return e.second == pe[e.first]; });
    auto it =
        std::max_element(std::begin(adj[v]), pos, [&](auto&& a, auto&& b) { return sub[a.first] < sub[b.first]; });
    if (it != std::begin(adj[v])) std::iter_swap(std::begin(adj[v]), it);
    std::partition(pos, std::end(adj[v]), [&](auto&& e) { return e.second == pe[v]; });
    for (auto&& [u, id] : adj[v]) {
      if (id != pe[u]) break;
      head[u] = u == adj[v].front().first ? head[v] : u;
      build_impl(u);
    }
    out[v] = std::size(order);
  }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  HldTree g(n);
  for (int _ = n - 1; _--;) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add_edge({u, v, 1});
  }
  using Mint = Fp<int(1e9) + 7>;
  GetInverse<Mint>::init(n);
  vector f(n + 1, vector<Mint>(n + 1));
  for (int i = 1; i <= n; ++i) {
    f[i][0] = 1;
    for (int j = 1; j <= n; ++j) f[i][j] = (f[i - 1][j] + f[i][j - 1]) / 2;
  }
  Mint ans;
  for (int v = 0; v < n; ++v) {
    g.build(v);
    for (int u = 0; u < v; ++u) {
      for (int x = g.pv[u], px = u;; x = g.pv[x]) {
        int c = g.sub[x] - g.sub[px];
        if (x == v) {
          ans += c;
          break;
        }
        ans += c * f[g.depth[u] - g.depth[x]][g.depth[x]];
        px = x;
      }
    }
  }
  ans /= n;
  cout << ans.val() << '\n';
}