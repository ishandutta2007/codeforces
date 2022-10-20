#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  while (size(t) < size(s)) {
    t += '*';
  }
  int n = s.size();
  vector dp(n + 1, vector<mint>(n + 1));
  for (int i = 0; i <= n; ++i) {
    dp[i][i] = 1;
  }
  for (int w = 0; w < n; ++w) {
    for (int l = 0; l + w <= n; ++l) {
      int r = l + w;
      if (l and (t[l - 1] == '*' or t[l - 1] == s[w])) {
        dp[l - 1][r] += dp[l][r];
      }
      if (r < n and (t[r] == '*' or t[r] == s[w])) {
        dp[l][r + 1] += dp[l][r];
      }
    }
  }
  mint res;
  for (int r = 0; r <= n; ++r) {
    if (r == n or t[r] == '*') {
      res += dp[0][r];
    }
  }
  cout << res.v << '\n';
}