#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

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
  m& operator+=(m b) { if ((int)(v += b.v - mod) < 0) v += mod; return *this; }
  m& operator-=(m b) { if ((int)(v -= b.v) < 0) v += mod; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return *this; }
  m& operator/=(m b) { return *this *= power(b, mod - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
};

using mint = modular<998244353>;

void fwht(vector<mint>& a, bool inverse) {
  int n = __lg(a.size());
  assert((int)a.size() == 1 << n);
  for (int i = 0; i < n; ++i)
    for (int bt = 0; bt < 1 << n; ++bt)
      if (bt >> i & 1) {
        mint x = a[bt ^ 1 << i], y = a[bt];
        a[bt ^ 1 << i] = x + y, a[bt] = x - y;
      }
  if (inverse) {
    auto inv = 1 / mint(1 << n);
    for (auto&& e : a) e *= inv;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  vector<long long> v;
  auto add = [&](auto x) {
    for (auto e : v) {
      x = min(x, x ^ e);
    }
    if (x) {
      v.push_back(x);
    }
  };
  for (auto e : a) {
    add(e);
  }
  sort(rbegin(v), rend(v));
  DEBUG(v);
  int k = v.size(), p = 0;
  while (p < k and v[p] >= 1 << 18) {
    ++p;
  }
  DEBUG(p);
  vector cnt(18, vector<mint>(1 << 18));
  for (int bt = 0; bt < 1 << p; ++bt) {
    long long xr = 0;
    for (int i = 0; i < p; ++i) {
      if (bt >> i & 1) {
        xr ^= v[i];
      }
    }
    cnt[__builtin_popcountll(xr >> 18)][xr & ~(-1u << 18)] += 1;
  }
  vector<mint> c(1 << 18);
  for (int bt = 0; bt < 1 << (k - p); ++bt) {
    int xr = 0;
    for (int i = 0; i < k - p; ++i) {
      if (bt >> i & 1) {
        xr ^= v[p + i];
      }
    }
    DEBUG(xr);
    c[xr] += 1;
  }
  if (false) {
    cnt[0].resize(16);
    c.resize(16);
    DEBUG(cnt[0]);
    DEBUG(c);
    fwht(cnt[0], false);
    fwht(c, false);
    DEBUG(cnt[0]);
    DEBUG(c);
    for (int i = 0; i < 16; ++i) {
      cnt[0][i] *= c[i];
    }
    DEBUG(cnt[0]);
    fwht(cnt[0], true);
    DEBUG(cnt[0]);
    exit(0);
  }
  fwht(c, false);
  vector<mint> res(36);
  for (int pc = 0; pc <= 17; ++pc) {
    fwht(cnt[pc], false);
    for (int bt = 0; bt < 1 << 18; ++bt) {
      cnt[pc][bt] *= c[bt];
    }
    fwht(cnt[pc], true);
    for (int bt = 0; bt < 1 << 18; ++bt) {
      res[pc + __builtin_popcount(bt)] += cnt[pc][bt];
    }
  }
  DEBUG(res);
  for (int i = 0; i <= m; ++i) {
    res[i] *= power<mint>(2, n - k);
    cout << res[i].v << " \n"[i == m];
  }
}