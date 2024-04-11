#include <bits/stdc++.h>
using namespace std;

unsigned mod = 2;
struct mint {
  using m = mint;
  unsigned v;
  mint(long long a = 0) : v((a %= mod) < 0 ? a + mod : a) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m r) { if ((v += r.v) >= mod) v -= mod; return *this; }
  m& operator-=(m r) { if (v < r.v) v += mod; v -= r.v; return *this; }
  m& operator*=(m r) { v = (uint64_t)v * r.v % mod; return *this; }
  friend m operator+(m l, m r) { return l += r; }
  friend m operator-(m l, m r) { return l -= r; }
  friend m operator*(m l, m r) { return l *= r; }
  friend bool operator==(m l, m r) { return l.v == r.v; }
  friend string to_string(m a) { return to_string(a.v); }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), c(m);
  for (auto&& e : a) {
    cin >> e;
    if (c[e % m]) {
      cout << "0\n";
      exit(0);
    }
    ++c[e % m];
  }
  assert(n <= m);
  mod = m;
  mint res = 1;
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < j; ++i) {
      res *= abs(a[j] - a[i]);
    }
  }
  cout << res.v << '\n';
}