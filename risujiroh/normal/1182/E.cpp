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
using Mint = ModInt<(unsigned) 1e9 + 6>;

constexpr lint mod = 1e9 + 7;
lint tmod(lint a, lint p) { return (a %= p) < 0 ? a + p : a; }
lint mod_inv(lint a, lint p) {
  a = tmod(a, p);
  lint b = p, x = 1, u = 0;
  while (b) {
    lint q = a / b;
    swap(a -= q * b, b);
    swap(x -= q * u, u);
  }
  return a == 1 ? tmod(x, p) : -1;
}
lint mod_pow(lint a, lint n, lint p) {
  assert(n >= 0);
  a = tmod(a, p);
  lint res = 1;
  while (n) {
    if (n & 1) (res *= a) %= p;
    (a *= a) %= p;
    n >>= 1;
  }
  return res;
}
lint mod_log(lint g, lint x, lint p) {
  g = tmod(g, p);
  x = tmod(x, p);
  int m = ceil(sqrt(p - 1));
  map<int, int> mp;
  lint a = 1;
  for (int j = 0; j < m; ++j) {
    mp[a] = j;
    (a *= g) %= p;
  }
  g = mod_inv(mod_pow(g, m, p), p), a = 1;
  for (int i = 0; i < (p - 1 + m - 1) / m; ++i) {
    if (mp.count(a * x % p)) {
      return i * m + mp[a * x % p];
    }
    (a *= g) %= p;
  }
  return -1;
}

template<class T> V<T> operator*(const VV<T>& A, const V<T>& x) {
  assert(A[0].size() == x.size());
  V<T> res(A.size());
  for (int i = 0; i < (int) A.size(); ++i) {
    res[i] = inner_product(begin(A[i]), end(A[i]), begin(x), (T) 0);
  }
  return res;
}
template<class T> VV<T> operator*(const VV<T>& A, const VV<T>& B) {
  assert(A[0].size() == B.size());
  VV<T> res(A.size(), V<T>(B[0].size()));
  for (int i = 0; i < (int) A.size(); ++i) for (int k = 0; k < (int) A[0].size(); ++k) for (int j = 0; j < (int) B[0].size(); ++j) {
    res[i][j] += A[i][k] * B[k][j];
  }
  return res;
}
template<class T> VV<T>& operator*=(VV<T>& A, const VV<T>& B) { return A = A * B; }
template<class T> VV<T> I(int n) {
  VV<T> res(n, V<T>(n));
  for (int i = 0; i < n; ++i) res[i][i] = 1;
  return res;
}
template<class T> VV<T> pow(VV<T> A, lint n) {
  auto res = I<T>(A.size());
  while (n) {
    if (n & 1) res *= A;
    A *= A;
    n >>= 1;
  }
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint n; cin >> n, --n;
  V<lint> a(3); for (auto&& e : a) cin >> e;
  lint c; cin >> c;
  a.push_back(mod_pow(c, 2, mod) * a[2] % mod * a[1] % mod * a[0] % mod);
  for (auto&& e : a) e = mod_log(5, e, mod);
  c = mod_log(5, c, mod);
  VV<Mint> A{
    {1, 1, 1, 0, 2 * c},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 1}
  };
  V<Mint> x{a[3] - a[2], a[2] - a[1], a[1] - a[0], 0, 1};
  x = pow(A, n) * x;
  auto res = mod_pow(5, (a[0] + x[3]).v, mod);
  cout << res << '\n';
}