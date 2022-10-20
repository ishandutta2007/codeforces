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

using ll = long long;

constexpr ll inf = 3e12;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, p;
    cin >> n >> p;
    vector<int> k(n);
    for (auto&& e : k) cin >> e;
    sort(rbegin(k), rend(k));
    mint res;
    ll a = 0, b = 1e6;
    bool f = false;
    for (int e : k) {
      auto na = power<ll>(p, b - e, [](ll x, ll y) {
        return x <= inf / y ? x * y : inf;
      }, a);
      if (na == inf) {
        f = true;
        while (a * p < inf and b > e) {
          a *= p;
          --b;
        }
        res += a * (power<mint>(p, b) - power<mint>(p, e));
      } else {
        a = na;
      }
      b = e;
      if (f or a) {
        --a;
      } else {
        a = 1;
      }
    }
    res += a * power<mint>(p, b);
    cout << res.v << '\n';
  }
}