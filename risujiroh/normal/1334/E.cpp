#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

struct mint64 {
  static uint64_t mod;
  using m = mint64;
  uint64_t v;
  mint64(__int128_t x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((v += b.v) >= mod) v -= mod; return *this; }
  m& operator-=(m b) { if (v < b.v) v += mod; v -= b.v; return *this; }
  m& operator*=(m b) { v = (__uint128_t)v * b.v % mod; return *this; }
  m& operator/=(m b) { return *this *= power(b, mod - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
};

uint64_t mint64::mod = 2;

bool miller_rabin(long long n) {
  if (n < 2) return false;
  if (n % 2 == 0) return n == 2;
  mint64::mod = n;
  int tz = __builtin_ctzll(n - 1);
  for (mint64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    a = power(a, (n - 1) >> tz);
    if (a.v < 2) continue;
    bool ok = false;
    for (int _ = tz; _--; a *= a) ok |= a == -1;
    if (not ok) return false;
  }
  return true;
}

long long rho(long long n) {
  if (n % 2 == 0) return 2;
  mint64::mod = n;
  auto f = [](mint64 x) { return x * x + 1; };
  for (int x1 = 0; ; ++x1)
    for (mint64 x = x1, y = f(x); ; x = f(x), y = f(f(y))) {
      auto d = gcd<long long>((y - x).v, n);
      if (1 < d and d < n) return d;
      if (d == n) break;
    }
}
vector<long long> factorize(long long n) {
  if (n == 1) return {};
  if (miller_rabin(n)) return {n};
  auto d = rho(n);
  auto res = factorize(d);
  for (auto e : factorize(n / d)) res.push_back(e);
  return res;
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

using mint = modular<998244353>;

vector<mint> fact, inv_fact, minv;
void prepare(int n) {
  fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? i * fact[i - 1] : 1;
  inv_fact[n] = power(fact[n], mint::mod - 2);
  for (int i = n; i; --i) inv_fact[i - 1] = inv_fact[i] * i;
  for (int i = 1; i <= n; ++i) minv[i] = fact[i - 1] * inv_fact[i];
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
  long long n;
  cin >> n;
  auto ps = factorize(n);
  sort(begin(ps), end(ps));
  ps.erase(unique(begin(ps), end(ps)), end(ps));
  DEBUG(ps);
  prepare(60);
  auto fn = [&](auto x) {
    mint res = 1;
    int s = 0;
    for (auto p : ps) {
      int c = 0;
      while (x % p == 0) {
        x /= p;
        ++c;
      }
      res *= inv_fact[c];
      s += c;
    }
    res *= fact[s];
    return res;
  };
  int q;
  cin >> q;
  while (q--) {
    long long a, b;
    cin >> a >> b;
    auto c = gcd(a, b);
    a /= c, b /= c;
    cout << (fn(a) * fn(b)).v << '\n';
  }
}