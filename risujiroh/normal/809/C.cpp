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
mint f(ll a, ll b, ll k) {
  if (a == -1 or b == -1) return 0;
  mint dp[2][2][2], num[2][2][2];
  num[1][1][1] = 1;
  for (int i = 32; i--; ) {
    mint ndp[2][2][2], nnum[2][2][2];
    for (int f : {0, 1}) {
      for (int g : {0, 1}) {
        for (int h : {0, 1}) {
          for (int x : {0, 1}) {
            for (int y : {0, 1}) {
              ll z = x ^ y;
              if (f and x > (a >> i & 1)) continue;
              if (g and y > (b >> i & 1)) continue;
              if (h and z > (k >> i & 1)) continue;
              int nf = f and x == (a >> i & 1);
              int ng = g and y == (b >> i & 1);
              int nh = h and z == (k >> i & 1);
              ndp[nf][ng][nh] += dp[f][g][h] + (z << i) * num[f][g][h];
              nnum[nf][ng][nh] += num[f][g][h];
            }
          }
        }
      }
    }
    swap(dp, ndp);
    swap(num, nnum);
  }
  mint res;
  for (int f : {0, 1}) {
    for (int g : {0, 1}) {
      for (int h : {0, 1}) {
        res += dp[f][g][h] + num[f][g][h];
      }
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    int x1, y1, x2, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    x1 -= 2, y1 -= 2;
    --x2, --y2, --k;
    mint res;
    res += f(x2, y2, k);
    res -= f(x2, y1, k);
    res -= f(x1, y2, k);
    res += f(x1, y1, k);
    cout << res.v << '\n';
  }
}