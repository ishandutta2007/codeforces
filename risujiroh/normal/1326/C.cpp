#include <bits/stdc++.h>
using namespace std;

template <unsigned M> struct modular {
  using m = modular;
  unsigned v;
  modular(long long x = 0) : v((x %= M) < 0 ? x + M : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((v += b.v) >= M) v -= M; return *this; }
  m& operator-=(m b) { if (v < b.v) v += M; v -= b.v; return *this; }
  m& operator*=(m b) {
    auto x = (uint64_t)v * b.v;
    unsigned xu = x >> 32, xl = x, d;
    asm("divl %4; \n\t" : "=a" (d), "=d" (v) : "d" (xu), "a" (xl), "r" (M));
    return *this;
  }
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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> idx;
  long long res = 0;
  mint num = 1;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    if (p >= n - k) {
      res += p + 1;
      idx.push_back(i);
    }
  }
  int m = idx.size();
  for (int t = 0; t < m - 1; ++t) {
    num *= idx[t + 1] - idx[t];
  }
  cout << res << ' ' << num.v << '\n';
}