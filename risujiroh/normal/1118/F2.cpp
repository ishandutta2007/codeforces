#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }

template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  ModInt() : v(0) {}
  template<class Int> ModInt(Int x) : v(x >= 0 ? x % P : -x % P ? P - -x % P : 0) {}
  constexpr ModInt(unsigned v, int) : v(v) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool) *this; }
  M operator*(M rhs) const { return M(*this) *= rhs; }
  M operator/(M rhs) const { return M(*this) /= rhs; }
  M operator+(M rhs) const { return M(*this) += rhs; }
  M operator-(M rhs) const { return M(*this) -= rhs; }
  bool operator==(M rhs) const { return v == rhs.v; }
  bool operator!=(M rhs) const { return !(*this == rhs); }
  M& operator*=(M rhs) { v = (unsigned long long) v * rhs.v % P; return *this; }
  M& operator/=(M rhs) { return *this *= rhs.inv(); }
  M& operator+=(M rhs) { v = rhs.v < P - v ? v + rhs.v : v - (P - rhs.v); return *this; }
  M& operator-=(M rhs) { v = rhs.v <= v ? v - rhs.v : v + (P - rhs.v); return *this; }
  M inv() const {
    int a = v, b = P, x = 1, u = 0;
    while (b) {
      int q = a / b;
      swap(a -= q * b, b);
      swap(x -= q * u, u);
    }
    assert(a == 1);
    return x;
  }
  template<class Int> M pow(Int n) const {
    n = n >= 0 ? n % (P - 1) : P - 1 - -n % (P - 1);
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
  template<class Int> friend M operator*(Int lhs, M rhs) { return M(lhs) *= rhs; }
  template<class Int> friend M operator/(Int lhs, M rhs) { return M(lhs) /= rhs; }
  template<class Int> friend M operator+(Int lhs, M rhs) { return M(lhs) += rhs; }
  template<class Int> friend M operator-(Int lhs, M rhs) { return M(lhs) -= rhs; }
  friend ostream& operator<<(ostream& os, M rhs) { return os << rhs.v; }
  friend istream& operator>>(istream& is, M& rhs) { lint x; is >> x; rhs = x; return is; }
  template<class Int> friend bool operator==(Int lhs, M rhs) { return M(lhs) == rhs; }
  template<class Int> friend bool operator!=(Int lhs, M rhs) { return !(lhs == rhs); }
};
using Mint = ModInt<998244353>;

namespace LCA {
  V<> dep;
  VV<> par;

  void init(const VV<>& g, int r) {
    int n = g.size();
    dep.resize(n);
    assign(par, __lg(2 * n - 1), n, -1);
    auto dfs = [&](const auto& dfs, int v, int p) -> void {
      for (int w : g[v]) if (w != p) {
        dep[w] = dep[v] + 1;
        par[0][w] = v;
        dfs(dfs, w, v);
      }
    };
    dep[r] = 0;
    dfs(dfs, r, -1);
    for (int k = 1; k < par.size(); ++k) {
      for (int v = 0; v < n; ++v) {
        if (par[k - 1][v] == -1) continue;
        par[k][v] = par[k - 1][par[k - 1][v]];
      }
    }
  }

  int get_par(int v, int h) {
    for (int k = 0; h > 0; h >>= 1, ++k) {
      if (v == -1) break;
      if (h & 1) v = par[k][v];
    }
    return v;
  }

  int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    v = get_par(v, dep[v] - dep[u]);
    if (u == v) return u;
    for (int k = par.size() - 1; k >= 0; --k) {
      if (par[k][u] != par[k][v]) {
        u = par[k][u];
        v = par[k][v];
      }
    }
    return par[0][u];
  }
}
using namespace LCA;

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  VV<> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  VV<> vlist(n + 1);
  for (int v = 0; v < n; ++v) {
    vlist[a[v]].push_back(v);
  }

  init(g, 0);
  auto chk = [&]() -> bool {
    for (int c = 1; c <= n; ++c) if (vlist[c].size() > 1) {
      int m = vlist[c].size();
      int anc = vlist[c][0];
      for (int j = 1; j < m; ++j) {
        anc = lca(anc, vlist[c][j]);
      }
      for (int v : vlist[c]) if (v != anc) {
        v = par[0][v];
        while (true) {
          if (a[v] != 0 and a[v] != c) return false;
          if (a[v] == c) break;
          a[v] = c;
          if (v == anc) break;
          v = par[0][v];
        }
      }
    }
    return true;
  };
  if (!chk()) return cout << 0 << '\n', 0;

  VV<Mint> dp(n, V<Mint>(2));
  auto dfs = [&](const auto& dfs, int v, int p) -> void {
    for (int w : g[v]) if (w != p) {
      dfs(dfs, w, v);
    }
    if (a[v]) {
      dp[v][1] = 1;
      for (int w : g[v]) if (w != p) {
        dp[v][1] *= (dp[w][0] + dp[w][1]);
      }
    } else {
      dp[v][0] = 1;
      for (int w : g[v]) if (w != p) {
        dp[v][0] *= (dp[w][0] + dp[w][1]);
      }
      dp[v][1] = 0;
      for (int w : g[v]) if (w != p) {
        if (a[w]) {
          dp[v][1] += dp[v][0];
        } else if (dp[w][1]) {
          dp[v][1] += dp[v][0] / (dp[w][0] + dp[w][1]) * dp[w][1];
        }
      }
    }
  };
  dfs(dfs, 0, -1);
  cout << dp[0][1] << '\n';
}