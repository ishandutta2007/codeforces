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
using Mint = ModInt<998244353>;

template<class T> struct FenwickTree {
  const int n;
  V<T> t;
  FenwickTree(int _n) : n(_n), t(n + 1) {}
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
  VV<> g(n);
  for (int _ = 0; _ < n - 1; ++_) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  V<> sz(n);
  {
    auto dfs = [&](auto& F, int v, int p) -> void {
      sz[v] = 1;
      for (int u : g[v]) if (u != p) {
        F(F, u, v);
        sz[v] += sz[u];
      }
      sort(begin(g[v]), end(g[v]), [&](int l, int r) {
        return (l != p ? sz[l] : n) < (r != p ? sz[r] : n);
      });
      if (not g[v].empty() and g[v].back() == p) {
        g[v].pop_back();
      }
    };
    dfs(dfs, 0, -1);
  }
  V<> in(n), out(n);
  VV<> ls(n), rs(n), ss(n);
  {
    int t = 0;
    auto dfs = [&](auto& F, int v) -> void {
      in[v] = t++;
      for (int u : g[v]) {
        F(F, u);
      }
      int m = g[v].size();
      for (int i = 0; i < m; ++i) {
        if (i == 0 or sz[g[v][i - 1]] != sz[g[v][i]]) {
          ls[v].push_back(in[g[v][i]]);
          ss[v].push_back(sz[g[v][i]]);
        }
        if (i == m - 1 or sz[g[v][i]] != sz[g[v][i + 1]]) {
          rs[v].push_back(out[g[v][i]]);
        }
      }
      out[v] = t;
    };
    dfs(dfs, 0);
  }
  FenwickTree<Mint> ft(n + 1);
  auto sub = [&](int l, int r, Mint x) -> void {
    if (l == r) return;
    ft.add(l, -x);
    ft.add(r, x);
  };
  Mint inv = Mint(n).inv(), offset = 0;
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int v; Mint d; cin >> v >> d.v, --v;
      offset += d;
      d *= inv;
      sub(0, in[v], d * (n - sz[v]));
      sub(out[v], n, d * (n - sz[v]));
      for (int i = 0; i < (int)ls[v].size(); ++i) {
        sub(ls[v][i], rs[v][i], d * ss[v][i]);
      }
    } else {
      int v; cin >> v, --v;
      cout << offset + ft.sum(in[v] + 1) << '\n';
    }
  }
}