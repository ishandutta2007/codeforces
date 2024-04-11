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

using mat = array<array<mint, 2>, 2>;

mat operator*(const mat& a, const mat& b) {
  mat c;
  for (int i : {0, 1}) {
    for (int k : {0, 1}) {
      for (int j : {0, 1}) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return c;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int k;
  cin >> k;
  using ll = long long;
  mat m{1, 2, 1, 0};
  mint den = 2;
  while (k--) {
    ll a;
    cin >> a;
    m = power(m, a, multiplies<>(), {1, 0, 0, 1});
    den = power(den, a);
  }
  mint num = m[1][1] / 2;
  den /= 2;
  cout << num.v << '/' << den.v << '\n';
}