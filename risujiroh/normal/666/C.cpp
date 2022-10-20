#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T, class Op = multiplies<T>>
constexpr T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  using m = modular;
  static constexpr unsigned mod = M;
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

using mint = modular<power(10, 9) + 7>;

vector<mint> fact, inv_fact, minv;
void prepare(int n) {
  fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? fact[i - 1] * i : 1;
  inv_fact[n] = power(fact[n], mint::mod - 2);
  for (int i = n; i--; ) inv_fact[i] = (i + 1) * inv_fact[i + 1];
  for (int i = 1; i <= n; ++i) minv[i] = inv_fact[i] * fact[i - 1];
}
mint binom(int n, int k) {
  if (k < 0 or k > n) return 0;
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
template <> mint& mint::operator/=(mint b) {
  return *this *= b.v < minv.size() ? minv[b.v] : power(b, mod - 2);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  prepare(1e5);
  int q;
  cin >> q;
  vector<pair<int, string>> p(q + 1);
  bool first = true;
  vector<int> a;
  for (auto&& [t, s] : p) {
    t = 1;
    if (not exchange(first, false)) {
      cin >> t;
    }
    cin >> s;
    if (t == 1) {
      a.push_back(size(s));
    }
  }
  sort(begin(a), end(a));
  a.erase(unique(begin(a), end(a)), end(a));
  constexpr int lim = 1e5;
  vector pre(size(a), vector<mint>(lim + 1));
  vector<mint> p25(lim + 1, 1);
  for (int i = 1; i <= lim; ++i) {
    p25[i] = p25[i - 1] * 25;
  }
  for (int i = 0; i < (int)size(a); ++i) {
    int m = a[i];
    pre[i][m] = 1;
    for (int n = m; n < lim; ++n) {
      pre[i][n + 1] = binom(n, m - 1) * p25[n - m + 1] + 26 * pre[i][n];
    }
  }
  int i = -1;
  for (auto&& [t, s] : p) {
    if (t == 1) {
      i = lower_bound(begin(a), end(a), size(s)) - begin(a);
    } else {
      cout << pre[i][stoi(s)].v << '\n';
    }
  }
}