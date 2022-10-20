#include <bits/stdc++.h>
using namespace std;

unsigned mod = 2;
struct mint {
  using m = mint;
  unsigned v;
  mint(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((v += b.v) >= mod) v -= mod; return *this; }
  m& operator-=(m b) { if (v < b.v) v += mod; v -= b.v; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return *this; }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
  friend string to_string(m a) { return to_string(a.v); }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int d;
    cin >> d >> mod;
    int k = __lg(d);
    mint res = 1;
    for (int i = 0; i < k; ++i) {
      res *= (1 << i) + 1;
    }
    res *= d - (1 << k) + 2;
    res -= 1;
    cout << res.v << '\n';
  }
}