#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

template <class T, class Op = multiplies<T>>
constexpr T power(T a, int64_t n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <uint32_t M>
struct modular {
  using T = modular;
  static constexpr uint32_t mod = M;
  uint32_t v;
  modular(int64_t x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  T operator-() const { return T() -= *this; }
  T& operator+=(T b) { return (int)(v += b.v - mod) < 0 ? v += mod : v, *this; }
  T& operator-=(T b) { return (int)(v -= b.v) < 0 ? v += mod : v, *this; }
  T& operator*=(T b) { return v = (uint64_t)v * b.v % mod, *this; }
  T& operator/=(T b) { return *this *= power(b, mod - 2); }
  friend T operator+(T a, T b) { return a += b; }
  friend T operator-(T a, T b) { return a -= b; }
  friend T operator*(T a, T b) { return a *= b; }
  friend T operator/(T a, T b) { return a /= b; }
  friend bool operator==(T a, T b) { return a.v == b.v; }
};

using mint = modular<998244353>;

vector<mint> fact, inv_fact, minv;
void prepare(int n) {
  fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? fact[i - 1] * i : 1;
  inv_fact[n] = power(fact[n], mint::mod - 2);
  for (int i = n; i--;) inv_fact[i] = (i + 1) * inv_fact[i + 1];
  for (int i = 1; i <= n; ++i) minv[i] = inv_fact[i] * fact[i - 1];
}
mint binom(int n, int k) {
  if (k < 0 or k > n) return 0;
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
template <>
mint& mint::operator/=(mint b) {
  return *this *= b.v < minv.size() ? minv[b.v] : power(b, mod - 2);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  prepare(n + m);
  vector<mint> p(n + 1);
  mint base;
  for (int k = 0; k <= n; ++k) {
    p[k] = binom(n, k) / binom(n + m, k) * m / (n + m - k);
    base += p[k] * (k + 1);
  }
  DUMP(p);
  vector<mint> ex(n + 1);
  mint cum;
  for (int i = n; i--;) {
    mint num = base;
    // for (int j = 1; j <= n - i; ++j) {
    //   mint coeff = fact[j] * fact[n + m - i - j - 1] * inv_fact[n + m - i];
    //   coeff *= m * binom(n - i, j);
    //   num += coeff * ex[i + j];
    // }
    mint x = cum;
    x *= m * fact[n - i] * inv_fact[n + m - i];
    num += x;
    ex[i] = num;
    ex[i] *= n + m - i;
    ex[i] *= minv[n - i];
    cum += fact[n + m - i - 1] * inv_fact[n - i] * ex[i];
  }
  DUMP(ex);
  cout << ex[0].v << '\n';
}