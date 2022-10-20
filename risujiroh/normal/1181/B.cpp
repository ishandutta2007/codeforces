#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

using R = double;
constexpr R pi = acos((R) -1);
using C = complex<R>;
C& operator*=(C& l, const C& r) {
  return l = {real(l) * real(r) - imag(l) * imag(r), real(l) * imag(r) + imag(l) * real(r)};
}
void fft(V<C>& a, bool inv = false) {
  int n = a.size();
  int j = 0;
  for (int i = 1; i < n; ++i) {
    int w = n >> 1;
    while (j >= w) j -= w, w >>= 1;
    j += w;
    if (i < j) swap(a[i], a[j]);
  }
  static VV<C> xi(30);
  for (int k = 0; 1 << k < n; ++k) if (xi[k].empty()) {
    xi[k].resize(1 << k);
    for (int i = 0; i < 1 << k; ++i) {
      xi[k][i] = polar<R>(1, i * pi / (1 << k));
    }
  }
  for (int k = 0; 1 << k < n; ++k) {
    const int w = 1 << k;
    for (int s = 0; s < n; s += 2 * w) {
      for (int i = s; i < s + w; ++i) {
        j = i + w;
        a[j] *= inv ? conj(xi[k][i - s]) : xi[k][i - s];
        tie(a[i], a[j]) = make_pair(a[i] + a[j], a[i] - a[j]);
      }
    }
  }
}
template<int K = 15> void multiply(V<lint>& a, const V<lint>& b) {
  if (a.empty() or b.empty()) {
    a = {};
    return;
  }
  int n = 1 << __lg(2 * (a.size() + b.size() - 1) - 1);
  V<C> f(n), g(n);
  for (int i = 0; i < n; ++i) {
    if (i < (int) a.size()) f[i].real(a[i] & ~(~0 << K)), f[i].imag(a[i] >> K);
    if (i < (int) b.size()) g[i].real(b[i] & ~(~0 << K)), g[i].imag(b[i] >> K);
  }
  fft(f), fft(g);
  V<C> Al(n), Au(n), Bl(n), Bu(n);
  for (int i = 0; i < n; ++i) {
    Al[i] = (f[i] + conj(f[-i & n - 1])) / C(2, 0);
    Au[i] = (f[i] - conj(f[-i & n - 1])) / C(0, 2);
    Bl[i] = (g[i] + conj(g[-i & n - 1])) / C(2, 0);
    Bu[i] = (g[i] - conj(g[-i & n - 1])) / C(0, 2);
  }
  for (int i = 0; i < n; ++i) {
    f[i] = Al[i] * Bl[i] + C(0, 1) * Al[i] * Bu[i];
    g[i] = Au[i] * Bl[i] + C(0, 1) * Au[i] * Bu[i];
  }
  fft(f, true), fft(g, true);
  a.resize(a.size() + b.size() - 1);
  for (int i = 0; i < (int) a.size(); ++i) {
    lint l = real(f[i]) / n + 0.5;
    lint m = (imag(f[i]) + real(g[i])) / n + 0.5;
    lint u = imag(g[i]) / n + 0.5;
    a[i] = l + (m << K) + (u << 2 * K);
  }
}

