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

using mint = modular<998244353>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto&& e : a) cin >> e;
  for (auto&& e : b) cin >> e;
  if (*min_element(begin(a), end(a)) != *min_element(begin(b), end(b))) {
    cout << "0\n";
    exit(0);
  }
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    mp[a[i]] = i;
  }
  vector<int> pos(m);
  for (int j = 0; j < m; ++j) {
    if (not mp.count(b[j])) {
      cout << "0\n";
      exit(0);
    }
    pos[j] = mp[b[j]];
  }
  DEBUG(pos);
  if (not is_sorted(begin(pos), end(pos))) {
    cout << "0\n";
    exit(0);
  }
  if (*min_element(begin(a) + pos.back(), end(a)) != b.back()) {
    cout << "0\n";
    exit(0);
  }
  mint res = 1;
  for (int j = 0; j < m - 1; ++j) {
    int r = pos[j];
    while (r < pos[j + 1] and a[r] >= b[j]) {
      ++r;
    }
    int l = pos[j + 1];
    while (l - 1 > pos[j] and a[l - 1] >= b[j + 1]) {
      --l;
    }
    res *= max(r - l + 1, 0);
  }
  cout << res.v << '\n';
}