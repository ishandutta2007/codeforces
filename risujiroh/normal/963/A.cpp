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

constexpr long long mod = 1e9 + 9;
using mint = modular<mod>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  string s;
  cin >> s;
  mint res;
  for (int i = 0; i < k; ++i) {
    mint r = power(mint(b) / a, k);
    mint cur = power(mint(a), n - i) * power(mint(b), i);
    if (r == 1) {
      cur *= (n + 1) / k;
    } else {
      cur *= (1 - power(r, (n + 1) / k)) / (1 - r);
    }
    if (s[i] == '+') {
      res += cur;
    } else {
      res -= cur;
    }
  }
  cout << res.v << '\n';
}