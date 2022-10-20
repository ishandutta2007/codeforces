#include <bits/stdc++.h>
using namespace std;

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = multiplies<T>(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  using m = modular;
  unsigned v;
  modular(long long x = 0) : v((x %= M) < 0 ? x + M : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((v += b.v) >= M) v -= M; return *this; }
  m& operator-=(m b) { if (v < b.v) v += M; v -= b.v; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % M; return *this; }
  m& operator/=(m b) { return *this *= power(b, M - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
  friend string to_string(m a) { return to_string(a.v); }
};

constexpr long long mod = 998244353;
using mint = modular<mod>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int _ = n - 1; _--; ) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto mrg = [](auto&& a, auto&& b) {
    array<mint, 3> res;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k : {0, 1}) {
          int ni = i;
          if (i == 1 and k) {
            ni = 2;
          }
          if (i and j and k) {
            continue;
          }
          if (j == 1 and k == 0) {
            continue;
          }
          res[ni] += a[i] * b[j];
        }
      }
    }
    return res;
  };
  vector<array<mint, 3>> dp(n);
  auto dfs = [&](auto&& self, int v, int p) -> void {
    dp[v] = {1, 1, 0};
    for (int u : g[v]) {
      if (u != p) {
        self(self, u, v);
        dp[v] = mrg(dp[v], dp[u]);
      }
    }
  };
  dfs(dfs, 0, -1);
  auto res = dp[0][0] + dp[0][2] - 1;
  cout << res.v << '\n';
}