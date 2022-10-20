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
  V<> out(n), in(n); for (int i = 0; i < n; ++i) cin >> out[i] >> in[i];
  V<> in_ord(n);
  iota(begin(in_ord), end(in_ord), 0);
  sort(begin(in_ord), end(in_ord), [&](int i, int j) { return in[i] < in[j]; });
  V<> out_ord(n);
  iota(begin(out_ord), end(out_ord), 0);
  sort(begin(out_ord), end(out_ord), [&](int i, int j) { return out[i] < out[j]; });

  struct S { int min; Mint num; };
  auto min = [](S a, S b) -> S {
    if (a.min < b.min) return a;
    if (a.min > b.min) return b;
    return {a.min, a.num + b.num};
  };
  auto add = [](S a, S b) -> S {
    return {a.min + b.min, a.num * b.num};
  };
  constexpr int inf = 1.01e9;

  V<S> dp(n);
  auto itr = begin(out_ord);
  S mn{inf, 0};
  for (int i : in_ord) {
    while (itr != end(out_ord) and out[*itr] <= in[i]) {
      mn = min(mn, add(dp[*itr], {-out[*itr], 1}));
      ++itr;
    }
    dp[i] = min({in[i], 1}, add(mn, {in[i], 1}));
  }

  S res{inf, 0};
  for (int i = 0; i < n; ++i) if (out[i] > in[in_ord.back()]) {
    res = min(res, dp[i]);
  }
  cout << res.num << '\n';
}