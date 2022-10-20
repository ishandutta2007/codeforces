#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

template <class T, class Op = multiplies<T>>
constexpr T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <class T>
void ntt(vector<T>& a, bool inverse) {
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
    for (int m = n; m >>= 1;) {
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
template <class T>
vector<T> operator*(vector<T> a, vector<T> b) {
  if (empty(a) or empty(b)) return {};
  int n = size(a), m = size(b), sz = 1 << __lg(2 * (n + m - 1) - 1);
  a.resize(sz), ntt(a, false);
  b.resize(sz), ntt(b, false);
  for (int i = 0; i < sz; ++i) a[i] *= b[i];
  ntt(a, true), a.resize(n + m - 1);
  return a;
}

template <unsigned M>
struct modular {
  using m = modular;
  static constexpr unsigned mod = M;
  unsigned v;
  modular(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) {
    if ((int)(v += b.v - mod) < 0) v += mod;
    return *this;
  }
  m& operator-=(m b) {
    if ((int)(v -= b.v) < 0) v += mod;
    return *this;
  }
  m& operator*=(m b) {
    v = (uint64_t)v * b.v % mod;
    return *this;
  }
  m& operator/=(m b) { return *this *= power(b, mod - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
};

auto operator*(const vector<long long>& a, const vector<long long>& b) {
  if (empty(a) or empty(b)) return vector<long long>();
  int n = size(a), m = size(b);
  using mint0 = modular<1300234241>;
  using mint1 = modular<1484783617>;
  vector<mint0> a0(n), b0(m);
  vector<mint1> a1(n), b1(m);
  for (int i = 0; i < n; ++i) a0[i] = a[i], a1[i] = a[i];
  for (int j = 0; j < m; ++j) b0[j] = b[j], b1[j] = b[j];
  a0 = a0 * b0, a1 = a1 * b1;
  static const mint1 im0 = 1 / mint1(mint0::mod);
  vector<long long> res(n + m - 1);
  for (int i = 0; i < n + m - 1; ++i) {
    long long y0 = a0[i].v, y1 = (im0 * (a1[i] - y0)).v;
    res[i] = y0 + mint0::mod * y1;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  constexpr int lim = 5e5;
  vector<vector<int>> divisors(lim + 1);
  for (int d = lim; d; --d) {
    for (int i = d; i <= lim; i += d) {
      divisors[i].push_back(d);
    }
  }
  int n, x, y;
  cin >> n >> x >> y;
  constexpr int off = 2e5;
  vector<long long> f(off + 1), g(off + 1);
  for (int _ = n + 1; _--;) {
    int a;
    cin >> a;
    ++f[a];
    ++g[off - a];
  }
  f = f * g;
  f.resize(lim + off + 1);
  int q;
  cin >> q;
  while (q--) {
    int l;
    cin >> l;
    l /= 2;
    int res = -1;
    for (int d : divisors[l]) {
      if (d <= y) continue;
      if (f[off + d - y]) {
        res = 2 * d;
        break;
      }
    }
    cout << res << " \n"[q == 0];
  }
}