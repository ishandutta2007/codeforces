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

struct dsu {
  dsu() {}
  explicit dsu(int n) : _cc(n), dat(n, -1) {}

  int size() const { return std::size(dat); }
  int root(int v) {
    assert(0 <= v), assert(v < size());
    return dat[v] < 0 ? v : dat[v] = root(dat[v]);
  }
  std::pair<int, int> unite(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    u = root(u), v = root(v);
    if (u == v) return {u, -1};
    --_cc;
    if (-dat[u] < -dat[v]) std::swap(u, v);
    dat[u] += dat[v];
    dat[v] = u;
    return {u, v};
  }
  bool same(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    return root(u) == root(v);
  }
  int size(int v) {
    assert(0 <= v), assert(v < size());
    return -dat[root(v)];
  }
  int cc() const { return _cc; }

 private:
  int _cc;
  std::vector<int> dat;
};

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

template <uint32_t Modulus>
struct modular {
  static_assert(int(Modulus) > 0, "Modulus must be in the range [1, 2^31)");
  static constexpr int modulus() { return Modulus; }

  modular() : v(0) {}
  modular(int64_t x) : v(x % Modulus) {
    if (int(v) < 0) v += Modulus;
  }

  explicit operator int() const { return v; }
  modular& operator++() { return ++v == Modulus ? v = 0 : 0, *this; }
  modular& operator--() { return --(v ? v : v = Modulus), *this; }
  modular operator+() const { return *this; }
  modular operator-() const {
    modular res;
    res.v = v ? Modulus - v : 0;
    return res;
  }
  modular& operator*=(modular b) {
    v = uint64_t(v) * b.v % Modulus;
    return *this;
  }
  modular& operator/=(modular b) {
    auto [x, gcd] = extgcd(b.v, Modulus);
    assert(gcd == 1);
    return *this *= x;
  }
  modular& operator+=(modular b) {
    v += b.v - Modulus;
    if (int(v) < 0) v += Modulus;
    return *this;
  }
  modular& operator-=(modular b) {
    v -= b.v;
    if (int(v) < 0) v += Modulus;
    return *this;
  }

  friend modular operator++(modular& a, int) {
    return std::exchange(a, ++modular(a));
  }
  friend modular operator--(modular& a, int) {
    return std::exchange(a, --modular(a));
  }
  friend modular operator*(modular a, modular b) { return a *= b; }
  friend modular operator/(modular a, modular b) { return a /= b; }
  friend modular operator+(modular a, modular b) { return a += b; }
  friend modular operator-(modular a, modular b) { return a -= b; }
  friend std::istream& operator>>(std::istream& is, modular& b) {
    int64_t x;
    return is >> x, b = x, is;
  }
  friend std::ostream& operator<<(std::ostream& os, modular b) {
    return os << b.v;
  }
  friend bool operator==(modular a, modular b) { return a.v == b.v; }
  friend bool operator!=(modular a, modular b) { return a.v != b.v; }

 private:
  static std::pair<int, int> extgcd(int a, int b) {
    std::array x{1, 0};
    while (b) {
      int q = a / b;
      std::swap(x[0] -= q * x[1], x[1]);
      std::swap(a -= q * b, b);
    }
    return {x[0], a};
  }

  uint32_t v;
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> c2ij(n * (n - 1) / 2);
  for (int i : rep(n))
    for (int j : rep(n)) {
      int c;
      cin >> c;
      if (i < j) {
        --c;
        c2ij[c] = {i, j};
      }
    }
  dsu d(n);
  vector<int> cnt(n);
#ifdef LOCAL
  vector<bitset<7>> bs;
#else
  vector<bitset<1500>> bs;
#endif
  for (auto [i, j] : c2ij) {
    tie(i, j) = d.unite(i, j);
    if (j != -1) cnt[i] += cnt[j];
    int t = ++cnt[i];
    int sz = d.size(i);
    if (t == sz * (sz - 1) / 2) {
      bs.emplace_back();
      for (int k : rep(n))
        if (d.same(k, i)) bs.back()[k] = 1;
    }
  }
  int sz = size(bs);
  vector<int> w(sz + 1);
  for (int v : rep(sz)) w[v] = bs[v].count() - 1;
  assert(sz <= n - 1);
  dfs_forest g(sz + 1);
  for (int v : rep(sz)) {
    int par = sz;
    for (int u : rep(sz))
      if (u != v and (bs[v] & ~bs[u]).none())
        if (par == sz or w[u] < w[par]) par = u;
    g.add({v, par});
  }
  g.build(sz);

  using mint = modular<998244353>;

  vector<vector<array<mint, 3>>> dp(g.n);
  for_each(rbegin(g.order), rend(g.order), [&](int v) {
    dp[v].resize(w[v] + 1);
    dp[v][0][0] = 1;
    dp[v][w[v]][2] = v != sz;
    for (auto [id, u] : g.adj[v]) {
      if (id == g.pe[v]) continue;
      vector<array<mint, 3>> ndp(size(dp[v]) + size(dp[u]) - 1);
      for (int x : rep(size(dp[v])))
        for (int f : rep(3))
          if (int(dp[v][x][f]))
            for (int y : rep(size(dp[u])))
              for (int g : rep(3)) {
                if (f == 2 and g) continue;
                int nf;
                if (f == 0) nf = !!g;
                if (f == 1) nf = 1;
                if (f == 2) nf = 2;
                ndp[x + y][nf] += dp[v][x][f] * dp[u][y][g];
              }
      swap(dp[v], ndp);
    }
  });
  dp.back().resize(n);
  for (int k : rep(1, n + 1)) {
    mint ans;
    ans += dp.back()[n - k][0];
    ans += dp.back()[n - k][1];
    cout << ans << " \n"[k == n];
  }
}