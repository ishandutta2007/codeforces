#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  constexpr ModInt() : v(0) {}
  constexpr ModInt(unsigned _v, int) : v(_v) {}
  template<class Z> ModInt(const Z& a) : v((a < 0 ? P - -a % P : a) % P) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool)*this; }
  M& operator*=(M r) { v = (uint64_t)v * r.v % P; return *this; }
  M& operator/=(M r) { return *this *= r.inv(); }
  M& operator+=(M r) { if ((v += r.v) >= P) v -= P; return *this; }
  M& operator-=(M r) { if ((v += P - r.v) >= P) v -= P; return *this; }
  friend M operator*(M l, M r) { return M(l) *= r; }
  friend M operator/(M l, M r) { return M(l) /= r; }
  friend M operator+(M l, M r) { return M(l) += r; }
  friend M operator-(M l, M r) { return M(l) -= r; }
  friend ostream& operator<<(ostream& os, M r) { return os << r.v; }
  friend bool operator==(M l, M r) { return l.v == r.v; }
  friend bool operator!=(M l, M r) { return !(l == r); }
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
};
using Mint = ModInt<(unsigned)1e9 + 7>;

template<class Itr> auto rle(Itr first, Itr last) {
  V< pair<decltype(*first), int> > res;
  for (; first != last; ++first) {
    if (res.empty() or res.back().first != *first) {
      res.emplace_back(*first, 1);
    } else {
      ++res.back().second;
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  V<Mint> dp(1e5 + 1);
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= 1e5; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  string s; cin >> s;
  Mint res = 1;
  for (const auto& e : rle(begin(s), end(s))) {
    if (e.first == 'w' or e.first == 'm') {
      return cout << 0 << '\n', 0;
    }
    if (e.first != 'u' and e.first != 'n') continue;
    res *= dp[e.second];
  }
  cout << res << '\n';
}