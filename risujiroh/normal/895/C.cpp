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
};

constexpr long long mod = 1e9 + 7;
using mint = modular<mod>;

vector<int> sieve(int n) {
  vector<bool> b(n / 3 + 1, true);
  vector<int> res{2, 3};
  for (int p = 5, d = 4; p * p <= n; p += d = 6 - d) if (b[p / 3])
    for (int i = p * p, di = p % 3 * 2 * p; i <= n; i += di = 6 * p - di)
      b[i / 3] = false;
  for (int p = 5, d = 4; p <= n; p += d = 6 - d) if(b[p / 3]) res.push_back(p);
  while (not res.empty() and res.back() > n) res.pop_back();
  return res;
}

template <class Z> map<Z, int> factorize(Z n) {
  map<Z, int> res;
  for (Z i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector cnt(71, 0);
  while (n--) {
    int a;
    cin >> a;
    ++cnt[a];
  }
  auto ps = sieve(70);
  int m = ps.size();
  DEBUG(m);
  vector<mint> dp(1 << m);
  dp[0] = 1;
  for (n = 1; n <= 70; ++n) {
    if (cnt[n] == 0) {
      continue;
    }
    vector<mint> ndp(1 << m);
    auto c = power<mint>(2, cnt[n] - 1);
    int x = 0;
    for (auto [p, e] : factorize(n)) {
      if (e & 1) {
        x |= 1 << (lower_bound(begin(ps), end(ps), p) - begin(ps));
      }
    }
    for (int bt = 0; bt < 1 << m; ++bt) {
      ndp[bt] += dp[bt] * c;
      ndp[bt ^ x] += dp[bt] * c;
    }
    swap(dp, ndp);
  }
  auto res = dp[0] - 1;
  cout << res.v << '\n';
}