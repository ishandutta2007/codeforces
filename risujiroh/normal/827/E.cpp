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
  if (a.empty() or b.empty()) return {};
  int n = size(a), m = size(b), sz = 1 << __lg(2 * (n + m - 1) - 1);
  a.resize(sz), ntt(a, false);
  b.resize(sz), ntt(b, false);
  for (int i = 0; i < sz; ++i) a[i] *= b[i];
  ntt(a, true), a.resize(n + m - 1);
  return a;
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

using mint = modular<998244353>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> ok(n + 1, true);
    for (int _ = 2; _--; ) {
      vector<mint> a(n), b(n);
      for (int i = 0; i < n; ++i) {
        a[i] = s[i] == 'V';
        b[i] = s[n - i - 1] == 'K';
      }
      auto c = a * b;
      for (int k = 1; k < n; ++k) {
        for (int x = k; x < n; x += k) {
          if (c[n + x - 1].v) {
            ok[k] = false;
            break;
          }
        }
      }
      for (auto&& e : s) {
        if (e == '?') continue;
        e ^= 'V' ^ 'K';
      }
    }
    vector<int> res;
    for (int k = 1; k <= n; ++k) {
      if (ok[k]) {
        res.push_back(k);
      }
    }
    int m = size(res);
    cout << m << '\n';
    for (int i = 0; i < m; ++i) {
      cout << res[i] << " \n"[i == m - 1];
    }
  }
}