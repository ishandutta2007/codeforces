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

struct m32 {
  static unsigned mod, lg;
  static uint64_t r;
  static void set_mod(int _mod = mod) {
    assert(_mod >= 2);
    mod = _mod;
    lg = __lg(mod - 1);
    r = ((__uint128_t(1) << (lg + 64)) + mod - 1) / mod;
  }
  unsigned v;
  m32() : v(0) {}
  m32(long long x) : v((x %= mod) < 0 ? x + mod : x) {}
  m32 operator-() const { return m32() -= *this; }
  m32& operator+=(m32 b) {
    if ((int)(v += b.v - mod) < 0) v += mod;
    return *this;
  }
  m32& operator-=(m32 b) {
    if ((int)(v -= b.v) < 0) v += mod;
    return *this;
  }
  m32& operator*=(m32 b) {
    auto a = (uint64_t)v * b.v;
    v = a - (uint64_t)((__uint128_t(a) * r >> lg) >> 64) * mod;
    return *this;
  }
  m32& operator/=(m32 b) { return *this *= power(b, mod - 2); }
  friend m32 operator+(m32 a, m32 b) { return a += b; }
  friend m32 operator-(m32 a, m32 b) { return a -= b; }
  friend m32 operator*(m32 a, m32 b) { return a *= b; }
  friend m32 operator/(m32 a, m32 b) { return a /= b; }
  friend bool operator==(m32 a, m32 b) { return a.v == b.v; }
};
unsigned m32::mod, m32::lg;
uint64_t m32::r;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> m32::mod;
  m32::set_mod();
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  if (n == (int)m32::mod) {
    cout << "0 1\n";
    exit(0);
  }
  auto s = accumulate(begin(a), end(a), m32());
  auto s2 = accumulate(begin(a), end(a), m32(), [](m32 acc, m32 e) {
    return acc + e * e;
  });
  for (m32 x : a) {
    m32 d = (s / n - x) * 2 / (n - 1);
    if (s2 / n == x * x + x * d * (n - 1) + d * d * (n - 1) * (2 * n - 1) / 6) {
      vector<int> v(n);
      v[0] = x.v;
      for (int i = 1; i < n; ++i) {
        v[i] = (v[i - 1] + d).v;
      }
      sort(begin(v), end(v));
      if (a == v) {
        cout << x.v << ' ' << d.v << '\n';
        exit(0);
      }
    }
  }
  cout << "-1\n";
}