#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  ModInt() : v(0) {}
  template<class Int> ModInt(Int x) : v(x >= 0 ? x % P : -x % P ? P - -x % P : 0) {}
  constexpr ModInt(unsigned v, int) : v(v) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool) *this; }
  M operator*(M rhs) const { return M(*this) *= rhs; }
  M operator/(M rhs) const { return M(*this) /= rhs; }
  M operator+(M rhs) const { return M(*this) += rhs; }
  M operator-(M rhs) const { return M(*this) -= rhs; }
  bool operator==(M rhs) const { return v == rhs.v; }
  bool operator!=(M rhs) const { return !(*this == rhs); }
  M& operator*=(M rhs) { v = (unsigned long long) v * rhs.v % P; return *this; }
  M& operator/=(M rhs) { return *this *= rhs.inv(); }
  M& operator+=(M rhs) { v = rhs.v < P - v ? v + rhs.v : v - (P - rhs.v); return *this; }
  M& operator-=(M rhs) { v = rhs.v <= v ? v - rhs.v : v + (P - rhs.v); return *this; }
  M inv() const {
    int a = v, b = P, x = 1, u = 0;
    while (b) {
      int q = a / b;
      swap(a -= q * b, b);
      swap(x -= q * u, u);
    }
    assert(a == 1);
    return x;
  }
  template<class Int> M pow(Int n) const {
    n = n >= 0 ? n % (P - 1) : P - 1 - -n % (P - 1);
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
  template<class Int> friend M operator*(Int lhs, M rhs) { return M(lhs) *= rhs; }
  template<class Int> friend M operator/(Int lhs, M rhs) { return M(lhs) /= rhs; }
  template<class Int> friend M operator+(Int lhs, M rhs) { return M(lhs) += rhs; }
  template<class Int> friend M operator-(Int lhs, M rhs) { return M(lhs) -= rhs; }
  friend ostream& operator<<(ostream& os, M rhs) { return os << rhs.v; }
  friend istream& operator>>(istream& is, M& rhs) { lint x; is >> x; rhs = x; return is; }
  template<class Int> friend bool operator==(Int lhs, M rhs) { return M(lhs) == rhs; }
  template<class Int> friend bool operator!=(Int lhs, M rhs) { return !(lhs == rhs); }
};
using Mint = ModInt<(unsigned) 1e9 + 7>;

namespace LCA {
  using T = int;
  struct Edge { int to; T w; };
  T op(const T& x, const T& y) { return x + y; }
  constexpr T e = 0;

  V<> dep;
  VV<> par;
  VV<T> val;
  void init(const VV<Edge>& g, int r) {
    int n = g.size();
    dep.resize(n);
    par.assign(__lg(2 * n - 1), V<>(n, -1));
    val.assign(__lg(2 * n - 1), V<>(n, e));
    auto dfs = [&](const auto& dfs, int v, int p) -> void {
      for (const auto& e : g[v]) if (e.to != p) {
        dep[e.to] = dep[v] + 1;
        par[0][e.to] = v;
        val[0][e.to] = e.w;
        dfs(dfs, e.to, v);
      }
    };
    dep[r] = 0;
    dfs(dfs, r, -1);
    for (int k = 1; k < par.size(); ++k) {
      for (int v = 0; v < n; ++v) {
        if (par[k - 1][v] == -1) continue;
        par[k][v] = par[k - 1][par[k - 1][v]];
        val[k][v] = op(val[k - 1][v], val[k - 1][par[k - 1][v]]);
      }
    }
  }
  int get_par(int v, int h) {
    for (int k = 0; h > 0; h >>= 1, ++k) {
      if (v == -1) break;
      if (h & 1) v = par[k][v];
    }
    return v;
  }
  int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    v = get_par(v, dep[v] - dep[u]);
    if (u == v) return u;
    for (int k = par.size() - 1; k >= 0; --k) {
      if (par[k][u] != par[k][v]) {
        u = par[k][u];
        v = par[k][v];
      }
    }
    return par[0][u];
  }
  T get_val(int v, int h) {
    T res = e;
    for (int k = 0; h > 0; h >>= 1, ++k) {
      if (v == -1) break;
      if (h & 1) {
        res = op(res, val[k][v]);
        v = par[k][v];
      }
    }
    return res;
  }
  T acc(int u, int v) {
    int a = lca(u, v);
    return op(get_val(v, dep[v] - dep[a]), get_val(u, dep[u] - dep[a]));
  }
}
using namespace LCA;

template<class T> struct FenwickTree {
  const int n;
  V<T> t;
  FenwickTree(int n) : n(n), t(n + 1) {}
  void add(int i, T x) { for (++i; i <= n; i += i & -i) t[i] += x; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  VV<Edge> g(n);
  for (int _ = 0; _ < n - 1; ++_) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].emplace_back(Edge{v, 1});
    g[v].emplace_back(Edge{u, 1});
  }
  init(g, 0);

  V<> vs;
  auto dfs = [&](const auto& dfs, int v, int p) -> void {
    vs.push_back(v);
    for (const auto& e : g[v]) if (e.to != p) {
      dfs(dfs, e.to, v);
      vs.push_back(v);
    }
  };
  dfs(dfs, 0, -1);
  assert(vs.size() == 2 * n - 1);
  V<> l(n, 1e9), r(n, -1e9);
  for (int i = 0; i < 2 * n - 1; ++i) {
    l[vs[i]] = min(l[vs[i]], i);
    r[vs[i]] = max(r[vs[i]], i + 1);
  }
  FenwickTree<int> ft(2 * n);

  while (q--) {
    int k, m, rt; cin >> k >> m >> rt, --rt;
    V<> a(k), d(k);
    for (int i = 0; i < k; ++i) {
      cin >> a[i], --a[i];
      d[i] = acc(rt, a[i]);
    }
    V<> idx(k);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int i, int j) { return d[i] < d[j]; });
    V<Mint> dp(m + 1);
    dp[0] = 1;
    for (int i : idx) {
      int y = ft.sum(l[a[i]] + 1);
      if (lca(rt, a[i]) != a[i]) {
        ft.add(l[a[i]], +1);
        ft.add(r[a[i]], -1);
      } else {
        ft.add(l[0], +1);
        ft.add(r[0], -1);
        if (a[i] != rt) {
          int v = get_par(rt, acc(rt, a[i]) - 1);
          ft.add(l[v], -1);
          ft.add(r[v], +1);
        }
      }
      V<Mint> ndp(m + 1);
      for (int x = 1; x <= m; ++x) {
        ndp[x] = dp[x - 1] + (x - y) * dp[x];
      }
      swap(dp, ndp);
    }
    Mint res = accumulate(begin(dp) + 1, end(dp), Mint(0));
    cout << res << '\n';
    for (int i : idx) {
      if (lca(rt, a[i]) != a[i]) {
        ft.add(l[a[i]], -1);
        ft.add(r[a[i]], +1);
      } else {
        ft.add(l[0], -1);
        ft.add(r[0], +1);
        if (a[i] != rt) {
          int v = get_par(rt, acc(rt, a[i]) - 1);
          ft.add(l[v], +1);
          ft.add(r[v], -1);
        }
      }
    }
  }
}