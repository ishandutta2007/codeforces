#include <bits/stdc++.h>
using namespace std;

template <class T> vector<T> operator-(vector<T> a) {
  for (auto&& e : a) e = -e;
  return a;
}
template <class T> vector<T>& operator+=(vector<T>& l, const vector<T>& r) {
  l.resize(max(l.size(), r.size()));
  for (int i = 0; i < (int)r.size(); ++i) l[i] += r[i];
  return l;
}
template <class T> vector<T> operator+(vector<T> l, const vector<T>& r) {
  return l += r;
}
template <class T> vector<T>& operator-=(vector<T>& l, const vector<T>& r) {
  l.resize(max(l.size(), r.size()));
  for (int i = 0; i < (int)r.size(); ++i) l[i] -= r[i];
  return l;
}
template <class T> vector<T> operator-(vector<T> l, const vector<T>& r) {
  return l -= r;
}
template <class T> vector<T>& operator<<=(vector<T>& a, size_t n) {
  return a.insert(begin(a), n, 0), a;
}
template <class T> vector<T> operator<<(vector<T> a, size_t n) {
  return a <<= n;
}
template <class T> vector<T>& operator>>=(vector<T>& a, size_t n) {
  return a.erase(begin(a), begin(a) + min(a.size(), n)), a;
}
template <class T> vector<T> operator>>(vector<T> a, size_t n) {
  return a >>= n;
}
template <class T> vector<T> operator*(const vector<T>& l, const vector<T>& r) {
  if (l.empty() or r.empty()) return {};
  vector<T> res(l.size() + r.size() - 1);
  for (int i = 0; i < (int)l.size(); ++i)
    for (int j = 0; j < (int)r.size(); ++j) res[i + j] += l[i] * r[j];
  return res;
}
template <class T> vector<T>& operator*=(vector<T>& l, const vector<T>& r) {
  return l = l * r;
}
template <class T> vector<T> inverse(const vector<T>& a) {
  assert(not a.empty() and not (a[0] == 0));
  vector<T> b{1 / a[0]};
  while (b.size() < a.size()) {
    vector<T> x(begin(a), begin(a) + min(a.size(), 2 * b.size()));
    x *= b * b;
    b.resize(2 * b.size());
    for (auto i = b.size() / 2; i < min(x.size(), b.size()); ++i) b[i] = -x[i];
  }
  return {begin(b), begin(b) + a.size()};
}
template <class T> vector<T> operator/(vector<T> l, vector<T> r) {
  if (l.size() < r.size()) return {};
  reverse(begin(l), end(l)), reverse(begin(r), end(r));
  int n = l.size() - r.size() + 1;
  l.resize(n), r.resize(n);
  l *= inverse(r);
  return {rend(l) - n, rend(l)};
}
template <class T> vector<T>& operator/=(vector<T>& l, const vector<T>& r) {
  return l = l / r;
}
template <class T> vector<T> operator%(vector<T> l, const vector<T>& r) {
  if (l.size() < r.size()) return l;
  l -= l / r * r;
  return {begin(l), begin(l) + (r.size() - 1)};
}
template <class T> vector<T>& operator%=(vector<T>& l, const vector<T>& r) {
  return l = l % r;
}
template <class T> vector<T> derivative(const vector<T>& a) {
  vector<T> res(max((int)a.size() - 1, 0));
  for (int i = 0; i < (int)res.size(); ++i) res[i] = (i + 1) * a[i + 1];
  return res;
}
template <class T> vector<T> primitive(const vector<T>& a) {
  vector<T> res(a.size() + 1);
  for (int i = 1; i < (int)res.size(); ++i) res[i] = a[i - 1] / i;
  return res;
}
template <class T> vector<T> logarithm(const vector<T>& a) {
  assert(not a.empty() and a[0] == 1);
  auto res = primitive(derivative(a) * inverse(a));
  return {begin(res), begin(res) + a.size()};
}
template <class T> vector<T> exponent(const vector<T>& a) {
  assert(a.empty() or a[0] == 0);
  vector<T> b{1};
  while (b.size() < a.size()) {
    vector<T> x(begin(a), begin(a) + min(a.size(), 2 * b.size()));
    x[0] += 1;
    b.resize(2 * b.size());
    x -= logarithm(b);
    x *= {begin(b), begin(b) + b.size() / 2};
    for (auto i = b.size() / 2; i < min(x.size(), b.size()); ++i) b[i] = x[i];
  }
  return {begin(b), begin(b) + a.size()};
}

template <class T, class F = multiplies<T>>
T power(T a, long long n, F op = multiplies<T>(), T e = {1}) {
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
  modular(long long a = 0) : v((a %= M) < 0 ? a + M : a) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m r) { if ((v += r.v) >= M) v -= M; return *this; }
  m& operator-=(m r) { if (v < r.v) v += M; v -= r.v; return *this; }
  m& operator*=(m r) { v = (uint64_t)v * r.v % M; return *this; }
  m& operator/=(m r) { return *this *= power(r, M - 2); }
  friend m operator+(m l, m r) { return l += r; }
  friend m operator-(m l, m r) { return l -= r; }
  friend m operator*(m l, m r) { return l *= r; }
  friend m operator/(m l, m r) { return l /= r; }
  friend bool operator==(m l, m r) { return l.v == r.v; }
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

constexpr long long mod = 998244353;
using mint = modular<mod>;

#ifndef LOCAL
template<> mint& mint::operator*=(mint r) {
  auto x = (uint64_t)v * r.v;
  unsigned xh = x >> 32, xl = x, d;
  asm("divl %4; \n\t" : "=a" (d), "=d" (v) : "d" (xh), "a" (xl), "r" (mod));
  return *this;
}
#endif

