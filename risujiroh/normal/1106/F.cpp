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

using Mint = ModInt<998244353>;

constexpr int mod = Mint::p() - 1;

using Mat = VV<lint>;

Mat operator*(const Mat& lhs, const Mat& rhs) {
  assert(!lhs.empty() and !rhs.empty());
  assert(lhs[0].size() == rhs.size());
  int n = lhs.size(), l = lhs[0].size(), m = rhs[0].size();
  Mat res; assign(res, n, m, 0);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    for (int k = 0; k < l; ++k) {
      (res[i][j] += lhs[i][k] * rhs[k][j] % mod) %= mod;
    }
  }
  return res;
}

Mat pow(Mat a, lint k) {
  assert(!a.empty() and a.size() == a[0].size());
  assert(k >= 0);
  int n = a.size();
  Mat res; assign(res, n, n, 0);
  for (int i = 0; i < n; ++i) res[i][i] = 1;
  for (; k > 0; a = a * a, k >>= 1) if (k & 1) res = res * a;
  return res;
}

int mod_log(Mint g, Mint x) {
  int m = 1e4;
  unordered_map<int, int> mp;
  Mint a = 1;
  for (int j = 0; j < m; ++j) {
    mp[a.v] = j;
    a *= g;
  }
  a = 1, g = g.pow(-m);
  for (int i = 0; i < (Mint::p() - 1 + m - 1) / m; ++i) {
    if (mp.count((a * x).v)) {
      return i * m + mp[(a * x).v];
    }
    a *= g;
  }
  return -1;
}

template<class Int> Int extgcd(Int a, Int b, Int& x, Int& y) {
  Int u = y = 0, v = x = 1; 
  while (b) {
    Int q = a / b;
    swap(a -= q * b, b);
    swap(x -= q * u, u);
    swap(y -= q * v, v);
  }
  return a;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int k; cin >> k;
  V<> b(k); for (int i = 0; i < k; ++i) cin >> b[i];
  int n, m; cin >> n >> m;
  Mat A; assign(A, k, k, 0);
  for (int j = 0; j < k; ++j) {
    A[0][j] = b[j];
  }
  for (int i = 1; i < k; ++i) {
    A[i][i - 1] = 1;
  }
  A = pow(A, n - k);
  int e = A[0][0];
  constexpr int g = 530;
  int x = mod_log(g, m);
  int y, z;
  int d = extgcd(e, mod, y, z);
  if (x % d) return cout << -1 << '\n', 0;
  int res = Mint(g).pow(1LL * y * x / d).v;
  cout << res << '\n';
}