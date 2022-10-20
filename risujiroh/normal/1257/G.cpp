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
using Mint = ModInt<998244353>;
constexpr int N = 1 << 21;
struct Fact {
  V<Mint> v;
  Fact(int n) : v(n + 1, 1) {
    for (int i = 1; i <= n; ++i) v[i] = i * v[i - 1];
  }
  Mint operator[](int i) const { return v[i]; }
} fact(N);
struct Finv {
  V<Mint> v;
  Finv(int n) : v(n + 1, 1 / fact[n]) {
    for (int i = n; i; --i) v[i - 1] = i * v[i];
  }
  Mint operator[](int i) const { return v[i]; }
} finv(N);
struct Minv {
  V<Mint> v;
  Minv(int n) : v(n) {
    for (int i = 1; i <= n; ++i) v[i - 1] = fact[i - 1] * finv[i];
  }
  Mint operator[](int i) const { return v[i - 1]; }
} minv(N);
Mint comb(int n, int r) {
  if (r < 0 or r > n) return 0;
  return fact[n] * finv[r] * finv[n - r];
}

namespace NTT {
  constexpr int LG = 21;
  constexpr unsigned P = Mint::p();
  const Mint g = [] { for (Mint a = 3; ; ++a.v) if (a.pow((P - 1) / 2) != 1) return a; }();
  void ntt(const V<Mint>& a, Mint A[], int n) {
    int lg = __lg(n);
    assert(n == 1 << lg);
    assert(lg <= LG);
    assert((P - 1) % n == 0);
    static VV<Mint> w(1, V<Mint>(1, 1));
    for (int k = 1; k <= lg; ++k) if (k >= (int)w.size()) {
      w.emplace_back(1 << (k - 1));
      auto z = g.pow((P - 1) >> k);
      for (int i = 0; i < 1 << (k - 1); ++i) {
        w[k][i] = w[k - 1][i >> 1];
        if (i & 1) w[k][i] *= z;
      }
    }
    for (int i = 0, j = n / 2; j < n; ++i, ++j) {
      auto ai = i < (int)a.size() ? a[i] : 0;
      auto aj = j < (int)a.size() ? a[j] : 0;
      uint64_t x = P + ai.v - aj.v;
      A[i] = ai + aj;
      A[j].v = w[lg][i].v * x % P;
    }
    for (int k = lg - 1; k >= 1; --k) {
      int d = 1 << (k - 1);
      for (int s = 0; s < n; s += 2 * d) {
        for (int i = s, j = s + d, p = i - s; i < s + d; ++i, ++j) {
          uint64_t x = P + A[i].v - A[j].v;
          A[i] = A[i] + A[j];
          A[j].v = w[k][p++].v * x % P;
        }
      }
    }
  }
  void intt(Mint A[], int n) {
    int lg = __lg(n);
    assert(n == 1 << lg);
    assert(lg <= LG);
    assert((P - 1) % n == 0);
    static Mint w[1 << (LG - 1)];
    if (!w[0]) {
      w[0] = 1;
      for (int k = 1; k < LG; ++k) {
        int d = 1 << (k - 1);
        auto z = g.inv().pow((P - 1) >> (k + 1));
        for (int i = 0; i < d; ++i) {
          w[i + d] = w[i] * z;
        }
      }
    }
    for (int k = 1; k <= lg; ++k) {
      int d = 1 << (k - 1);
      for (int s = 0, p = 0; s < n; s += 2 * d) {
        uint64_t nw = w[p++].v;
        for (int i = s, j = s + d; i < s + d; ++i, ++j) {
          uint64_t x = P + A[i].v - A[j].v;
          A[i] = A[i] + A[j];
          A[j].v = nw * x % P;
        }
      }
    }
  }
  Mint A[1 << LG], B[1 << LG];
  V<Mint> multiply(const V<Mint>& a, const V<Mint>& b) {
    int na = a.size(), nb = b.size();
    if (!na or !nb) return {};
    int nc = na + nb - 1, n = 1 << __lg(2 * nc - 1);
    if (min(na, nb) < 16) {
      V<Mint> c(nc);
      for (int i = 0; i < na; ++i) for (int j = 0; j < nb; ++j) {
        c[i + j] += a[i] * b[j];
      }
      return c;
    }
    ntt(a, A, n);
    ntt(b, B, n);
    for (int i = 0; i < n; ++i) A[i] *= B[i];
    intt(A, n);
    V<Mint> c(nc);
    for (int i = 0; i < nc; ++i) c[i] = A[i] * minv[n];
    return c;
  }
}

