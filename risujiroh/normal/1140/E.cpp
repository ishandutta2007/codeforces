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
using Mint = ModInt<998244353>;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<> e, o;
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    if (~i & 1) e.push_back(a);
    else o.push_back(a);
  }
  int m = e.size();
  for (int i = 0; i < m - 1; ++i) if (e[i] != -1 and e[i] == e[i + 1]) return cout << 0 << '\n', 0;
  m = o.size();
  for (int i = 0; i < m - 1; ++i) if (o[i] != -1 and o[i] == o[i + 1]) return cout << 0 << '\n', 0;
  V<Mint> p(n + 1), q(n + 1);
  q[1] = 1;
  for (int i = 2; i <= n; ++i) {
    p[i] = (k - 1) * q[i - 1];
    q[i] = p[i - 1] + (k - 2) * q[i - 1];
  }
  auto fn = [&](V<> a) -> Mint {
    int n = a.size();
    if (all_of(begin(a), end(a), [](int x) { return x == -1; })) {
      return k * Mint(k - 1).pow(n - 1);
    }
    int x = 0;
    while (a.back() == -1) {
      a.pop_back();
      ++x;
    }
    Mint res = Mint(k - 1).pow(x);
    reverse(begin(a), end(a));
    x = 0;
    while (a.back() == -1) {
      a.pop_back();
      ++x;
    }
    res *= Mint(k - 1).pow(x);
    x = 0;
    n = a.size();
    int prev;
    for (int i = 0; i < n; ++i) {
      if (a[i] == -1) {
        ++x;
        if (a[i + 1] == -1) continue;
        if (prev == a[i + 1]) {
          res *= (k - 1) * q[x];
        } else {
          res *= p[x] + (k - 2) * q[x];
        }
      } else {
        x = 0;
        prev = a[i];
      }
    }
    return res;
  };
  cout << fn(o) * fn(e) << '\n';
}