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
  int n, k; cin >> n >> k;
  V<> a(n), c(1e5 + 1);
  for (auto&& e : a) {
    cin >> e;
    ++c[e];
  }
  sort(begin(a), end(a));
  a.erase(unique(begin(a), end(a)), end(a));
  n = a.size();
  if (k > n) return cout << 0 << '\n', 0;
  Mint res;
  for (int x = 1; x <= (int)1e5 / (k - 1); ++x) {
    V<Mint> dp(n);
    for (int i = 0; i < n; ++i) dp[i] = c[a[i]];
    for (int l = 2; l <= k; ++l) {
      for (int i = 0; i + 1 < n; ++i) dp[i + 1] += dp[i];
      V<Mint> ndp(n);
      int j = -1;
      for (int i = 0; i < n; ++i) {
        while (j + 1 < n and a[j + 1] <= a[i] - x) ++j;
        if (j >= 0) ndp[i] = dp[j] * c[a[i]];
      }
      swap(dp, ndp);
    }
    res += accumulate(begin(dp), end(dp), Mint(0));
  }
  cout << res << '\n';
}