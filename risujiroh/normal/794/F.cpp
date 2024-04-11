#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T, class F> struct lazy_segtree {
  const int n;
  vector<T> t;
  vector<F> d;
  lazy_segtree(int _n = 0) : n(_n), t(2 * n), d(n) {}
  T& operator[](int i) { return t[n + i]; }
  void build() { for (int i = n; i--; ) t[i] = t[2 * i] * t[2 * i + 1]; }
  void apply(int i, F f) {
    t[i] = f(t[i]);
    if (i < n) d[i] = d[i] * f;
  }
  void push(int i) {
    apply(2 * i, d[i]), apply(2 * i + 1, d[i]);
    d[i] = F();
  }
  void push_down(int i) {
    for (int h = __lg(i), tz = __builtin_ctz(i); h > tz; --h) push(i >> h);
  }
  void pull_up(int i) {
    while (i >>= 1) t[i] = t[2 * i] * t[2 * i + 1];
  }
  T fold(int l, int r) {
    push_down(l += n), push_down(r += n);
    T a, b;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = a * t[l++];
      if (r & 1) b = t[--r] * b;
    }
    return a * b;
  }
  T get(int i) { return fold(i, i + 1); }
  void act(int l, int r, F f) {
    push_down(l += n), push_down(r += n);
    for (int i = l, j = r; i < j; i >>= 1, j >>= 1) {
      if (i & 1) apply(i++, f);
      if (j & 1) apply(--j, f);
    }
    pull_up(l >> __builtin_ctz(l)), pull_up(r >> __builtin_ctz(r));
  }
  void set(int i, T a) {
    push_down(i += n), push_down(i + 1);
    t[i] = a;
    pull_up(i);
  }
};

using ll = long long;
struct node {
  array<ll, 10> c{};
  node operator*(const node& b) const {
    array<ll, 10> s{};
    for (int i = 0; i < 10; ++i) {
      s[i] = c[i] + b.c[i];
    }
    return {s};
  }
};
struct f {
  array<int8_t, 10> to{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  f operator*(const f& b) const {
    f res;
    for (int i = 0; i < 10; ++i) {
      res.to[i] = b.to[to[i]];
    }
    return res;
  }
  node operator()(const node& x) const {
    node res;
    for (int i = 0; i < 10; ++i) {
      res.c[to[i]] += x.c[i];
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  lazy_segtree<node, f> seg(n);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ll base = 1;
    while (a) {
      seg[i].c[a % 10] += base;
      a /= 10;
      base *= 10;
    }
  }
  seg.build();
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    --l;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      f e;
      e.to[x] = y;
      seg.act(l, r, e);
    } else {
      auto e = seg.fold(l, r);
      ll res = 0;
      for (int i = 0; i < 10; ++i) {
        res += i * e.c[i];
      }
      cout << res << '\n';
    }
  }
}