#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  ModInt() : v(0) {}
  ModInt(auto x) : v(x >= 0 ? x % P : (P - -x % P) % P) {}
  constexpr ModInt(unsigned v, int) : v(v) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool)*this; }
  M operator*(M r) const { return M(*this) *= r; }
  M operator/(M r) const { return M(*this) /= r; }
  M operator+(M r) const { return M(*this) += r; }
  M operator-(M r) const { return M(*this) -= r; }
  bool operator==(M r) const { return v == r.v; }
  bool operator!=(M r) const { return !(*this == r); }
  M& operator*=(M r) { v = (uint64_t)v * r.v % P; return *this; }
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
  M pow(auto n) const {
    if (n < 0) return pow(-n).inv();
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
  friend M operator*(auto l, M r) { return M(l) *= r; }
  friend M operator/(auto l, M r) { return M(l) /= r; }
  friend M operator+(auto l, M r) { return M(l) += r; }
  friend M operator-(auto l, M r) { return M(l) -= r; }
  friend ostream& operator<<(ostream& os, M r) { return os << r.v; }
  friend istream& operator>>(istream& is, M& r) { lint x; is >> x; r = x; return is; }
  friend bool operator==(auto l, M r) { return M(l) == r; }
  friend bool operator!=(auto l, M r) { return !(l == r); }
};
using Mint = ModInt<(unsigned)1e9 + 7>;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> l(n); for (auto&& e : l) cin >> e, --e;
  V<> r(n); for (auto&& e : r) cin >> e;
  l.push_back(-1);
  r.push_back(0);
  V<Mint> im(n + 1);
  for (int i = 0; i < n; ++i) {
    im[i] = Mint(r[i] - l[i]).inv();
  }
  Mint res;
  V<Mint> p(n);
  for (int i = 0; i < n; ++i) {
    int w = max(min(r[i], r[i + 1]) - max(l[i], l[i + 1]), 0);
    p[i] = 1 - im[i] * im[i + 1] * w;
    res += p[i];
  }
  res *= res;
  for (int i = 0; i < n; ++i) {
    res -= p[i] * p[i];
    res += p[i];
  }
  for (int i = 0; i + 1 < n; ++i) {
    res -= 2 * p[i] * p[i + 1];
    int w = max(min({r[i], r[i + 1], r[i + 2]}) - max({l[i], l[i + 1], l[i + 2]}), 0);
    Mint q = im[i] * im[i + 1] * im[i + 2] * w;
    res += 2 * (1 - ((1 - p[i]) + (1 - p[i + 1]) - q));
  }
  cout << res << '\n';
}