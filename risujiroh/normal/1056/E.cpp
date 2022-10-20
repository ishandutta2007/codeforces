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
  constexpr ModInt() : v(0u) {}
  template<class Int> constexpr ModInt(Int x) : v(x >= 0 ? x % P : -x % P ? P - -x % P : 0) {}
  static constexpr uint p() { return P; }
  constexpr M operator++(int) { M t = *this; if (++v == P) v = 0; return t; }
  constexpr M operator--(int) { M t = *this; v = (v ? v : P) - 1; return t; }
  constexpr M& operator++() { if (++v == P) v = 0; return *this; }
  constexpr M& operator--() { v = (v ? v : P) - 1; return *this; }
  constexpr M operator+() const { return *this; }
  constexpr M operator-() const { return ModInt(v ? P - v : 0); }
  template<class T> constexpr operator T() const noexcept { return v; }
  constexpr M& operator*=(const M& rhs) { v = (ulint) v * rhs.v % P; return *this; }
  template<class Int> constexpr M& operator*=(Int x) { return *this *= M(x); }
  constexpr M& operator/=(const M& rhs) { return *this *= rhs.inv(); }
  template<class Int> constexpr M& operator/=(Int x) { return *this /= M(x); }
  constexpr M& operator+=(const M& rhs) { v = rhs.v < P - v ? v + rhs.v : v - (P - rhs.v); return *this; }
  template<class Int> constexpr M& operator+=(Int x) { return *this += M(x); }
  constexpr M& operator-=(const M& rhs) { v = rhs.v <= v ? v - rhs.v : v + (P - rhs.v); return *this; }
  template<class Int> constexpr M& operator-=(Int x) { return *this -= M(x); }
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
  template<uint P> ostream& operator<<(ostream& os, const M<P>& rhs) { os << rhs.v; return os; }
  template<uint P> istream& operator>>(istream& is, M<P>& rhs) { lint x; is >> x; rhs = M<P>(x); return is; }
  template<uint P> constexpr bool operator==(const M<P>& lhs, const M<P>& rhs) { return lhs.v == rhs.v; }
  template<uint P, class Int> constexpr bool operator==(const M<P>& lhs, Int x) { return lhs == M<P>(x); }
  template<class Int, uint P> constexpr bool operator==(Int x, const M<P>& rhs) { return M<P>(x) == rhs; }
  template<uint P> constexpr bool operator!=(const M<P>& lhs, const M<P>& rhs) { return !(lhs == rhs); }
  template<uint P, class Int> constexpr bool operator!=(const M<P>& lhs, Int x) { return !(lhs == x); }
  template<class Int, uint P> constexpr bool operator!=(Int x, const M<P>& rhs) { return !(x == rhs); }


constexpr uint mod0 = 1'000'000'007u, mod1 = 1'000'000'009u;

template <uint mod> struct RollingHash {
  using Mint = ModInt<mod>;
  int n;
  Mint b;
  V<Mint> h, powb;

  RollingHash(const string& s, Mint b) : n(s.size()), b(b), h(n + 1), powb(n + 1, 1) {
    for (int i = 0; i < n; ++i) {
      h[i + 1] = h[i] * b + s[i];
      powb[i + 1] = powb[i] * b;
    }
  }

  uint get(int l, int r) {
    return (h[r] - h[l] * powb[r - l]).v;
  }
};


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  string s, t; cin >> s >> t;
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  RollingHash<mod0> rh0(t, mt() % mod0);
  RollingHash<mod1> rh1(t, mt() % mod1);
  int a = count(begin(s), end(s), '0');
  int b = count(begin(s), end(s), '1');
  int d = __gcd(a, b);
  int n = s.size(), m = t.size();
  if (m % d) return cout << 0 << '\n', 0;
  int a_ = a / d, b_ = b / d;
  int x, y;
  for (x = 1; ; ++x) if ((m - a * x) % b == 0) {
    y = (m - a * x) / b;
    break;
  }
  int res = 0;
  while (y > 0) {
    int hx0 = -1, hy0 = -1;
    int hx1 = -1, hy1 = -1;
    int i = 0;
    int l = 0, r = s[i] == '0' ? x : y;
    bool ok = true;
    while (i < n) {
      if (s[i] == '0') {
        if (hx0 == -1) hx0 = rh0.get(l, r), hx1 = rh1.get(l, r);
        else if (hx0 != rh0.get(l, r) or hx1 != rh1.get(l, r)) {
          ok = false;
          break;
        }
      } else {
        if (hy0 == -1) hy0 = rh0.get(l, r), hy1 = rh1.get(l, r);
        else if (hy0 != rh0.get(l, r) or hy1 != rh1.get(l, r)) {
          ok = false;
          break;
        }
      }
      l = r, r = l + (s[++i] == '0' ? x : y);
    }
    if (x == y and hx0 == hy0 and hx1 == hy1) ok = false;
    res += ok;
    x += b_, y -= a_;
  }
  cout << res << '\n';
}