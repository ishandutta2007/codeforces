#include <bits/stdc++.h>
using namespace std;

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = Op(), T e = {1}) {
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

constexpr long long mod = 1e9 + 7;
using mint = modular<mod>;

vector<mint> fact, inv_fact, minv;
void prepare(int n) {
  fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? i * fact[i - 1] : 1;
  inv_fact[n] = power(fact[n], mod - 2);
  for (int i = n; i; --i) inv_fact[i - 1] = inv_fact[i] * i;
  for (int i = 1; i <= n; ++i) minv[i] = fact[i - 1] * inv_fact[i];
}
mint binom(int n, int k) {
  if (k < 0 or k > n) return 0;
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
template<> mint& mint::operator/=(mint r) {
  return *this *= r.v < minv.size() ? minv[r.v] : power(r, mod - 2);
}

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
  prepare(n);
  auto mrg = [&](auto&& a, auto&& b, int na, int nb) {
    assert((int)a.size() == na);
    assert((int)b.size() == nb);
    int nc = na + nb;
    vector c(nc, vector<mint>(nc));
    for (int ia = 0; ia < na; ++ia) {
      for (int ja = 0; ja <= ia; ++ja) {
        for (int ib = 0; ib < nb; ++ib) {
          for (int jb = 0; jb <= ib; ++jb) {
            c[ia + ib][ja] += a[ia][ja] * b[ib][jb];
            c[ia + ib + 1][ja + jb + 1] += (a[ia][ja] / (ja + 1)) * (b[ib][jb] / (jb + 1)) * (ja + jb + 2);
          }
        }
      }
    }
    return c;
  };
  vector<int> sz(n);
  vector<vector<vector<mint>>> dp(n);
  auto dfs = [&](auto&& self, int v, int p) -> void {
    sz[v] = 1;
    dp[v] = {{1}};
    for (int u : g[v]) {
      if (u != p) {
        self(self, u, v);
        dp[v] = mrg(dp[v], dp[u], sz[v], sz[u]);
        sz[v] += sz[u];
      }
    }
  };
  dfs(dfs, 0, -1);
  vector<mint> a(n, 1);
  for (int k = 0; k < n - 1; ++k) {
    a[k] = accumulate(begin(dp[0][k]), end(dp[0][k]), mint(0));
    a[k] *= power(mint(n), n - k - 2);
  }
  for (int k = 0; k < n; ++k) {
    mint res;
    for (int i = k; i < n; ++i) {
      res += power(-1, i - k) * binom(i, k) * a[i];
    }
    cout << res.v << " \n"[k == n - 1];
  }
}