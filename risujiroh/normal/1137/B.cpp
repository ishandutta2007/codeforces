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

template<class Int> Int rng(Int a, Int b) {
  static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<Int>(a, b - 1)(mt);
}

struct RollingHash {
  using Mint0 = ModInt<(unsigned) 1e9 + 7>;
  using Mint1 = ModInt<(unsigned) 1e9 + 9>;
  const int n;
  static Mint0 b0;
  static Mint1 b1;
  V<Mint0> h0, powb0;
  V<Mint1> h1, powb1;
  template<class Itr> RollingHash(Itr first, Itr last) :
    n(distance(first, last)), h0(n + 1), powb0(n + 1), h1(n + 1), powb1(n + 1) {
    powb0[0].v = powb1[0].v = 1;
    for (int i = 0; i < n; ++i, ++first) {
      h0[i + 1] = h0[i] * b0 + Mint0(*first);
      h1[i + 1] = h1[i] * b1 + Mint1(*first);
      powb0[i + 1] = powb0[i] * b0;
      powb1[i + 1] = powb1[i] * b1;
    }
  }
  pair<int, int> get(int l, int r) {
    return {(h0[r] - h0[l] * powb0[r - l]).v, (h1[r] - h1[l] * powb1[r - l]).v};
  }
};
RollingHash::Mint0 RollingHash::b0 = rng<int>(0, RollingHash::Mint0::p());
RollingHash::Mint1 RollingHash::b1 = rng<int>(0, RollingHash::Mint1::p());

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  auto calc_k = [&]() -> int {
    RollingHash rh(begin(t), end(t));
    for (int k = m - 1; k > 0; --k) {
      if (rh.get(0, k) == rh.get(m - k, m)) return k;
    }
    return 0;
  };
  int k = calc_k();
  int lc0 = 0, lc1 = 0;
  for (int i = 0; i < m - k; ++i) {
    lc0 += t[i] == '0';
    lc1 += t[i] == '1';
  }
  int rc0 = 0, rc1 = 0;
  for (int i = m - k; i < m; ++i) {
    rc0 += t[i] == '0';
    rc1 += t[i] == '1';
  }
  int c0 = 0, c1 = 0;
  for (int i = 0; i < n; ++i) {
    c0 += s[i] == '0';
    c1 += s[i] == '1';
  }
  if (c0 < rc0 or c1 < rc1) return cout << s << '\n', 0;
  c0 -= rc0, c1 -= rc1;
  int x = min(lc0 ? c0 / lc0 : 1e9, lc1 ? c1 / lc1 : 1e9);
  string res;
  for (int _ = 0; _ < x; ++_) {
    res += t.substr(0, m - k);
  }
  c0 -= x * lc0, c1 -= x * lc1;
  res += t.substr(m - k, m);
  res += string(c0, '0');
  res += string(c1, '1');
  cout << res << '\n';
}