#include <bits/stdc++.h>
using namespace std;

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = multiplies<T>(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  using m = modular;
  unsigned v;
  modular(long long x = 0) : v((x %= M) < 0 ? x + M : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((v += b.v) >= M) v -= M; return *this; }
  m& operator-=(m b) { if (v < b.v) v += M; v -= b.v; return *this; }
  m& operator*=(m b) {
    auto x = (uint64_t)v * b.v;
    unsigned xu = x >> 32, xl = x, d;
    asm("divl %4; \n\t" : "=a" (d), "=d" (v) : "d" (xu), "a" (xl), "r" (M));
    return *this;
  }
  m& operator/=(m b) { return *this *= power(b, M - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
  friend string to_string(m a) { return to_string(a.v); }
};

template <unsigned M> void ntt(vector<modular<M>>& a, bool inverse) {
  static vector<modular<M>> dw(30), idw(30);
  if (dw[0] == 0) {
    modular<M> root = 2;
    while (power(root, (M - 1) / 2) == 1) root += 1;
    for (int i = 0; i < 30; ++i)
      dw[i] = -power(root, (M - 1) >> (i + 2)), idw[i] = 1 / dw[i];
  }
  int n = a.size();
  assert((n & (n - 1)) == 0);
  if (not inverse) {
    for (int m = n; m >>= 1; ) {
      modular<M> w = 1;
      for (int s = 0, k = 0; s < n; s += 2 * m) {
        for (int i = s, j = s + m; i < s + m; ++i, ++j) {
          auto x = a[i], y = a[j] * w;
          if (x.v >= M) x.v -= M;
          a[i].v = x.v + y.v, a[j].v = x.v + (M - y.v);
        }
        w *= dw[__builtin_ctz(++k)];
      }
    }
  } else {
    for (int m = 1; m < n; m *= 2) {
      modular<M> w = 1;
      for (int s = 0, k = 0; s < n; s += 2 * m) {
        for (int i = s, j = s + m; i < s + m; ++i, ++j) {
          auto x = a[i], y = a[j];
          a[i] = x + y, a[j].v = x.v + (M - y.v), a[j] *= w;
        }
        w *= idw[__builtin_ctz(++k)];
      }
    }
  }
  auto c = 1 / modular<M>(inverse ? n : 1);
  for (auto&& e : a) e *= c;
}
template <unsigned M>
vector<modular<M>> operator*(vector<modular<M>> a, vector<modular<M>> b) {
  if (a.empty() or b.empty()) return {};
  int n = a.size(), m = b.size(), sz = 1 << __lg(2 * (n + m - 1) - 1);
  if (min(n, m) < 30) {
    vector<long long> res(n + m - 1);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
      res[i + j] += (a[i] * b[j]).v;
    return {begin(res), end(res)};
  }
  bool eq = a == b;
  a.resize(sz), ntt(a, false);
  if (eq) b = a;
  else b.resize(sz), ntt(b, false);
  for (int i = 0; i < sz; ++i) a[i] *= b[i];
  ntt(a, true), a.resize(n + m - 1);
  return a;
}

unsigned mod = 2;
struct mint {
  using m = mint;
  unsigned v;
  mint(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((v += b.v) >= mod) v -= mod; return *this; }
  m& operator-=(m b) { if (v < b.v) v += mod; v -= b.v; return *this; }
  m& operator*=(m b) {
    auto x = (uint64_t)v * b.v;
    unsigned xu = x >> 32, xl = x, d;
    asm("divl %4; \n\t" : "=a" (d), "=d" (v) : "d" (xu), "a" (xl), "r" (mod));
    return *this;
  }
  m& operator/=(m b) { return *this *= power(b, mod - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
  friend string to_string(m a) { return to_string(a.v); }
};

vector<mint> operator*(const vector<mint>& a, const vector<mint>& b) {
  if (a.empty() or b.empty()) return {};
  int n = a.size(), m = b.size();
  static constexpr int mod0 = 998244353, mod1 = 1300234241, mod2 = 1484783617;
  using mint0 = modular<mod0>;
  using mint1 = modular<mod1>;
  using mint2 = modular<mod2>;
  vector<mint0> a0(n), b0(m);
  vector<mint1> a1(n), b1(m);
  vector<mint2> a2(n), b2(m);
  for (int i = 0; i < n; ++i) a0[i] = a[i].v, a1[i] = a[i].v, a2[i] = a[i].v;
  for (int j = 0; j < m; ++j) b0[j] = b[j].v, b1[j] = b[j].v, b2[j] = b[j].v;
  a0 = a0 * b0, a1 = a1 * b1, a2 = a2 * b2;
  static const mint1 im0 = 1 / mint1(mod0);
  static const mint2 im1 = 1 / mint2(mod1), im0m1 = im1 / mod0;
  static const mint m0 = mod0, m0m1 = m0 * mod1;
  vector<mint> res(n + m - 1);
  for (int i = 0; i < n + m - 1; ++i) {
    int y0 = a0[i].v;
    int y1 = (im0 * (a1[i] - y0)).v;
    int y2 = (im0m1 * (a2[i] - y0) - im1 * y1).v;
    res[i] = y0 + m0 * y1 + m0m1 * y2;
  }
  return res;
}

char buf[1 << 24], *ptr0 = buf, *ptr1 = buf;
char get_char() {
  if (ptr0 == ptr1) ptr0 = buf, ptr1 = buf + fread(buf, 1, 1 << 24, stdin);
  return *ptr0++;
}
template <class Z> Z getint() {
  char c = get_char();
  bool neg = c == '-';
  Z res = neg ? 0 : c - '0';
  while (isdigit(c = get_char())) res = res * 10 + (c - '0');
  return neg ? -res : res;
}

int main() {
  int n = getint<int>();
  int m = getint<int>();
  mod = getint<int>();
  vector<mint> a(n), b(m);
  generate(begin(a), end(a), [] { return getint<int>(); });
  generate(begin(b), end(b), [] { return getint<int>(); });
  auto c = a * b;
  for (int i = 0; ; ++i) {
    if (c[i].v) {
      cout << i << '\n';
      exit(0);
    }
  }
}