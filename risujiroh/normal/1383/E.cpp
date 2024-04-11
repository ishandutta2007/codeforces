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
  string s;
  cin >> s;
  int l = 0;
  while (s[l] == '0') {
    ++l;
  }
  if (s[l] != '1') {
    cout << l << '\n';
    exit(0);
  }
  mint coeff = l + 1;
  int r = size(s);
  while (s[r - 1] == '0') {
    --r;
  }
  coeff *= size(s) - r + 1;
  s = s.substr(l, r - l);
  int n = size(s);
  vector<array<int, 2>> nxt(n + 1);
  nxt[n].fill(n);
  for (int i = n; i--; ) {
    nxt[i] = nxt[i + 1];
    nxt[i][s[i] - '0'] = i;
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') continue;
    a[i] = a[i - 1] + 1;
  }
  vector<int> to(n, n), stk;
  for (int i = n; i--; ) {
    while (not empty(stk) and not (a[i] < a[stk.back()])) {
      stk.pop_back();
    }
    if (not empty(stk)) {
      to[i] = stk.back();
    }
    stk.push_back(i);
  }
  vector<mint> dp(n + 1);
  dp[0] = 1;
  mint res;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      dp[to[i]] += dp[i];
      dp[nxt[i + 1][1]] += dp[i];
    } else {
      dp[nxt[i + 1][0]] += dp[i];
      dp[nxt[i + 1][1]] += dp[i];
      res += dp[i];
    }
  }
  res *= coeff;
  cout << res.v << '\n';
}