struct dual_vec {
  vector<mint> v;
  void resize(int sz) { v.resize(sz); }
};
dual_vec mfft(const vector<mint>& a, int sz) {
  dual_vec fa{a};
  fa.resize(sz), ntt(fa.v, false);
  return fa;
}
dual_vec operator*(dual_vec l, const dual_vec& r) {
  for (int i = 0; i < (int)l.v.size(); ++i) l.v[i] *= r.v[i];
  return l;
}
vector<mint> ifft(dual_vec fa, int n) {
  ntt(fa.v, true), fa.resize(n);
  return fa.v;
}

vector<mint> operator*(const vector<mint>& l, const vector<mint>& r) {
  if (l.empty() or r.empty()) return {};
  int n = l.size(), m = r.size(), sz = 1 << __lg(2 * (n + m - 1) - 1);
  if (min(n, m) < 30) {
    vector<long long> res(n + m - 1);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
      res[i + j] += (l[i] * r[j]).v;
    return {begin(res), end(res)};
  }
  if (l == r) {
    dual_vec fl = mfft(l, sz);
    return ifft(fl * fl, n + m - 1);
  }
  return ifft(mfft(l, sz) * mfft(r, sz), n + m - 1);
}
vector<mint> inverse(const vector<mint>& a) {
  assert(not a.empty() and not (a[0] == 0));
  vector<mint> b{1 / a[0]};
  for (int m = 1; m < (int)a.size(); m *= 2) {
    vector<mint> x(begin(a), begin(a) + min<int>(a.size(), 2 * m));
    dual_vec fb = mfft(b, 2 * m);
    x = ifft(mfft(x, 2 * m) * fb, 2 * m);
    fill(begin(x), begin(x) + m, 0);
    x = -ifft(mfft(x, 2 * m) * fb, 2 * m);
    b.insert(end(b), begin(x) + m, end(x));
  }
  return {begin(b), begin(b) + a.size()};
}
vector<mint> exponent(const vector<mint>& a) {
  assert(a.empty() or a[0] == 0);
  vector<mint> b{1, 1 < a.size() ? a[1] : 0}, c{1};
  dual_vec half_fc = mfft(c, 1), fc = mfft(c, 2);
  for (int m = 2; m < (int)a.size(); m *= 2) {
    dual_vec fb = mfft(b, 2 * m), half_fb = fb;
    half_fb.resize(m);
    half_fc = fc;
    vector<mint> z = ifft(half_fb * half_fc, m);
    fill(begin(z), begin(z) + m / 2, 0);
    z = -ifft(mfft(z, m) * half_fc, m);
    c.insert(end(c), begin(z) + m / 2, end(z));
    fc = mfft(c, 2 * m);
    vector<mint> x(begin(a), begin(a) + min<int>(a.size(), m));
    x = derivative(x), x.push_back(0);
    dual_vec fx = mfft(x, m);
    x = ifft(fx * half_fb, m);
    x -= derivative(b);
    x.resize(2 * m);
    for (int i = 0; i < m - 1; ++i) x[m + i] = x[i], x[i] = 0;
    x = ifft(mfft(x, 2 * m) * fc, 2 * m);
    x = primitive(x), x.pop_back();
    for (int i = m; i < min<int>(a.size(), 2 * m); ++i) x[i] += a[i];
    fill(begin(x), begin(x) + m, 0);
    x = ifft(mfft(x, 2 * m) * fb, 2 * m);
    b.insert(end(b), begin(x) + m, end(x));
  }
  return {begin(b), begin(b) + a.size()};
}

vector<mint> inverse_square_root(const vector<mint>& a) {
  assert(not a.empty() and a[0] == 1);
  vector<mint> b{1};
  for (int m = 1; m < (int)a.size(); m *= 2) {
    vector<mint> x(begin(a), begin(a) + min<int>(a.size(), 2 * m));
    vector<mint> y = b;
    x.resize(4 * m), ntt(x, false);
    y.resize(4 * m), ntt(y, false);
    for (int i = 0; i < 4 * m; ++i) x[i] *= y[i] * y[i] * y[i];
    ntt(x, true);
    auto inv = 1 / mint(-2);
    for (int i = m; i < 2 * m; ++i) x[i] *= inv;
    b.insert(end(b), begin(x) + m, begin(x) + 2 * m);
  }
  return {begin(b), begin(b) + a.size()};
}

vector<mint> fact, inv_fact, minv;
void prepare(int n) {
  fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? i * fact[i - 1] : 1;
  inv_fact[n] = power(fact[n], mod - 2);
  for (int i = n; i; --i) inv_fact[i - 1] = i * inv_fact[i];
  for (int i = 1; i <= n; ++i) minv[i] = inv_fact[i] * fact[i - 1];
}
mint binom(int n, int k) {
  if (k < 0 or k > n) return 0;
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
template<> mint& mint::operator/=(mint r) {
  return *this *= r.v < minv.size() ? minv[r.v] : power(r, mod - 2);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  prepare(2 * m);
  vector<mint> c(m + 1);
  while (n--) {
    int x;
    cin >> x;
    if (x <= m) {
      c[x] = 1;
    }
  }
  auto $ = [](mint a) {
    return vector<mint>{a};
  };
  int s = find_if_not(begin(c), end(c), [](mint e) { return e == 0; }) - begin(c);
  if (s == m + 1) {
    while (m--) {
      cout << "0\n";
    }
    exit(0);
  }
  c.resize(m + 1 + s);
  vector<mint> num = $(1) - inverse(inverse_square_root($(1) - $(4) * c));
  vector<mint> den = $(2) * c;
  num >>= s;
  den >>= s;
  vector<mint> a = num * inverse(den);
  for (int i = 1; i <= m; ++i) {
    cout << a[i].v << '\n';
  }
}