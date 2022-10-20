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
  m& operator*=(m b) { v = (uint64_t)v * b.v % M; return *this; }
  m& operator/=(m b) { return *this *= power(b, M - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
  friend string to_string(m a) { return to_string(a.v); }
};

constexpr long long mod = 998244353;
using mint = modular<mod>;

using mat = array<array<mint, 2>, 2>;
mat operator*(const mat& a, const mat& b) {
  mat c;
  for (int i : {0, 1}) {
    for (int k : {0, 1}) {
      for (int j : {0, 1}) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return c;
}
mat id = {1, 0, 0, 1};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  long long n, m, l, r;
  cin >> n >> m >> l >> r;
  ++r;
  if (n & 1 and m & 1) {
    cout << power(mint(r - l), n * m).v << '\n';
    exit(0);
  }
  long long even = (r - l) / 2, odd = (r - l) / 2;
  if ((r - l) & 1) {
    ++(l & 1 ? odd : even);
  }
  mat a{
    even, odd,
    odd, even
  };
  a = power(a, n * m, multiplies<>(), id);
  cout << a[0][0].v << '\n';
}