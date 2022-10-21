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
  int h, w, n, s;
  cin >> h >> w >> n >> s;
  vector<int> r(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i] >> c[i];
  }
  prepare(h + w + n);
  auto way = [&](int di, int dj) {
    return binom(di + dj, di);
  };
  {
    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) {
      return make_pair(r[i], c[i]) < make_pair(r[j], c[j]);
    });
    vector<int> nr(n), nc(n);
    for (int t = 0; t < n; ++t) {
      nr[t] = r[ord[t]];
      nc[t] = c[ord[t]];
    }
    swap(r, nr);
    swap(c, nc);
  }
  vector dp(n, vector(2, vector(21, mint())));
  for (int i = 0; i < n; ++i) {
    dp[i][1][0] += way(r[i] - 1, c[i] - 1);
    dp[i][1][1] += way(r[i] - 1, c[i] - 1);
    for (int p : {0, 1}) {
      for (int k = 0; k <= 20; ++k) {
        for (int j = i + 1; j < n; ++j) {
          dp[j][p ^ 1][k] += dp[i][p][k] * way(r[j] - r[i], c[j] - c[i]);
          if (k < 20) {
            dp[j][p ^ 1][k + 1] += dp[i][p][k] * way(r[j] - r[i], c[j] - c[i]);
          }
        }
      }
    }
  }
  vector f(2, vector(21, mint()));
  f[0][0] = way(h - 1, w - 1);
  for (int i = 0; i < n; ++i) {
    for (int p : {0, 1}) {
      for (int k = 0; k <= 20; ++k) {
        f[p][k] += dp[i][p][k] * way(h - r[i], w - c[i]);
      }
    }
  }
  vector<mint> coeff(21);
  for (int k = 0; k <= 20; ++k) {
    coeff[k] = power(-1, k) * (f[0][k] - f[1][k]);
  }
  mint rest = way(h - 1, w - 1) - accumulate(begin(coeff), end(coeff), mint());
  mint res;
  for (int k = 0; k <= 20; ++k) {
    res += coeff[k] * s;
    s = (s + 1) / 2;
  }
  res += rest * s;
  res /= way(h - 1, w - 1);
  cout << res.v << '\n';
}