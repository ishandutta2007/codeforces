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

using Mint = ModInt<998244353>;

V<Mint> fact, ifact;
void init(int n) {
  assert(n >= 0);
  fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = Mint(i) * fact[i - 1];
  }
  ifact.resize(n + 1);
  ifact[n] = fact[n].inv();
  for (int i = n; i > 0; --i) {
    ifact[i - 1] = Mint(i) * ifact[i];
  }
}

Mint comb(int n, int r) {
  if (r < 0 or r > n) return 0;
  assert(n < (int) fact.size());
  return fact[n] * ifact[r] * ifact[n - r];
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  init(n);
  Mint res = comb(n - 1, k) * Mint(m) * Mint(m - 1).pow(k);
  cout << res << '\n';
}