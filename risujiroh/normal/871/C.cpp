#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

struct dsu {
  int cc;
  vector<int> p, sz, num;
  dsu(int n = 0) : cc(n), p(n, -1), sz(n, 1), num(n) {}
  int root(int v) const {
    while (p[v] != -1) v = p[v];
    return v;
  }
  bool unite(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return false;
    --cc;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    num[u] += num[v];
    return true;
  }
  bool same(int u, int v) const { return root(u) == root(v); }
  int size(int v) const { return sz[root(v)]; }
};

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  static constexpr unsigned mod = M;
  using m = modular;
  unsigned v;
  modular(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((v += b.v) >= mod) v -= mod; return *this; }
  m& operator-=(m b) { if (v < b.v) v += mod; v -= b.v; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return *this; }
  m& operator/=(m b) { return *this *= power(b, mod - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
};

using mint = modular<(int)1e9 + 7>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  auto vx = x;
  sort(begin(vx), end(vx));
  vx.erase(unique(begin(vx), end(vx)), end(vx));
  auto vy = y;
  sort(begin(vy), end(vy));
  vy.erase(unique(begin(vy), end(vy)), end(vy));
  int h = size(vx), w = size(vy);
  dsu d(h + w);
  for (int i = 0; i < n; ++i) {
    int p = lower_bound(begin(vx), end(vx), x[i]) - begin(vx);
    int q = lower_bound(begin(vy), end(vy), y[i]) - begin(vy);
    d.unite(p, h + q);
    ++d.num[d.root(p)];
  }
  mint res = 1;
  for (int v = 0; v < h + w; ++v) {
    if (d.root(v) != v) {
      continue;
    }
    assert(d.num[v] >= d.sz[v] - 1);
    if (d.num[v] == d.sz[v] - 1) {
      res *= power<mint>(2, d.sz[v]) - 1;
    } else {
      res *= power<mint>(2, d.sz[v]);
    }
  }
  cout << res.v << '\n';
}