template<class T, V<T> Mul(const V<T>&, const V<T>&)>
struct FormalPowerSeries : public V<T> {
  using F = FormalPowerSeries;
  using V<T>::V;
  FormalPowerSeries() {}
  FormalPowerSeries(const V<T>& v) : V<T>(v) {}
  T get(int i) const { return i < (int)this->size() ? (*this)[i] : 0; }
  F cut(int n) const { return F(begin(*this), begin(*this) + min<int>(n, this->size())); }
  F trim() {
    while (not this->empty() and !this->back()) this->pop_back();
    return *this;
  }
  F operator+() const { return *this; }
  F operator-() const { F res = *this; for (auto&& e : res) e = -e; return res; }
  explicit operator bool() const noexcept { return not F(*this).trim().empty(); }
  bool operator!() const noexcept { return !(bool)*this; }
  F& operator*=(const F& r) { return *this = Mul(*this, r); }
  F& operator*=(const T& r) { for (auto&& e : *this) e *= r; return *this; }
  F& operator/=(const F& r) {
    int n = max(this->size(), r.size());
    *this *= r.inv(n);
    this->resize(n);
    return *this;
  }
  F& operator/=(const T& r) { return *this *= 1 / r; }
  F& operator+=(const F& r) {
    this->resize(max(this->size(), r.size()));
    for (int i = 0; i < (int)r.size(); ++i) (*this)[i] += r[i];
    return *this;
  }
  F& operator+=(const T& r) { return *this += F(1, r); }
  F& operator-=(const F& r) {
    this->resize(max(this->size(), r.size()));
    for (int i = 0; i < (int)r.size(); ++i) (*this)[i] -= r[i];
    return *this;
  }
  F& operator-=(const T& r) { return *this -= F(1, r); }
  F& operator<<=(int n) {
    if (n < 0) return *this >>= -n;
    this->insert(begin(*this), n, 0);
    return *this;
  }
  F& operator>>=(int n) {
    if (n < 0) return *this <<= -n;
    this->erase(begin(*this), begin(*this) + n);
    return *this;
  }
  friend F operator*(const F& l, const F& r) { return F(l) *= r; }
  friend F operator*(const F& l, const T& r) { return F(l) *= r; }
  friend F operator*(const T& l, const F& r) { return r * l; }
  friend F operator/(const F& l, const F& r) { return F(l) /= r; }
  friend F operator/(const F& l, const T& r) { return F(l) /= r; }
  friend F operator/(const T& l, const F& r) { return r.inv() * l; }
  friend F operator+(const F& l, const F& r) { return F(l) += r; }
  friend F operator+(const F& l, const T& r) { return F(l) += r; }
  friend F operator+(const T& l, const F& r) { return r + l; }
  friend F operator-(const F& l, const F& r) { return F(l) -= r; }
  friend F operator-(const F& l, const T& r) { return F(l) -= r; }
  friend F operator-(const T& l, const F& r) { return -r + l; }
  friend ostream& operator<<(ostream& os, const F& r) {
    int n = F(r).trim().size();
    if (!n) return os << '0';
    for (int i = 0; i < n; ++i) if (r[i]) {
      if (!i or r[i] != 1) os << r[i];
      if (i) cout << 'X';
      if (i >= 2) cout << '^' << i;
      if (i < n - 1) cout << " + ";
    }
    return os;
  }
  friend F operator<<(const F& l, int n) { return F(l) <<= n; }
  friend F operator>>(const F& l, int n) { return F(l) >>= n; }
  friend bool operator==(const F& l, const F& r) { return (l - r).trim().empty(); }
  friend bool operator==(const F& l, const T& r) { return l == F(1, r); }
  friend bool operator==(const T& l, const F& r) { return F(1, l) == r; }
  friend bool operator!=(const F& l, const F& r) { return !(l == r); }
  friend bool operator!=(const F& l, const T& r) { return !(l == r); }
  friend bool operator!=(const T& l, const F& r) { return !(l == r); }
  F inv(int n = -1) const {
    assert(get(0));
    if (n == -1) n = this->size();
    F g{1 / (*this)[0]};
    for (int m = 1; m < n; m *= 2) {
      g = (2 * g - cut(2 * m) * g * g).cut(2 * m);
    }
    return g.cut(n);
  }
  F diff() const {
    int n = this->size();
    F res(n - 1);
    for (int i = 1; i < n; ++i) res[i - 1] = i * (*this)[i];
    return res;
  }
  F integ() const {
    int n = this->size();
    F res(n + 1);
    for (int i = 1; i <= n; ++i) res[i] = (*this)[i - 1] / i;
    return res;
  }
  F log(int n = -1) const {
    assert(get(0) == 1);
    if (n == -1) n = this->size();
    return (diff() * inv(n - 1)).cut(n - 1).integ();
  }
  F exp(int n = -1) const {
    assert(!get(0));
    if (n == -1) n = this->size();
    F g{1};
    for (int m = 1; m < n; m *= 2) {
      g = (g * (1 + cut(2 * m) - g.log(2 * m))).cut(2 * m);
    }
    return g.cut(n);
  }
  template<class Z> F pow(Z m, int n = -1) const {
    if (m < 0) return pow(-m, n).inv();
    if (n == -1) n = (max<int>(this->size(), 1) - 1) * m + 1;
    F res{1};
    for (F a = cut(n); m; a = (a * a).cut(n), m >>= 1) {
      if (m & 1) res = (res * a).cut(n);
    }
    return res;
  }
  F sqrt(int n = -1) const {
    assert(get(0) == 1);
    if (n == -1) n = this->size();
    F g{1};
    for (int m = 1; m < n; m *= 2) {
      g = ((g + cut(2 * m) * g.inv(2 * m)) / 2).cut(2 * m);
    }
    return g.cut(n);
  }
};
template<class T> V<T> naive_multiply(const V<T>& a, const V<T>& b) {
  int n = a.size(), m = b.size();
  V<T> c(n + m - 1);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    c[i + j] += a[i] * b[j];
  }
  return c;
}
// using FPS = FormalPowerSeries<double, naive_multiply>; // for debug

