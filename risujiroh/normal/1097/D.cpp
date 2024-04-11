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
  constexpr ModInt(uint v, int _) : v(v) {} // 
  static constexpr uint p() { return P; }
  M operator++(int) { M t = *this; if (++v == P) v = 0; return t; }
  M operator--(int) { M t = *this; v = (v ? v : P) - 1; return t; }
  M& operator++() { if (++v == P) v = 0; return *this; }
  M& operator--() { v = (v ? v : P) - 1; return *this; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !static_cast<bool>(*this); }
  M operator*(M rhs) const { return M(*this) *= rhs; }
  M operator/(M rhs) const { return M(*this) /= rhs; }
  M operator+(M rhs) const { return M(*this) += rhs; }
  M operator-(M rhs) const { return M(*this) -= rhs; }
  bool operator==(M rhs) { return v == rhs.v; }
  bool operator!=(M rhs) { return !(*this == rhs); }
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
  template<class Int> friend M operator*(Int lhs, M rhs) { return M(lhs) *= rhs; }
  template<class Int> friend M operator/(Int lhs, M rhs) { return M(lhs) /= rhs; }
  template<class Int> friend M operator+(Int lhs, M rhs) { return M(lhs) += rhs; }
  template<class Int> friend M operator-(Int lhs, M rhs) { return M(lhs) -= rhs; }
  friend ostream& operator<<(ostream& os, M rhs) { return os << rhs.v; }
  friend istream& operator>>(istream& is, M& rhs) { lint x; is >> x; rhs = x; return is; }
  template<class Int> friend bool operator==(Int lhs, M rhs) { return M(lhs) == rhs; }
  template<class Int> friend bool operator!=(Int lhs, M rhs) { return !(lhs == rhs); }
};

using Mint = ModInt<static_cast<uint>(1e9 + 7)>;

template<class Int> V<Int> divisor(Int n) {
  V<Int> res;
  Int i;
  for (i = 1; i * i < n; ++i) if (n % i == 0) res.push_back(i), res.push_back(n / i);
  if (i * i == n) res.push_back(i);
  sort(begin(res), end(res));
  return res;
}

template<class Int> map<Int, int> factor(Int n) {
  map<Int, int> res;
  for (Int i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

int ord(lint n, lint p) { return n % p ? 0 : ord(n / p, p) + 1; }

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  lint n; cin >> n;
  int k; cin >> k;
  auto mp = factor(n);
  VV<Mint> dp;
  for (const auto& e : mp) {
    int m = e.second + 1;
    V<Mint> dp0(m), dp1(m);
    dp0.back() = 1;
    for (int i = 0; i < k; ++i) {
      fill(begin(dp1), end(dp1), 0);
      for (int j = 0; j < m; ++j) {
        Mint inv = Mint(j + 1).inv();
        for (int k = 0; k <= j; ++k) {
          dp1[k] += dp0[j] * inv;
        }
      }
      swap(dp0, dp1);
    }
    dp.push_back(dp0);
  }
  auto ds = divisor(n);
  Mint res = 0;
  for (lint d : ds) {
    int i = 0;
    Mint p = 1;
    for (const auto& e : mp) {
      int x = ord(d, e.first);
      p *= dp[i][x];
      ++i;
    }
    res += p * d;
  }
  cout << res << '\n';
}