struct Bint {
  bool neg;
  string s;
  Bint() : neg(false), s("0") {}
  Bint(const string& x) : neg(x[0] == '-'), s(x.substr(neg)) {}
  Bint(lint x) : neg(x < 0), s(to_string(abs(x))) {}
  Bint(bool neg, const string& s) : neg(neg), s(s) {}
  Bint operator+() const { return *this; }
  Bint operator-() const { return {!neg, s}; }
  explicit operator bool() const noexcept { return s != "0"; }
  bool operator!() const noexcept { return !(bool) *this; }
  Bint operator*(const Bint& r) const { return Bint(*this) *= r; }
  Bint operator/(const Bint& r) const { return Bint(*this) /= r; }
  Bint operator%(const Bint& r) const { return Bint(*this) %= r; }
  Bint operator+(const Bint& r) const { return Bint(*this) += r; }
  Bint operator-(const Bint& r) const { return Bint(*this) -= r; }
  bool operator<(const Bint& r) const {
    if (neg != r.neg) return neg;
    return neg ^ (s.size() != r.s.size() ? s.size() < r.s.size() : s < r.s);
  }
  bool operator>(const Bint& r) const { return r < *this; }
  bool operator<=(const Bint& r) const { return !(*this > r); }
  bool operator>=(const Bint& r) const { return !(*this < r); }
  bool operator==(const Bint& r) const { return neg == r.neg and s == r.s; }
  bool operator!=(const Bint& r) const { return !(*this == r); }
  Bint& operator*=(const Bint& r) {
    if (!*this or !r) {
      neg = false, s = "0";
      return *this;
    }
    neg ^= r.neg;
    auto t = r.s;
    if (s.size() + t.size() < 20) {
      s = to_string(stoull(s) * stoull(t));
      return *this;
    }
    constexpr int D = 6;
    constexpr int B = 1e6;
    V<lint> a;
    for (int i = s.size(); i > 0; i -= D) {
      a.push_back(stoi(s.substr(max(i - D, 0), min(D, i))));
    }
    V<lint> b;
    for (int i = t.size(); i > 0; i -= D) {
      b.push_back(stoi(t.substr(max(i - D, 0), min(D, i))));
    }
    multiply(a, b);
    V<> res;
    lint c = 0;
    for (int i = 0; i < (int) a.size(); ++i) {
      res.push_back((c += a[i]) % B);
      c /= B;
    }
    s = to_string(c);
    while (!res.empty()) {
      auto t = to_string(res.back());
      while (t.size() < D) t = '0' + t;
      s += t;
      res.pop_back();
    }
    int i = 0;
    while (i < (int) s.size() and s[i] == '0') ++i;
    s = s.substr(i);
    return *this;
  }
  Bint& operator/=(const Bint& r) {
    assert(r);
    auto t = r.s;
    if (Bint(s) < Bint(t)) {
      neg = false, s = "0";
      return *this;
    }
    neg ^= r.neg;
    string res;
    for (int i = s.size() - t.size(); i >= 0; --i) {
      char c = '0';
      while (Bint(s) >= Bint(t + string(i, '0'))) {
        s = (Bint(s) - Bint(t + string(i, '0'))).s;
        ++c;
      }
      res += c;
    }
    s = res;
    int i = 0;
    while (i < (int) s.size() and s[i] == '0') ++i;
    s = s.substr(i);
    return *this;
  }
  Bint& operator%=(const Bint& r) { return *this -= *this / r * r; }
  Bint& operator+=(const Bint& r) {
    auto t = r.s;
    reverse(begin(s), end(s));
    reverse(begin(t), end(t));
    while (s.size() < t.size()) s += '0';
    while (t.size() < s.size()) t += '0';
    s += '0', t += '0';
    if (neg == r.neg) {
      int c = 0;
      for (int i = 0; i < (int) s.size(); ++i) {
        if ((s[i] += t[i] - '0' + c) > '9') {
          s[i] -= 10;
          c = 1;
        } else c = 0;
      }
    } else {
      if (neg) swap(s, t);
      s.back() = '1';
      int c = 0;
      for (int i = 0; i < (int) s.size(); ++i) {
        if ((s[i] -= t[i] - '0' + c) < '0') {
          s[i] += 10;
          c = 1;
        } else c = 0;
      }
      if (neg = s.back() == '0') {
        int i = 0;
        while (s[i] == '0') ++i;
        s[i] = '0' + 10 - (s[i] - '0');
        while (++i < (int) s.size() - 1) s[i] = '9' - (s[i] - '0');
      } else s.back() = '0';
    }
    while (s.size() > 1 and s.back() == '0') s.pop_back();
    reverse(begin(s), end(s));
    return *this;
  }
  Bint& operator-=(const Bint& r) { return *this += -r; }
  template<class Z> friend Bint operator*(Z l, const Bint& r) { return Bint(l) *= r; }
  template<class Z> friend Bint operator/(Z l, const Bint& r) { return Bint(l) /= r; }
  template<class Z> friend Bint operator%(Z l, const Bint& r) { return Bint(l) %= r; }
  template<class Z> friend Bint operator+(Z l, const Bint& r) { return Bint(l) += r; }
  template<class Z> friend Bint operator-(Z l, const Bint& r) { return Bint(l) -= r; }
  friend ostream& operator<<(ostream& os, const Bint& r) { if (r.neg) os << '-'; return os << r.s; }
  friend istream& operator>>(istream& is, Bint& r) { string x; is >> x; r = x; return is; }
  template<class Z> friend bool operator==(Z l, const Bint& r) { return Bint(l) == r; }
  template<class Z> friend bool operator!=(Z l, const Bint& r) { return !(l == r); }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  Bint res(string(n + 1, '9'));
  {
    int i = n / 2;
    while (i and s[i] == '0') --i;
    if (i) {
      res = min(res, Bint(s.substr(0, i)) + Bint(s.substr(i, n - i)));
    }
  }
  {
    int i = (n + 1) / 2;
    while (i < n and s[i] == '0') ++i;
    if (i < n) {
      res = min(res, Bint(s.substr(0, i)) + Bint(s.substr(i, n - i)));
    }
  }
  cout << res << '\n';
}