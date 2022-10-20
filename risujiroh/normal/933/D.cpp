#include <bits/stdc++.h>
using namespace std;

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
  friend string to_string(m a) { return to_string(a.v); }
};

constexpr long long mod = 1e9 + 7;
using mint = modular<mod>;

vector<mint> fact, inv_fact, minv;
void prepare(int n) {
  fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? i * fact[i - 1] : 1;
  inv_fact[n] = power(fact[n], mod - 2);
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

mint sum(long long sqn, int d) {
  long long x = max<long long>(sqrt(sqn) - 10, 0);
  while ((x + 1) * (x + 1) <= sqn) {
    ++x;
  }
  mint n = x;
  if (d == 0) return n + 1;
  if (d == 1) return n * (n + 1) / 2;
  if (d == 2) return n * (n + 1) * (2 * n + 1) / 6;
  if (d == 3) return n * n * (n + 1) * (n + 1) / 4;
  if (d == 4) return n * (n + 1) * (2 * n + 1) * (3 * n * n + 3 * n - 1) / 30;
  if (d == 5) return n * n * (n + 1) * (n + 1) * (2 * n * n + 2 * n - 1) / 12;
  assert(d == 6);
  return n * (n + 1) * (2 * n + 1) * (3 * n * n * n * n + 6 * n * n * n - 3 * n + 1) / 42;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  prepare(1e6);
  vector<mint> s(4);
  for (int d = 0; d <= 3; ++d) {
    for (long long x = 1; x * x <= n; ++x) {
      for (int i = 0; i <= d; ++i) {
        s[d] += binom(d, i) * power<mint>(x, 2 * i) * sum(n - x * x, 2 * (d - i));
      }
    }
    s[d] *= 4;
    s[d] += d == 0;
  }
  mint m = n, m2 = m * m, m3 = m * m2;
  mint res;
  res += (m3 + 3 * m2 + 2 * m) / 6 * s[0];
  res += (3 * m + 4) / 6 * s[1];
  res -= (m + 2) / 2 * s[2];
  res += s[3] / 3;
  cout << res.v << '\n';
}