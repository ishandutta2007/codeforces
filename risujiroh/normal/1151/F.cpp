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
using Mint = ModInt<(unsigned) 1e9 + 7>;
string to_frac(Mint x) {
  static map< int, pair<int, int> > mp;
  if (mp.empty()) {
    mp[0] = mp[Mint::p()] = {0, 1};
    for (int b = 2; b <= 1000; ++b) {
      for (int a = 1; a < b; ++a) if (__gcd(a, b) == 1) {
        mp[(Mint(a) / b).v] = {a, b};
      }
    }
  }
  auto itr = mp.lower_bound(x.v);
  if (itr != begin(mp) and x.v - prev(itr)->first < itr->first - x.v) --itr;
  auto res = to_string(itr->second.first + itr->second.second * ((int) x.v - itr->first));
  if (itr->second.second > 1) {
    res += '/';
    res += to_string(itr->second.second);
  }
  return res;
}

template<class T> VV<T> operator*(const VV<T>& A, const VV<T>& B) {
  assert(A[0].size() == B.size());
  VV<T> res(A.size(), V<T>(B[0].size()));
  for (int i = 0; i < (int) A.size(); ++i) for (int k = 0; k < (int) A[0].size(); ++k) for (int j = 0; j < (int) B[0].size(); ++j) {
    res[i][j] += A[i][k] * B[k][j];
  }
  return res;
}
template<class T> V<T> operator*(const VV<T>& A, const V<T>& x) {
  assert(A[0].size() == x.size());
  V<T> res(A.size());
  for (int i = 0; i < (int) A.size(); ++i) {
    res[i] = inner_product(begin(A[i]), end(A[i]), begin(x), (T) 0);
  }
  return res;
}
template<class T> VV<T>& operator*=(VV<T>& A, const VV<T>& B) { return A = A * B; }
template<class T> VV<T> I(int n) {
  VV<T> res(n, V<T>(n));
  for (int i = 0; i < n; ++i) res[i][i] = 1;
  return res;
}
template<class T> VV<T> pow(VV<T> A, lint n) {
  auto res = I<T>(A.size());
  while (n) {
    if (n & 1) res *= A;
    A *= A;
    n >>= 1;
  }
  return res;
}

// Ax=b(A_{ij}=a_{i+j})O(n^2)
template<class T> V<T> levinson_durbin(const V<T>& a, const V<T>& b) {
  assert(a.size() == 2 * b.size() - 1);
  int n = b.size();
  if (!a[n - 1]) return {};
  V<T> p(n), q(n), x(n);
  p.back() = q[0] = 1 / a[n - 1];
  x.back() = b[0] / a[n - 1];
  for (int k = 1; k < n; ++k) {
    T ep = inner_product(begin(a) + n, begin(a) + n + k, begin(p) + n - k, (T) 0);
    T eq = inner_product(begin(a) + n - 1 - k, begin(a) + n - 1, begin(q), (T) 0);
    T e = inner_product(begin(a) + n, begin(a) + n + k, begin(x) + n - k, (T) 0);
    if (!(1 - ep * eq)) {
      for (int i = 0; i < n; ++i) {
        if (inner_product(begin(a) + i, begin(a) + i + n, begin(x), (T) 0) != b[i]) {
          return {};
        }
      }
      return x;
    }
    T c = 1 / (1 - ep * eq);
    for (int i = 0; i <= k; ++i) {
      T tp = i ? p[n - 1 - k + i] : 0, tq = i < k ? q[i] : 0;
      tie(p[n - 1 - k + i], q[i]) = make_pair(c * (tp - ep * tq), c * (tq - eq * tp));
      x[n - 1 - k + i] += (b[k] - e) * q[i];
    }
  }
  return x;
}
// aO(n^2)
template<class T> V<T> restore_coeff(const V<T>& a) {
  int k = a.size() >> 1;
  while (k) {
    auto c = levinson_durbin(V<T>(begin(a), begin(a) + 2 * k - 1), V<T>(begin(a) + k, begin(a) + 2 * k));
    auto chk = [&]() -> bool {
      for (int i = 0; i + k < (int) a.size(); ++i) {
        if (inner_product(begin(c), end(c), begin(a) + i, (T) 0) != a[i + k]) {
          return false;
        }
      }
      return true;
    };
    if (!c.empty() and chk()) {
      int i = 0;
      while (i < k and !c[i] and inner_product(begin(c) + i + 1, end(c), begin(a), (T) 0) == a[k - 1 - i]) ++i;
      return V<T>(begin(c) + i, end(c));
    }
    --k;
  }
  return {};
}

