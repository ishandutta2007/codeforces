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

using mint = modular<998244353>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> c(n);
  for (auto&& e : c) cin >> e;
  sort(rbegin(c), rend(c));
  c.push_back(0);
  for (int i = n; i--; ) {
    c[i] += c[i + 1];
  }
  for (int k = 1; k <= n; ++k) {
    mint res;
    for (int i = 0; i * k < n; ++i) {
      res += i * (c[i * k] - c[min(i * k + k, n)]);
    }
    res /= n;
    cout << res.v << " \n"[k == n];
  }
}