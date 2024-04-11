#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


struct Frac {
  lint a, b;
  Frac(lint a = 0) : a(a), b(1) {}
  Frac(lint _a, lint _b) {
    assert(_b);
    lint d = __gcd(abs(_a), abs(_b));
    if (_b < 0) d = -d;
    a = _a / d;
    b = _b / d;
  }
  Frac operator+() const { return *this; }
  Frac operator-() const { Frac res(-a); res.b = b; return res; }
  explicit operator bool() const noexcept { return a; }
  bool operator!() const noexcept { return !(bool) *this; }
  Frac operator*(const Frac& r) const { return Frac(*this) *= r; }
  Frac operator/(const Frac& r) const { return Frac(*this) /= r; }
  Frac operator+(const Frac& r) const { return Frac(*this) += r; }
  Frac operator-(const Frac& r) const { return Frac(*this) -= r; }
  bool operator<(const Frac& r) const { return a * r.b < r.a * b; }
  bool operator>(const Frac& r) const { return r > *this; }
  bool operator<=(const Frac& r) const { return !(*this > r); }
  bool operator>=(const Frac& r) const { return !(*this < r); }
  bool operator==(const Frac& r) const { return a == r.a and b == r.b; }
  bool operator!=(const Frac& r) const { return !(*this == r); }
  Frac& operator*=(const Frac& r) { return *this = {a * r.a, b * r.b}; }
  Frac& operator/=(const Frac& r) { return *this = {a * r.b, b * r.a}; }
  Frac& operator+=(const Frac& r) { return *this = {a * r.b + r.a * b, b * r.b}; }
  Frac& operator-=(const Frac& r) { return *this += -r; }
  template<class Z> friend Frac operator*(Z l, const Frac& r) { return Frac(l) *= r; }
  template<class Z> friend Frac operator/(Z l, const Frac& r) { return Frac(l) /= r; }
  template<class Z> friend Frac operator+(Z l, const Frac& r) { return Frac(l) += r; }
  template<class Z> friend Frac operator-(Z l, const Frac& r) { return Frac(l) -= r; }
  friend ostream& operator<<(ostream& os, const Frac& r) { return os << r.a << " / " << r.b; }
  friend istream& operator>>(istream& is, Frac& r) { lint a, b; cin >> a >> b; r = {a, b}; return is; }
  template<class Z> friend bool operator==(Z l, const Frac& r) { return Frac(l) == r; }
  template<class Z> friend bool operator!=(Z l, const Frac& r) { return !(l == r); }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  V<> b(n); for (auto&& e : b) cin >> e;
  map<Frac, int> mp;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      res += b[i] == 0;
    } else {
      ++mp[{-b[i], a[i]}];
    }
  }
  int mx = 0;
  for (const auto& e : mp) {
    mx = max(mx, e.second);
  }
  res += mx;
  cout << res << '\n';
}