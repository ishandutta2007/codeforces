#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T, class Op = multiplies<T>>
constexpr T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <class T> vector<T> operator-(vector<T> a) {
  for (auto&& e : a) e = -e;
  return a;
}
template <class T> vector<T>& operator+=(vector<T>& a, const vector<T>& b) {
  a.resize(max(size(a), size(b)));
  for (int i = 0; i < (int)size(b); ++i) a[i] += b[i];
  return a;
}
template <class T> vector<T> operator+(vector<T> a, const vector<T>& b) {
  return a += b;
}
template <class T> vector<T>& operator-=(vector<T>& a, const vector<T>& b) {
  a.resize(max(size(a), size(b)));
  for (int i = 0; i < (int)size(b); ++i) a[i] -= b[i];
  return a;
}
template <class T> vector<T> operator-(vector<T> a, const vector<T>& b) {
  return a -= b;
}
template <class T> vector<T>& operator<<=(vector<T>& a, size_t n) {
  return a.insert(begin(a), n, 0), a;
}
template <class T> vector<T> operator<<(vector<T> a, size_t n) {
  return a <<= n;
}
template <class T> vector<T>& operator>>=(vector<T>& a, size_t n) {
  return a.erase(begin(a), begin(a) + min(size(a), n)), a;
}
template <class T> vector<T> operator>>(vector<T> a, size_t n) {
  return a >>= n;
}
// template <class T> vector<T> operator*(const vector<T>& a, const vector<T>& b) {
//   if (empty(a) or empty(b)) return {};
//   vector<T> res(size(a) + size(b) - 1);
//   for (int i = 0; i < (int)size(a); ++i)
//     for (int j = 0; j < (int)size(b); ++j) res[i + j] += a[i] * b[j];
//   return res;
// }
template <class T> vector<T>& operator*=(vector<T>& a, const vector<T>& b) {
  return a = a * b;
}
template <class T> vector<T> inverse(const vector<T>& a) {
  assert(not empty(a) and not (a[0] == 0));
  vector<T> b{1 / a[0]};
  while (size(b) < size(a)) {
    vector<T> x(begin(a), begin(a) + min(size(a), 2 * size(b)));
    x *= b * b;
    b.resize(2 * size(b));
    for (auto i = size(b) / 2; i < min(size(x), size(b)); ++i) b[i] = -x[i];
  }
  return {begin(b), begin(b) + size(a)};
}
template <class T> vector<T> operator/(vector<T> a, vector<T> b) {
  if (size(a) < size(b)) return {};
  reverse(begin(a), end(a)), reverse(begin(b), end(b));
  int n = size(a) - size(b) + 1;
  a.resize(n), b.resize(n);
  a *= inverse(b);
  return {rend(a) - n, rend(a)};
}
template <class T> vector<T>& operator/=(vector<T>& a, const vector<T>& b) {
  return a = a / b;
}
template <class T> vector<T> operator%(vector<T> a, const vector<T>& b) {
  if (size(a) < size(b)) return a;
  a -= a / b * b;
  return {begin(a), begin(a) + (size(b) - 1)};
}
template <class T> vector<T>& operator%=(vector<T>& a, const vector<T>& b) {
  return a = a % b;
}
template <class T> vector<T> derivative(const vector<T>& a) {
  vector<T> res(max((int)size(a) - 1, 0));
  for (int i = 0; i < (int)size(res); ++i) res[i] = (i + 1) * a[i + 1];
  return res;
}
template <class T> vector<T> primitive(const vector<T>& a) {
  vector<T> res(size(a) + 1);
  for (int i = 1; i < (int)size(res); ++i) res[i] = a[i - 1] / i;
  return res;
}
template <class T> vector<T> logarithm(const vector<T>& a) {
  assert(not empty(a) and a[0] == 1);
  auto res = primitive(derivative(a) * inverse(a));
  return {begin(res), begin(res) + size(a)};
}
template <class T> vector<T> exponent(const vector<T>& a) {
  assert(empty(a) or a[0] == 0);
  vector<T> b{1};
  while (size(b) < size(a)) {
    vector<T> x(begin(a), begin(a) + min(size(a), 2 * size(b)));
    x[0] += 1;
    b.resize(2 * size(b));
    x -= logarithm(b);
    x *= {begin(b), begin(b) + size(b) / 2};
    for (auto i = size(b) / 2; i < min(size(x), size(b)); ++i) b[i] = x[i];
  }
  return {begin(b), begin(b) + size(a)};
}

