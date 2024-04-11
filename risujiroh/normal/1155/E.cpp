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
using Mint = ModInt<(unsigned) 1e6 + 3>;

template<class T> pair<int, T> gauss_jordan(VV<T>& A) {
  int n = A.size(), m = A[0].size(), r = 0;
  T det = 1;
  for (int j = 0; j < m; ++j) {
    for (int i = r + 1; i < n; ++i) if (A[i][j]) {
      swap(A[r], A[i]);
      det = -det;
      break;
    }
    if (!A[r][j]) continue;
    det *= A[r][j];
    auto inv = (T) 1 / A[r][j];
    for (auto&& e : A[r]) e *= inv;
    for (int i = 0; i < n; ++i) if (i != r and A[i][j]) {
      auto c = A[i][j];
      for (int k = 0; k < m; ++k) {
        A[i][k] -= c * A[r][k];
      }
    }
    if (++r == n) break;
  }
  return {r, det * (int) (r == n)};
}

int main() {
  int k = 10;
  VV<Mint> A(k + 1, V<Mint>(k + 2));
  for (int x = 0; x <= k; ++x) {
    for (int j = 0; j <= k; ++j) {
      A[x][j] = Mint(x).pow(j);
    }
    cout << "? " << x << endl;
    cin >> A[x].back();
  }
  gauss_jordan(A);
  for (int x = 0; x < (int) Mint::p(); ++x) {
    Mint s;
    for (int j = 0; j <= k; ++j) {
      s += A[j].back() * Mint(x).pow(j);
    }
    if (!s) {
      cout << "! " << x << endl;
      return 0;
    }
  }
  cout << "! -1" << endl;
}