template<class Z> Z rng(Z a, Z b) {
  static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<Z>(a, b - 1)(mt);
}

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
template<int K = 15> void multiply(V<Mint>& a, const V<Mint>& b) {
  if (a.empty() or b.empty()) {
    a = {};
    return;
  }
  int n = 1 << __lg(2 * (a.size() + b.size() - 1) - 1);
  V<C> f(n), g(n);
  for (int i = 0; i < n; ++i) {
    if (i < (int) a.size()) f[i].real(a[i].v & ~(~0 << K)), f[i].imag(a[i].v >> K);
    if (i < (int) b.size()) g[i].real(b[i].v & ~(~0 << K)), g[i].imag(b[i].v >> K);
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
    a[i] = l + m * Mint(1 << K) + u * Mint(1 << 2 * K);
  }
}
template<class T> struct Polynomial {
  using P = Polynomial;
  V<T> c;
  Polynomial(const V<T>& c) : c(c) { shrink(); }
  void shrink() { while (!c.empty() and !c.back()) c.pop_back(); }
  int size() const { return c.size(); }
  void resize(int n) { c.resize(n); }
  T at(int i) const { return 0 <= i and i < size() ? c[i] : 0; }
  const T& operator[](int i) const { return c[i]; }
  T& operator[](int i) { return c[i]; }
  P operator*(const P& r) const { return P(*this) *= r; }
  P operator*(const T& r) const { return P(*this) *= r; }
  P operator/(const P& r) const { return P(*this) /= r; }
  P operator%(const P& r) const { return P(*this) %= r; }
  P operator+(const P& r) const { return P(*this) += r; }
  P operator-(const P& r) const { return P(*this) -= r; }
  P& operator*=(const T& r) { for (auto&& e : c) e *= r; shrink(); return *this; }
  P& operator*=(const P& r) { multiply(c, r.c); return *this; }
  P& operator/=(const P& r) {
    if (size() < r.size()) return *this = {{}};
    int n = size() - r.size() + 1;
    *this = rev() * r.rev().inv(n);
    resize(n);
    reverse(begin(c), end(c));
    return *this;
  }
  P& operator%=(const P& r) {
    *this -= *this / r * r;
    shrink();
    return *this;
  }
  P& operator+=(const P& r) {
    if (r.size() > size()) c.resize(r.size());
    for (int i = 0; i < r.size(); ++i) c[i] += r[i];
    shrink();
    return *this;
  }
  P& operator-=(const P& r) {
    if (r.size() > size()) c.resize(r.size());
    for (int i = 0; i < r.size(); ++i) c[i] -= r[i];
    shrink();
    return *this;
  }
  P rev() const {
    P res = *this;
    reverse(begin(res.c), end(res.c));
    res.shrink();
    return res;
  }
  P inv(int n) const {
    if (n == 1) {
      assert(!c.empty() and c[0]);
      return {{1 / c[0]}};
    }
    P res = *this;
    res.resize(n);
    P i = res.inv(n + 1 >> 1);
    res = i * (T) 2 - i * i * res;
    res.resize(n);
    res.shrink();
    return res;
  }
  P pow(int n) const {
    P res({1}), a = *this;
    while (n) {
      if (n & 1) res *= a;
      a *= a;
      n >>= 1;
    }
    return res;
  }
  P pow_mod(int n, const P& p) const {
    P res({1}), a = *this;
    while (n) {
      if (n & 1) (res *= a) %= p;
      (a *= a) %= p;
      n >>= 1;
    }
    return res;
  }
};
using P = Polynomial<Mint>;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<> a(n); for (auto&& e : a) cin >> e;
  int z = n - accumulate(begin(a), end(a), 0);
  VV<Mint> A(z + 1, V<Mint>(z + 1));
  int m = n * (n - 1) / 2;
  for (int j = 0; j <= z; ++j) {
    A[j][j] = 1;
    if (j) {
      A[j - 1][j] = Mint(j) * j / m;
      A[j][j] -= A[j - 1][j];
    }
    if (j < z) {
      A[j + 1][j] = Mint(z - j) * (n - z - j) / m;
      A[j][j] -= A[j + 1][j];
    }
  }
  int x = accumulate(begin(a), begin(a) + z, 0);
  V<Mint> b(z + 1);
  b[x] = 1;
  V<Mint> r(z + 1);
  for (int i = 0; i <= z; ++i) r[i] = rng<int>(1, Mint::p());
  V<Mint> p;
  for (int i = 0; i < 3 * (z + 1); ++i) {
    p.push_back(inner_product(begin(r), end(r), begin(b), Mint(0)));
    b = A * b;
  }
  auto c = restore_coeff(p);
  c.push_back(-1);
  auto f = P({0, 1}).pow_mod(k, P(c));
  Mint res;
  b.assign(z + 1, 0);
  b[x] = 1;
  for (int i = 0; i < f.size(); ++i) {
    res += f[i] * b[0];
    b = A * b;
  }
  cout << res << '\n';
}