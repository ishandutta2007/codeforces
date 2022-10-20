#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

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

int n, k;
template <int B = 128> struct sqrt_dec {
  struct block {
    int lazy = 0;
    vector<mint> s;
    block() : s(2 * B + 1) {}
  };
  int m = n / B + 1;
  vector<mint> a;
  vector<int> h;
  vector<block> b;
  sqrt_dec() : a(n + 1), h(n + 1), b(m) {}
  void build(int j) {
    b[j].lazy = 0;
    fill(begin(b[j].s), end(b[j].s), 0);
    for (int i = B * j; i < min(B * (j + 1), n + 1); ++i) {
      b[j].s[B + (h[i] - h[B * j])] += a[i];
    }
    partial_sum(begin(b[j].s), end(b[j].s), begin(b[j].s));
  }
  void push(int j) {
    for (int i = B * j; i < min(B * (j + 1), n + 1); ++i) {
      h[i] += b[j].lazy;
    }
    b[j].lazy = 0;
  }
  void add(int l, int r, int x) {
    if (l % B) {
      push(l / B);
      while (l < r and l % B) {
        h[l] += x;
        ++l;
      }
      build((l - 1) / B);
    }
    if (r % B) {
      push(r / B);
      while (l < r and r % B) {
        --r;
        h[r] += x;
      }
      build(r / B);
    }
    for (; l < r; l += B) {
      b[l / B].lazy += x;
    }
  }
  void set(int i, mint x) {
    push(i / B);
    a[i] = x;
    build(i / B);
  }
  mint sum(int l, int r) {
    mint res;
    if (l % B) {
      push(l / B);
      while (l < r and l % B) {
        if (h[l] <= k) {
          res += a[l];
        }
        ++l;
      }
      build((l - 1) / B);
    }
    if (r % B) {
      push(r / B);
      while (l < r and r % B) {
        --r;
        if (h[r] <= k) {
          res += a[r];
        }
      }
      build(r / B);
    }
    for (; l < r; l += B) {
      int j = l / B;
      int t = B + (k - h[B * j] - b[j].lazy);
      if (t >= 0) {
        res += b[j].s[min(t, 2 * B)];
      }
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> k;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
    --e;
  }
  sqrt_dec sd;
  sd.set(n, 1);
  vector idx(n, vector(2, n));
  for (int i = n; i--; ) {
    idx[a[i]].insert(begin(idx[a[i]]), i);
    sd.add(idx[a[i]][0] + 1, n + 1, 1);
    sd.add(idx[a[i]][1] + 1, n + 1, -2);
    sd.add(idx[a[i]][2] + 1, n + 1, 1);
    idx[a[i]].pop_back();
    sd.set(i, sd.sum(i + 1, n + 1));
  }
  sd.push(0);
  cout << sd.a[0].v << '\n';
}