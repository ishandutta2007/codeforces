#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


template<class Int> constexpr bool is_prime(Int n) {
  if (n < 2 or n > 2 and ~n & 1) return false;
  for (Int i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
  return true;
}
template<uint P> struct ModInt {
  static_assert(is_prime(P), "template argument must be a prime number");
  using M = ModInt;
  uint v;
  ModInt() : v(0) {}
  template<class Int> ModInt(Int x) : v(x >= 0 ? x % P : -x % P ? P - -x % P : 0) {}
  ModInt(uint v, int _) : v(v) {} // 
  static constexpr uint p() { return P; }
  M operator++(int) { M t = *this; if (++v == P) v = 0; return t; }
  M operator--(int) { M t = *this; v = (v ? v : P) - 1; return t; }
  M& operator++() { if (++v == P) v = 0; return *this; }
  M& operator--() { v = (v ? v : P) - 1; return *this; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  M& operator*=(M rhs) { v = (ulint) v * rhs.v % P; return *this; }
  M& operator/=(M rhs) { return *this *= rhs.inv(); }
  M& operator+=(M rhs) { v = rhs.v < P - v ? v + rhs.v : v - (P - rhs.v); return *this; }
  M& operator-=(M rhs) { v = rhs.v <= v ? v - rhs.v : v + (P - rhs.v); return *this; }
  M inv() const {
    assert(v);
    #ifdef __linux__ // ACCF
      return pow(P - 2);
    #else
      int a = v, b = P, x = 1, u = 0;
      while (b) {
        int q = a / b;
        swap(a -= q * b, b);
        swap(x -= q * u, u);
      }
      return x;
    #endif
  }
  template<class Int> M pow(Int n) const {
    n = n >= 0 ? n % (P - 1) : P - 1 - -n % (P - 1);
    M res = 1;
    for (M a = *this; n > 0; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
};
namespace std {
  template<uint P> using M = ModInt<P>;
  template<uint P> M<P> operator*(M<P> lhs, M<P> rhs) { return lhs *= rhs; }
  template<uint P> M<P> operator/(M<P> lhs, M<P> rhs) { return lhs /= rhs; }
  template<uint P> M<P> operator+(M<P> lhs, M<P> rhs) { return lhs += rhs; }
  template<uint P> M<P> operator-(M<P> lhs, M<P> rhs) { return lhs -= rhs; }
  template<uint P> ostream& operator<<(ostream& os, M<P> rhs) { return os << rhs.v; }
  template<uint P> istream& operator>>(istream& is, M<P>& rhs) { lint x; is >> x; rhs = x; return is; }
  template<uint P> bool operator==(M<P> lhs, M<P> rhs) { return lhs.v == rhs.v; }
  template<uint P> bool operator!=(M<P> lhs, M<P> rhs) { return !(lhs == rhs); }
}

using Mint = ModInt<998'244'353>;

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int t; cin >> t;
  for (int _ = 0; _ < t; ++_) {
    int n, m; cin >> n >> m;
    VV<> g(n);
    V<> col(n);
    int c = 0, cn;
    auto dfs = [&](const auto& dfs, int v) -> bool {
      for (int w : g[v]) if (!col[w]) {
        col[w] = -col[v];
        ++c;
        cn += col[w] == -1;
        if (!dfs(dfs, w)) return false;
      } else if (col[w] == col[v]) return false;
      return true;
    };
    for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v, --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    bool bi = true;
    Mint res = 1;
    int r = n;
    for (int v = 0; v < n; ++v) if (!col[v]) {
      int s = c;
      col[v] = 1;
      ++c;
      cn = 0;
      if (!dfs(dfs, v)) bi = false;
      res *= Mint(2).pow(cn) + Mint(2).pow(c - s - cn);
    }
    if (!bi) cout << 0 << '\n';
    else cout << res << '\n';
  }
}