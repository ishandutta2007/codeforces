#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> vector<T> operator-(vector<T> a) {
  for (auto&& e : a) e = -e;
  return a;
}
template <class T> vector<T>& operator+=(vector<T>& a, const vector<T>& b) {
  a.resize(max(a.size(), b.size()));
  for (int i = 0; i < (int)b.size(); ++i) a[i] += b[i];
  return a;
}
template <class T> vector<T> operator+(vector<T> a, const vector<T>& b) {
  return a += b;
}
template <class T> vector<T>& operator-=(vector<T>& a, const vector<T>& b) {
  a.resize(max(a.size(), b.size()));
  for (int i = 0; i < (int)b.size(); ++i) a[i] -= b[i];
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
  return a.erase(begin(a), begin(a) + min(a.size(), n)), a;
}
template <class T> vector<T> operator>>(vector<T> a, size_t n) {
  return a >>= n;
}
template <class T> vector<T> operator*(const vector<T>& a, const vector<T>& b) {
  if (a.empty() or b.empty()) return {};
  vector<T> res(a.size() + b.size() - 1);
  for (int i = 0; i < (int)a.size(); ++i)
    for (int j = 0; j < (int)b.size(); ++j) res[i + j] += a[i] * b[j];
  return res;
}
template <class T> vector<T>& operator*=(vector<T>& a, const vector<T>& b) {
  return a = a * b;
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
template <class T> vector<T> operator/(vector<T> a, vector<T> b) {
  if (a.size() < b.size()) return {};
  reverse(begin(a), end(a)), reverse(begin(b), end(b));
  int n = a.size() - b.size() + 1;
  a.resize(n), b.resize(n);
  a *= inverse(b);
  return {rend(a) - n, rend(a)};
}
template <class T> vector<T>& operator/=(vector<T>& a, const vector<T>& b) {
  return a = a / b;
}
template <class T> vector<T> operator%(vector<T> a, const vector<T>& b) {
  if (a.size() < b.size()) return a;
  a -= a / b * b;
  return {begin(a), begin(a) + (b.size() - 1)};
}
template <class T> vector<T>& operator%=(vector<T>& a, const vector<T>& b) {
  return a = a % b;
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

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  static constexpr unsigned mod = M;
  using m = modular;
  unsigned v;
  modular(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((v += b.v) >= mod) v -= mod; return *this; }
  m& operator-=(m b) { if (v < b.v) v += mod; v -= b.v; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return *this; }
  m& operator/=(m b) { return *this *= power(b, mod - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
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

vector<int> p, a, b;
int n, m;

template <unsigned M>
vector<int> fn() {
  using mint = modular<M>;
  int sz = 1 << __lg(2 * (n + m - 1) - 1);
  // vector<vector<mint>> pa(5), pb(3), pp(3);
  // for (int k = 0; k <= 4; ++k) {
  //   pa[k].resize(sz);
  //   for (int i = 0; i < sz; ++i) {
  //     pa[k][i] = power<mint>(a[i], k);
  //   }
  //   ntt(pa[k], false);
  //   if (k > 2) {
  //     continue;
  //   }
  //   pb[k].resize(sz);
  //   pp[k].resize(sz);
  //   for (int j = 0; j < m; ++j) {
  //     pb[k][j] = power<mint>(b[j], k);
  //     pp[k][j] = power<mint>(p[b[j]], k);
  //   }
  //   ntt(pb[k], false);
  //   ntt(pp[k], false);
  // }
  // array<array<int, 4>, 3> cs{
  //   1, 2, 0, 0,
  //   -2, 1, 1, 0,
  //   1, 1, 2, 0
  // };
  array<array<int, 4>, 9> cs{
    1, 4, 0, 0,
    -2, 3, 0, 1,
    1, 2, 0, 2,
    -2, 3, 1, 0,
    4, 2, 1, 1,
    -2, 1, 1, 2,
    1, 2, 2, 0,
    -2, 1, 2, 1,
    1, 0, 2, 2
  };
  vector<mint> s;
  for (auto [c, ea, eb, ep] : cs) {
    vector<mint> x(n), y(m);
    for (int i = 0; i < n; ++i) {
      x[i] = power<mint>(a[i], ea);
    }
    for (int j = 0; j < m; ++j) {
      y[j] = power<mint>(b[j], eb) * power(p[b[j]], ep);
    }
    s += vector<mint>{c} * x * y;
  }
  DEBUG(s);
  vector<int> res(n - m + 1);
  for (int i = 0; i < n - m + 1; ++i) {
    res[i] = s[i + m - 1].v == 0;
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  p.resize(26);
  for (auto&& e : p) {
    cin >> e;
    --e;
  }
  string s, t;
  cin >> s >> t;
  n = t.size(), m = s.size();
  a.resize(n), b.resize(m);
  for (int i = 0; i < n; ++i) {
    a[i] = t[i] - 'a';
  }
  for (int j = 0; j < m; ++j) {
    b[j] = s[m - j - 1] - 'a';
  }
  DEBUG(a);
  DEBUG(b);
  array<vector<int>, 2> r{fn<1300234241>(), fn<1484783617>()};
  for (int i = 0; i < (int)r[0].size(); ++i) {
    cout << r[0][i] * r[1][i];
  }
  cout << '\n';
}