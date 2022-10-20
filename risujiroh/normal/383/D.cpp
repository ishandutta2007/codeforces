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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  constexpr int off = 1e4;
  int n;
  cin >> n;
  mint res;
  vector<mint> f(2 * off + 1);
  while (n--) {
    int a;
    cin >> a;
    f[off] += 1;
    vector<mint> nf(2 * off + 1);
    for (int i = -off; i <= off; ++i) {
      if (i + a <= off) {
        nf[off + i + a] += f[off + i];
      }
      if (i - a >= -off) {
        nf[off + i - a] += f[off + i];
      }
    }
    swap(f, nf);
    res += f[off];
  }
  cout << res.v << '\n';
}