template <class T> void ntt(vector<T>& a, bool inverse) {
  int n = size(a);
  assert((n & (n - 1)) == 0);
  if (n < 2) return;
  assert((T::mod - 1) % n == 0);
  static vector<T> w{1}, iw{1};
  for (int m = size(w); m < n / 2; m *= 2) {
    static T root = 2;
    while (power(root, (T::mod - 1) / 2) == 1) root += 1;
    T dw = power(root, (T::mod - 1) / (4 * m)), idw = 1 / dw;
    w.resize(2 * m), iw.resize(2 * m);
    for (int i = 0; i < m; ++i) w[m + i] = w[i] * dw, iw[m + i] = iw[i] * idw;
  }
  if (not inverse) {
    for (int m = n; m >>= 1; ) {
      for (int s = 0, k = 0; s < n; s += 2 * m, ++k) {
        for (int i = s, j = s + m; i < s + m; ++i, ++j) {
          T x = a[i], y = a[j] * w[k];
          a[i] = x + y, a[j] = x - y;
        }
      }
    }
  } else {
    for (int m = 1; m < n; m *= 2) {
      for (int s = 0, k = 0; s < n; s += 2 * m, ++k) {
        for (int i = s, j = s + m; i < s + m; ++i, ++j) {
          T x = a[i], y = a[j];
          a[i] = x + y, a[j] = (x - y) * iw[k];
        }
      }
    }
    auto inv = 1 / T(n);
    for (auto&& e : a) e *= inv;
  }
}
template <class T> vector<T> operator*(vector<T> a, vector<T> b) {
  if (empty(a) or empty(b)) return {};
  int n = size(a), m = size(b), sz = 1 << __lg(2 * (n + m - 1) - 1);
  if (min(n, m) < 30) {
    vector<T> c(n + m - 1);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        c[i + j] += a[i] * b[j];
    return c;
  }
  a.resize(sz), ntt(a, false);
  b.resize(sz), ntt(b, false);
  for (int i = 0; i < sz; ++i) a[i] *= b[i];
  ntt(a, true), a.resize(n + m - 1);
  return a;
}

template <class T> vector<T> bm(const vector<T>& a) {
  T d = 1;
  vector<T> c{1}, nc{1};
  int n = a.size(), k = 0, m = 1;
  for (int i = 0; i < n; ++i) {
    T nd = inner_product(rbegin(nc), rend(nc), begin(a) + (i - k), (T)0);
    if (nd == 0) ++m;
    else if (2 * k <= i) {
      auto t = nc;
      nc -= vector<T>{nd / d} * (c << m);
      c = t, d = nd;
      k = i + 1 - k, m = 1;
    } else {
      nc -= vector<T>{nd / d} * (c << m);
      ++m;
    }
  }
  return {rbegin(nc), rend(nc)};
}
template <class T> T guess_kth(const vector<T>& a, long long k) {
  auto c = bm(a);
  auto b = power(vector<T>{0, 1}, k, [&](const auto& l, const auto& r) {
    return l * r % c;
  });
  return inner_product(begin(b), end(b), begin(a), (T)0);
}

template <unsigned M> struct modular {
  using m = modular;
  static constexpr unsigned mod = M;
  unsigned v;
  modular(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((int)(v += b.v - mod) < 0) v += mod; return *this; }
  m& operator-=(m b) { if ((int)(v -= b.v) < 0) v += mod; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return *this; }
  m& operator/=(m b) { return *this *= power(b, mod - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
};

using mint = modular<power(10, 9) + 7>;

vector<mint> fact, inv_fact, minv;
void prepare(int n) {
  fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? fact[i - 1] * i : 1;
  inv_fact[n] = power(fact[n], mint::mod - 2);
  for (int i = n; i--; ) inv_fact[i] = (i + 1) * inv_fact[i + 1];
  for (int i = 1; i <= n; ++i) minv[i] = inv_fact[i] * fact[i - 1];
}
mint binom(int n, int k) {
  if (k < 0 or k > n) return 0;
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
template <> mint& mint::operator/=(mint b) {
  return *this *= b.v < minv.size() ? minv[b.v] : power(b, mod - 2);
}

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

vector<mint> pw;
mint f(int n) {
  mint res;
  for (int k = 0; k <= n; ++k) {
    res += binom(n, k) * pw[k];
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  prepare(1e5);
  for (int k = 0; k < 1e5; ++k) {
    pw.push_back(power<mint>(k, m));
  }
  vector<mint> a;
  for (int i = 0; i < 2 * m + 10; ++i) {
    a.push_back(f(i));
  }
  cout << guess_kth(a, n).v << '\n';
}