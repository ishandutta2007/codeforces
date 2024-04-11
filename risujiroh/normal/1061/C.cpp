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
  constexpr ModInt() : v(0) {}
  template<class Int> constexpr ModInt(Int x) : v(x >= 0 ? x % P : -x % P ? P - -x % P : 0) {}
  constexpr ModInt(uint v, int dum) : v(v) {}
  static constexpr uint p() { return P; }
  constexpr M operator++(int) { M t = *this; if (++v == P) v = 0; return t; }
  constexpr M operator--(int) { M t = *this; v = (v ? v : P) - 1; return t; }
  constexpr M& operator++() { if (++v == P) v = 0; return *this; }
  constexpr M& operator--() { v = (v ? v : P) - 1; return *this; }
  constexpr M operator+() const { return *this; }
  constexpr M operator-() const { return {v ? P - v : 0, 0}; }
  template<class T> constexpr operator T() const noexcept { return v; }
  constexpr M& operator*=(const M& rhs) { v = (ulint) v * rhs.v % P; return *this; }
  constexpr M& operator/=(const M& rhs) { return *this *= rhs.inv(); }
  constexpr M& operator+=(const M& rhs) { v = rhs.v < P - v ? v + rhs.v : v - (P - rhs.v); return *this; }
  constexpr M& operator-=(const M& rhs) { v = rhs.v <= v ? v - rhs.v : v + (P - rhs.v); return *this; }
  constexpr M inv() const {
    assert(v);
    #ifdef __linux__ // ACCF
      return pow(P - 2);
    #else
      int a = v, b = P, x = 1, u = 0;
      while (b) {
        int q = a / b, t = 0;
        t = a - q * b, a = b, b = t;
        t = x - q * u, x = u, u = t;
      }
      return x;
    #endif
  }
  template<class Int> constexpr M pow(Int n) const {
    n = n >= 0 ? n % (P - 1) : P - 1 - -n % (P - 1);
    M res = 1;
    for (M a = *this; n > 0; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
};
namespace std {
  template<uint P> using M = ModInt<P>;
  template<uint P> constexpr M<P> operator*(const M<P>& lhs, const M<P>& rhs) { return M<P>(lhs) *= rhs; }
  template<uint P, class Int> constexpr M<P> operator*(const M<P>& lhs, Int x) { return M<P>(lhs) *= x; }
  template<class Int, uint P> constexpr M<P> operator*(Int x, const M<P>& rhs) { return M<P>(x) *= rhs; }
  template<uint P> constexpr M<P> operator/(const M<P>& lhs, const M<P>& rhs) { return M<P>(lhs) /= rhs; }
  template<uint P, class Int> constexpr M<P> operator/(const M<P>& lhs, Int x) { return M<P>(lhs) /= x; }
  template<class Int, uint P> constexpr M<P> operator/(Int x, const M<P>& rhs) { return M<P>(x) /= rhs; }
  template<uint P> constexpr M<P> operator+(const M<P>& lhs, const M<P>& rhs) { return M<P>(lhs) += rhs; }
  template<uint P, class Int> constexpr M<P> operator+(const M<P>& lhs, Int x) { return M<P>(lhs) += x; }
  template<class Int, uint P> constexpr M<P> operator+(Int x, const M<P>& rhs) { return M<P>(x) += rhs; }
  template<uint P> constexpr M<P> operator-(const M<P>& lhs, const M<P>& rhs) { return M<P>(lhs) -= rhs; }
  template<uint P, class Int> constexpr M<P> operator-(const M<P>& lhs, Int x) { return M<P>(lhs) -= x; }
  template<class Int, uint P> constexpr M<P> operator-(Int x, const M<P>& rhs) { return M<P>(x) -= rhs; }
  template<uint P> ostream& operator<<(ostream& os, const M<P>& rhs) { return os << rhs.v; }
  template<uint P> istream& operator>>(istream& is, M<P>& rhs) { lint x; is >> x; rhs = x; return is; }
  template<uint P> constexpr bool operator==(const M<P>& lhs, const M<P>& rhs) { return lhs.v == rhs.v; }
  template<uint P, class Int> constexpr bool operator==(const M<P>& lhs, Int x) { return lhs == M<P>(x); }
  template<class Int, uint P> constexpr bool operator==(Int x, const M<P>& rhs) { return M<P>(x) == rhs; }
  template<uint P> constexpr bool operator!=(const M<P>& lhs, const M<P>& rhs) { return !(lhs == rhs); }
  template<uint P, class Int> constexpr bool operator!=(const M<P>& lhs, Int x) { return !(lhs == x); }
  template<class Int, uint P> constexpr bool operator!=(Int x, const M<P>& rhs) { return !(x == rhs); }
}

using Mint = ModInt<1'000'000'007>;

template<uint N> struct Factor {
  int val[N + 1];
  constexpr Factor() : val() {
    for (int i = 4; i <= N; i += 2) val[i] = 2;
    for (int i = 3; i * i <= N; i += 2) {
      for (int j = i * i; j <= N; j += 2 * i) if(!val[j]) val[j] = i;
    }
  }
  constexpr int operator[](int i) const { return val[i]; }
};
constexpr Factor<1'000'000> factor;

constexpr bool is_prime(int n) { return !factor[n]; }

map<int, int> factorize(int n) {
  map<int, int> res;
  while (factor[n]) ++res[factor[n]], n /= factor[n];
  if (n != 1) ++res[n];
  return res;
}

V<> divisor(int n) {
  V<> res{1};
  for (const auto& e : factorize(n)) {
    int m = res.size();
    for (int i = 0; i < e.second; ++i) for (int j = i * m; j < (i + 1) * m; ++j) {
      res.push_back(res[j] * e.first);
    }
  }
  sort(rbegin(res), rend(res));
  return res;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  V<Mint> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int d : divisor(a[i])) if (d <= n) dp[d] += dp[d - 1];
  }
  cout << accumulate(next(begin(dp)), end(dp), Mint(0)) << '\n';
}