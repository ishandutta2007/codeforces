#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  constexpr ModInt() : v(0) {}
  constexpr ModInt(unsigned _v, int) : v(_v) {}
  template<class Z> ModInt(const Z& a) : v((a < 0 ? P - -a % P : a) % P) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool)*this; }
  M& operator*=(M r) { v = (uint64_t)v * r.v % P; return *this; }
  M& operator/=(M r) { return *this *= r.inv(); }
  M& operator+=(M r) { if ((v += r.v) >= P) v -= P; return *this; }
  M& operator-=(M r) { if ((v += P - r.v) >= P) v -= P; return *this; }
  friend M operator*(M l, M r) { return M(l) *= r; }
  friend M operator/(M l, M r) { return M(l) /= r; }
  friend M operator+(M l, M r) { return M(l) += r; }
  friend M operator-(M l, M r) { return M(l) -= r; }
  friend ostream& operator<<(ostream& os, M r) { return os << r.v; }
  friend bool operator==(M l, M r) { return l.v == r.v; }
  friend bool operator!=(M l, M r) { return !(l == r); }
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
  template<class Z> M pow(Z n) const {
    if (n < 0) return pow(-n).inv();
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
};
using Mint = ModInt<(unsigned)1e9 + 7>;
constexpr int N = 1 << 20;
struct Fact {
  V<Mint> v;
  Fact(int n) : v(n + 1, 1) {
    for (int i = 1; i <= n; ++i) v[i] = i * v[i - 1];
  }
  Mint operator[](int i) const { return v[i]; }
} fact(N);
struct Finv {
  V<Mint> v;
  Finv(int n) : v(n + 1, 1 / fact[n]) {
    for (int i = n; i; --i) v[i - 1] = i * v[i];
  }
  Mint operator[](int i) const { return v[i]; }
} finv(N);
struct Minv {
  V<Mint> v;
  Minv(int n) : v(n) {
    for (int i = 1; i <= n; ++i) v[i - 1] = fact[i - 1] * finv[i];
  }
  Mint operator[](int i) const { return v[i - 1]; }
} minv(N);
Mint comb(int n, int r) {
  if (r < 0 or r > n) return 0;
  return fact[n] * finv[r] * finv[n - r];
}

struct UnionFind {
  const int n;
  V<> t; // root ? -sz : par
  UnionFind(int _n) : n(_n), t(n, -1) {}
  int find(int v) { return t[v] < 0 ? v : t[v] = find(t[v]); }
  void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (-t[u] < -t[v]) swap(u, v);
    t[u] += t[v];
    t[v] = u;
  }
  bool same(int u, int v) { return find(u) == find(v); }
  int size(int v) { return -t[find(v)]; }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> g(n), h(n);
  UnionFind uf(n);
  struct Edge { int u, v; };
  V<Edge> es;
  for (int _ = 0; _ < m; ++_) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    if (uf.same(u, v)) {
      es.emplace_back(Edge{u, v});
    } else {
      uf.unite(u, v);
      h[u].push_back(v);
      h[v].push_back(u);
    }
  }
  int k = es.size();
  V<> par(n), dep(n);
  auto dfs = [&](auto& F, int v, int p) -> void {
    par[v] = p;
    for (int u : h[v]) if (u != p) {
      dep[u] = dep[v] + 1;
      F(F, u, v);
    }
  };
  dfs(dfs, 0, -1);
  auto fn = [&](int u, int v) -> V<> {
    V<> res;
    while (u != v) {
      if (dep[u] > dep[v]) {
        res.push_back(u);
        u = par[u];
      } else {
        res.push_back(v);
        v = par[v];
      }
    }
    res.push_back(u);
    return res;
  };
  V<> l(k);
  VV<> ids(n), vs(k);
  for (int id = 0; id < k; ++id) {
    vs[id] = fn(es[id].u, es[id].v);
    l[id] = vs[id].size();
    for (int v : vs[id]) {
      ids[v].push_back(id);
    }
  }
  Mint ex;
  ex += n * minv[2];
  ex -= m * minv[4];
  for (int e : l) {
    ex += Mint(2).pow(-e);
  }
  Mint ex2;
  ex2 += (lint)n * (n + 1) * minv[4];
  ex2 += m * minv[4];
  ex2 += (lint)m * (m - 1) * minv[16];
  for (int v = 0; v < n; ++v) {
    lint d = g[v].size();
    ex2 += d * (d - 1) * minv[16];
  }
  Mint sz, sz2;
  for (int e : l) {
    sz += Mint(2).pow(-e);
    sz2 += Mint(2).pow(-2 * e);
  }
  ex2 += sz + (sz * sz - sz2);
  for (int v = 0; v < n; ++v) {
    Mint s, s2;
    for (int id : ids[v]) {
      s += Mint(2).pow(-l[id]);
      s2 += Mint(2).pow(-2 * l[id]);
    }
    ex2 += s * s - s2;
  }

  ex2 -= 2 * (lint)n * m * minv[8];
  for (int v = 0; v < n; ++v) {
    ex2 -= 2 * g[v].size() * minv[8];
  }

  ex2 += 2 * n * minv[2] * sz;
  for (int v = 0; v < n; ++v) {
    for (int id : ids[v]) {
      ex2 += 2 * Mint(2).pow(-l[id]) * minv[2];
    }
  }

  ex2 -= 2 * m * minv[4] * sz;
  for (int id = 0; id < k; ++id) {
    ex2 -= 2 * l[id] * 3 * Mint(2).pow(-l[id]) * minv[4];
    lint sd = 0;
    for (int v : vs[id]) {
      sd += g[v].size() - 2;
    }
    ex2 -= 2 * sd * Mint(2).pow(-l[id]) * minv[4];
  }
  cout << ex2 - ex * ex << '\n';
}