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

V<Mint> fact, ifact;
void init(int n) {
  assert(n >= 0);
  fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = i * fact[i - 1];
  }
  ifact.resize(n + 1);
  ifact[n] = fact[n].inv();
  for (int i = n; i > 0; --i) {
    ifact[i - 1] = i * ifact[i];
  }
}

int c2i(char c) {
  if (islower(c)) return c - 'a';
  assert(isupper(c));
  return c - 'A' + 26;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size() >> 1;
  V<> a(52);
  for (char c : s) {
    ++a[c2i(c)];
  }

  V<Mint> dp0(n + 1);
  dp0[0] = 1;
  for (int i = 0; i < 52; ++i) if (a[i] > 0) {
    V<Mint> ndp(n + 1);
    for (int k = 0; k <= n; ++k) {
      ndp[k] = dp0[k];
      if (k - a[i] >= 0) ndp[k] += dp0[k - a[i]];
    }
    swap(dp0, ndp);
  }

  VV<Mint> res; assign(res, 52, 52, 0);
  for (int i = 0; i < 52; ++i) {
    res[i][i] = dp0[n];
  }
  for (int i = 0; i < 52; ++i) for (int j = 0; j < 52; ++j) if (i < j and a[i] > 0 and a[j] > 0) {
    V<Mint> dp1(n + 1);
    for (int k = 0; k <= n; ++k) {
      dp1[k] = dp0[k];
      if (k - a[i] - a[j] >= 0) dp1[k] += dp0[k - a[i] - a[j]];
      if (k - a[i] >= 0) dp1[k] -= dp1[k - a[i]];
      if (k - a[j] >= 0) dp1[k] -= dp1[k - a[j]];
      if (k - a[i] - a[j] >= 0) dp1[k] -= dp1[k - a[i] - a[j]];
    }
    res[i][j] = dp1[n];
  }

  init(n);
  Mint coeff = fact[n] * fact[n];
  for (int i = 0; i < 52; ++i) {
    coeff *= ifact[a[i]];
  }

  int q; cin >> q;
  while (q--) {
    int x, y; cin >> x >> y, --x, --y;
    x = c2i(s[x]);
    y = c2i(s[y]);
    if (x > y) swap(x, y);
    cout << coeff * res[x][y] << '\n';
  }
}