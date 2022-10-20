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
  int n;
  cin >> n;
  string s;
  cin >> s;
  prepare(2 * n);
  vector nxt(n + 1, vector(26, n));
  for (int i = n; i--; ) {
    nxt[i] = nxt[i + 1];
    nxt[i][s[i] - 'a'] = i;
  }
  vector dp(n + 1, vector<mint>(n + 1));
  vector<mint> sum(n + 1);
  for (int i = n; i--; ) {
    for (int len = 1; len <= n - i; ++len) {
      sum[len] -= dp[nxt[i + 1][s[i] - 'a']][len];
    }
    dp[i][1] = 1;
    for (int len = 2; len <= n - i; ++len) {
      // for (int x = 0; x < 26; ++x) {
      //   if (s[i] - 'a' == x) continue;
      //   dp[i][len] += dp[nxt[i][x]][len - 1];
      // }
      dp[i][len] = sum[len - 1];
    }
    for (int len = 1; len <= n - i; ++len) {
      sum[len] += dp[i][len];
    }
  }
  mint res;
  for (int len = 1; len <= n; ++len) {
    mint num;
    for (int x = 0; x < 26; ++x) {
      num += dp[nxt[0][x]][len];
    }
    res += num * binom(n - 1, n - len);
  }
  cout << res.v << '\n';
}