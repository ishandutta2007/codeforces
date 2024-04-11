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
using Mint = ModInt<998244353>;

V<Mint> fact, ifact;
void init(int n) {
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
Mint comb(int n, int r) {
  if (r < 0 or r > n) return 0;
  return fact[n] * ifact[r] * ifact[n - r];
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, s, l; cin >> n >> s >> l;
  if (n == 1) return cout << 1 << '\n', 0;
  init(s + n);
  Mint res = 0;
  for (int a = l; a <= s; ++a) for (int x = 1; x <= n; ++x) {
    if (a * x > s or a * x + (a - 1) * (n - x) < s) continue;
    Mint curr = 0;
    for (int k = 0; k <= n - x; ++k) {
      curr += (k & 1 ? -1 : 1) * comb(n - x, k) * comb(s - a * (x + k) + max(n - x - 1, 0), s - a * (x + k));
    }
    curr *= comb(n - 1, x - 1);
    res += curr / x;
  }
  Mint sum = 0;
  for (int a = l; a <= s; ++a) {
    sum += comb(s - a + max(n - 2, 0), s - a);
  }
  res /= sum;
  cout << res << '\n';
}