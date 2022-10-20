#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  ModInt() : v(0) {}
  template<class Int> ModInt(Int x) : v(x >= 0 ? x % P : -x % P ? P - -x % P : 0) {}
  constexpr ModInt(unsigned v, int) : v(v) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool) *this; }
  M operator*(M rhs) const { return M(*this) *= rhs; }
  M operator/(M rhs) const { return M(*this) /= rhs; }
  M operator+(M rhs) const { return M(*this) += rhs; }
  M operator-(M rhs) const { return M(*this) -= rhs; }
  bool operator==(M rhs) const { return v == rhs.v; }
  bool operator!=(M rhs) const { return !(*this == rhs); }
  M& operator*=(M rhs) { v = (unsigned long long) v * rhs.v % P; return *this; }
  M& operator/=(M rhs) { return *this *= rhs.inv(); }
  M& operator+=(M rhs) { v = rhs.v < P - v ? v + rhs.v : v - (P - rhs.v); return *this; }
  M& operator-=(M rhs) { v = rhs.v <= v ? v - rhs.v : v + (P - rhs.v); return *this; }
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
  template<class Int> M pow(Int n) const {
    n = n >= 0 ? n % (P - 1) : P - 1 - -n % (P - 1);
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
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
using Mint = ModInt<(unsigned) 1e9 + 7>;

constexpr int N = 100;
template<class T> using Mat = array<T, N * N>;
template<class T> Mat<T> operator*(const Mat<T>& A, const Mat<T>& B) {
  Mat<T> res{};
  for (int i = 0; i < N; ++i) for (int k = 0; k < N; ++k) for (int j = 0; j < N; ++j) {
    res[i * N + j] += A[i * N + k] * B[k * N + j];
  }
  return res;
}
template<class T> Mat<T>& operator*=(Mat<T>& A, const Mat<T>& B) { return A = A * B; }
template<class T> Mat<T> I() {
  Mat<T> res{};
  for (int i = 0; i < N; ++i) res[i * N + i] = 1;
  return res;
}
template<class T> Mat<T> pow(Mat<T> A, lint n) {
  auto res = I<T>();
  for (; n > 0; n >>= 1) {
    if (n & 1) res *= A;
    A *= A;
  }
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint n; cin >> n;
  int m; cin >> m;
  Mat<Mint> A{};
  auto _ = [](int i, int j) -> int { return i * N + j; };
  for (int i = 1; i < m; ++i) {
    A[_(i, i - 1)] = 1;
  }
  A[_(0, 0)] = A[_(0, m - 1)] = 1;
  A = pow(A, n);
  cout << A[_(0, 0)] << '\n';
}