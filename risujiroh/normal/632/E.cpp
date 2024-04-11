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
using Mint = ModInt<2013265921>;
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
    for (int k = lg - 1; k; --k) {
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

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<> a(n); for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  a.erase(unique(begin(a), end(a)), end(a));
  V<Mint> f(a.back() + 1);
  for (int e : a) f[e] = 1;
  NTT::ntt(f, NTT::A, 1 << 20);
  for (int i = 0; i < 1 << 20; ++i) NTT::A[i] = NTT::A[i].pow(k);
  NTT::intt(NTT::A, 1 << 20);
  V<> res;
  for (int i = 0; i <= 1000 * k; ++i) if (NTT::A[i]) {
    res.push_back(i);
  }
  int m = res.size();
  for (int i = 0; i < m; ++i) {
    cout << res[i] << " \n"[i == m - 1];
  }
}