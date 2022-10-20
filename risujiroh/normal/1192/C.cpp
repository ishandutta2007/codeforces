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
using Mint = ModInt<998244353>;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V< set<string> > se(11);
  while (n--) {
    string s; cin >> s;
    se[s.size()].emplace(s);
    reverse(begin(s), end(s));
    se[s.size()].emplace(s);
  }

  auto c2i = [](char c) -> int {
    if (islower(c)) return c - 'a';
    if (isupper(c)) return 26 + c - 'A';
    if (isdigit(c)) return 52 + c - '0';
    return -1;
  };

  auto coeff = [](int i, int j, int k, int l) -> int {
    if (i < j and j < k and k < l) return 24;
    if (i < j and j < k) return 12;
    if (i < j and k < l) return 12;
    if (j < k and k < l) return 12;
    if (i < j) return 4;
    if (j < k) return 6;
    if (k < l) return 4;
    return 1;
  };

  Mint res;
  for (int m = 3; m <= 10; ++m) {
    VV<Mint> a(62, V<Mint>(62));
    for (const auto& s : se[m]) {
      a[c2i(s[0])][c2i(s.back())] += 1;
    }
    V< VV<Mint> > b(62, VV<Mint>(62, V<Mint>(62)));
    for (int k = 0; k < 62; ++k) for (int j = 0; j <= k; ++j) for (int i = 0; i <= j; ++i) {
      for (int l = 0; l < 62; ++l) {
        b[i][j][k] += a[i][l] * a[j][l] * a[k][l];
      }
    }
    for (int l = 0; l < 62; ++l) for (int k = 0; k <= l; ++k) for (int j = 0; j <= k; ++j) for (int i = 0; i <= j; ++i) {
      res += coeff(i, j, k, l) * b[i][j][k] * b[i][j][l] * b[i][k][l] * b[j][k][l];
    }
  }
  cout << res << '\n';
}