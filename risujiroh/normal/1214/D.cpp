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

int h, w;
vector<string> s;

template <unsigned M> int solve() {
  using mint = modular<M>;
  vector f(h, vector<mint>(w));
  f[0][0] = 1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '#') continue;
      if (i + 1 < h) {
        f[i + 1][j] += f[i][j];
      }
      if (j + 1 < w) {
        f[i][j + 1] += f[i][j];
      }
    }
  }
  if (f[h - 1][w - 1] == 0) {
    return 0;
  }
  vector g(h, vector<mint>(w));
  g[h - 1][w - 1] = 1;
  for (int i = h; i--; ) {
    for (int j = w; j--; ) {
      if (s[i][j] == '#') continue;
      if (i) {
        g[i - 1][j] += g[i][j];
      }
      if (j) {
        g[i][j - 1] += g[i][j];
      }
      if (i == 0 and j == 0) continue;
      if (i == h - 1 and j == w - 1) continue;
      if (f[i][j] * g[i][j] == f[h - 1][w - 1]) {
        return 1;
      }
    }
  }
  return 2;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> h >> w;
  s.resize(h);
  for (auto&& e : s) cin >> e;
  vector<int> cnt(3);
  ++cnt[solve<119 << 23 | 1>()];
  ++cnt[solve<155 << 23 | 1>()];
  ++cnt[solve<177 << 23 | 1>()];
  cout << max_element(begin(cnt), end(cnt)) - begin(cnt) << '\n';
}