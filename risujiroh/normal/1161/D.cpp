#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  ModInt() : v(0) {}
  ModInt(auto x) : v(x >= 0 ? x % P : (P - -x % P) % P) {}
  constexpr ModInt(unsigned v, int) : v(v) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool) *this; }
  M operator*(M r) const { return M(*this) *= r; }
  M operator/(M r) const { return M(*this) /= r; }
  M operator+(M r) const { return M(*this) += r; }
  M operator-(M r) const { return M(*this) -= r; }
  bool operator==(M r) const { return v == r.v; }
  bool operator!=(M r) const { return !(*this == r); }
  M& operator*=(M r) { v = (uint64_t) v * r.v % P; return *this; }
  M& operator/=(M r) { return *this *= r.inv(); }
  M& operator+=(M r) { if ((v += r.v) >= P) v -= P; return *this; }
  M& operator-=(M r) { if ((v += P - r.v) >= P) v -= P; return *this; }
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
  M pow(auto n) const {
    if (n < 0) return pow(-n).inv();
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
  friend M operator*(auto l, M r) { return M(l) *= r; }
  friend M operator/(auto l, M r) { return M(l) /= r; }
  friend M operator+(auto l, M r) { return M(l) += r; }
  friend M operator-(auto l, M r) { return M(l) -= r; }
  friend ostream& operator<<(ostream& os, M r) { return os << r.v; }
  friend istream& operator>>(istream& is, M& r) { lint x; is >> x; r = x; return is; }
  friend bool operator==(auto l, M r) { return M(l) == r; }
  friend bool operator!=(auto l, M r) { return !(l == r); }
};
using Mint = ModInt<998244353>;

struct WeightedUnionFind {
  using T = bool;
  static T op(const T& x, const T& y) { return x ^ y; }
  static constexpr T e() { return false; }
  static T inv(const T& x) { return x; }
  static T sub(const T& x, const T& y) { return op(x, inv(y)); }

  const int n;
  V<> t; // root ? -sz : par
  V<T> pot;
  WeightedUnionFind(int n) : n(n), t(n, -1), pot(n, e()) {}
  int find(int v) {
    if (t[v] < 0) return v;
    int r = find(t[v]);
    pot[v] = op(pot[v], pot[t[v]]);
    return t[v] = r;
  }
  void unite(int u, int v, T d) {
    bool _same = same(u, v);
    assert(!_same);
    d = sub(d, sub(pot[v], pot[u]));
    if (t[u] >= 0) u = t[u];
    if (t[v] >= 0) v = t[v];
    if (-t[u] < -t[v]) {
      t[v] += t[u];
      t[u] = v;
      pot[u] = inv(d);
    } else {
      t[u] += t[v];
      t[v] = u;
      pot[v] = d;
    }
  }
  T diff(int u, int v) {
    bool _same = same(u, v);
    assert(_same);
    return sub(pot[v], pot[u]);
  }
  bool same(int u, int v) { return find(u) == find(v); }
  int size(int v) { return -t[find(v)]; }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  auto fn = [&](int k) -> Mint {
    WeightedUnionFind uf(n + k + 1);
    uf.unite(0, n + k, false);
    uf.unite(n, n + k, false);
    for (int i = 0; i < n; ++i) {
      if (uf.same(i, n + ~i) and uf.diff(i, n + ~i)) return 0;
      if (!uf.same(i, n + ~i)) uf.unite(i, n + ~i, false);
    }
    for (int i = 0; i < k; ++i) {
      if (uf.same(n + i, n + k + ~i) and uf.diff(n + i, n + k + ~i)) return 0;
      if (!uf.same(n + i, n + k + ~i)) uf.unite(n + i, n + k + ~i, false);
    }
    for (int i = 0; i < n - k; ++i) if (s[i] != '?') {
      if (s[i] == '0') {
        if (uf.same(i, n + k) and !uf.diff(i, n + k)) return 0;
        if (!uf.same(i, n + k)) uf.unite(i, n + k, true);
      } else {
        if (uf.same(i, n + k) and uf.diff(i, n + k)) return 0;
        if (!uf.same(i, n + k)) uf.unite(i, n + k, false);
      }
    }
    for (int i = n - k; i < n; ++i) if (s[i] != '?') {
      if (s[i] == '0') {
        if (uf.same(i, k + i) and uf.diff(i, k + i)) return 0;
        if (!uf.same(i, k + i)) uf.unite(i, k + i, false);
      } else {
        if (uf.same(i, k + i) and !uf.diff(i, k + i)) return 0;
        if (!uf.same(i, k + i)) uf.unite(i, k + i, true);
      }
    }
    set<int> se;
    for (int i = 0; i <= n + k; ++i) {
      se.insert(uf.find(i));
    }
    return Mint(2).pow((int)se.size() - 1);
  };
  Mint res;
  for (int k = 1; k < n; ++k) {
    res += fn(k);
  }
  cout << res << '\n';
}