using FPS = FormalPowerSeries<Mint, NTT::multiply>;
template<> FPS FPS::inv(int n) const {
  assert(get(0));
  if (n == -1) n = this->size();
  if (min<int>(this->size(), n) < 16) {
    FPS g(n);
    g[0] = 1 / (*this)[0];
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < min<int>(this->size(), i + 1); ++j) {
        g[i] -= (*this)[j] * g[i - j];
      }
      g[i] *= g[0];
    }
    return g;
  }
  using namespace NTT;
  F g{1 / (*this)[0]};
  for (int m = 1; m < n; m *= 2) {
    ntt(cut(2 * m), A, 4 * m);
    ntt(g, B, 4 * m);
    for (int i = 0; i < 4 * m; ++i) {
      A[i] *= B[i] * B[i];
    }
    intt(A, 4 * m);
    g.resize(2 * m);
    for (int i = 0; i < 2 * m; ++i) {
      g[i] = 2 * g[i] - A[i] * minv[4 * m];
    }
  }
  return g.cut(n);
}
template<> FPS& FPS::operator/=(const FPS& r) {
  int n = max(this->size(), r.size());
  if (r.size() < 16) {
    this->resize(n);
    auto ir0 = 1 / r[0];
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < min<int>(r.size(), i + 1); ++j) {
        (*this)[i] -= r[j] * (*this)[i - j];
      }
      (*this)[i] *= ir0;
    }
    return *this;
  }
  *this *= r.inv(n);
  this->resize(n);
  return *this;
}
template<> FPS FPS::integ() const {
  int n = this->size();
  F res(n + 1);
  for (int i = 1; i <= n; ++i) res[i] = (*this)[i - 1] * minv[i];
  return res;
}
template<> template<class Z> FPS FPS::pow(Z m, int n) const {
  if (m < 0) return pow(-m, n).inv();
  if (n == -1) {
    using namespace NTT;
    n = (max<int>(this->size(), 1) - 1) * m + 1;
    int lg = __lg(2 * n - 1);
    ntt(*this, A, 1 << lg);
    for (int i = 0; i < 1 << lg; ++i) A[i] = A[i].pow(m);
    intt(A, 1 << lg);
    FPS res(n);
    for (int i = 0; i < n; ++i) res[i] = A[i] * minv[1 << lg];
    return res;
  }
  F res{1};
  for (F a = cut(n); m; a = (a * a).cut(n), m >>= 1) {
    if (m & 1) res = (res * a).cut(n);
  }
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  map<int, int> mp;
  for (int _ = 0; _ < n; ++_) {
    int p; cin >> p;
    ++mp[p];
  }
  int mn = 1e9;
  auto cmp = [](const FPS& l, const FPS& r) { return l.size() < r.size(); };
  multiset<FPS, decltype(cmp)> ms(cmp);
  for (const auto& e : mp) {
    ms.emplace(e.second + 1, 1);
    mn = min(mn, e.second);
  }
  while (ms.size() >= 2) {
    auto f = *begin(ms);
    ms.erase(begin(ms));
    auto g = *begin(ms);
    ms.erase(begin(ms));
    ms.insert(f * g);
  }
  cout << (*begin(ms))[n / 2] << '\n';
}