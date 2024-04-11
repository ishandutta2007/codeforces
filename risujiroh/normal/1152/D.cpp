#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  ModInt() : v(0) {}
  template<class Z> ModInt(Z x) : v(x >= 0 ? x % P : (P - -x % P) % P) {}
  constexpr ModInt(unsigned v, int) : v(v) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool) *this; }
  M operator*(M r) const { return M(*this) *= r; }
  M operator/(M r) const { return M(*this) /= r; }
  M operator+(M r) const { return M(*this) += r; }
  M operator-(M r) const { return M(*this) -= r; }
  bool operator==(M r) const { return v == r.v; }
  bool operator!=(M r) const { return !(*this == r); }
  M& operator*=(M r) { v = (uint64_t) v * r.v % P; return *this; }
  M& operator/=(M r) { return *this *= r.inv(); }
  M& operator+=(M r) { if ((v += r.v) >= P) v -= P; return *this; }
  M& operator-=(M r) { if ((v += P - r.v) >= P) v -= P; return *this; }
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
  template<class Z> M pow(Z n) const {
    if (n < 0) return pow(-n).inv();
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
  template<class Z> friend M operator*(Z l, M r) { return M(l) *= r; }
  template<class Z> friend M operator/(Z l, M r) { return M(l) /= r; }
  template<class Z> friend M operator+(Z l, M r) { return M(l) += r; }
  template<class Z> friend M operator-(Z l, M r) { return M(l) -= r; }
  friend ostream& operator<<(ostream& os, M r) { return os << r.v; }
  friend istream& operator>>(istream& is, M& r) { lint x; is >> x; r = x; return is; }
  template<class Z> friend bool operator==(Z l, M r) { return M(l) == r; }
  template<class Z> friend bool operator!=(Z l, M r) { return !(l == r); }
};
using Mint = ModInt<(unsigned) 1e9 + 7>;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  VV<Mint> dp(n + 1, V<Mint>(n + 1));
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    }
  }
  Mint res;
  for (int i = 0; i <= n; ++i) {
    for (int j = i - 1; j >= 0; j -= 2) {
      res += dp[i][j];
    }
  }
  cout << res << '\n';
}