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

struct node {
  long long lv = -1, rv = -1;
  int sz, llen, rlen, mx, lmx, rmx;
  node operator*(const node& b) const {
    if (lv == -1) {
      return b;
    }
    if (b.lv == -1) {
      return *this;
    }
    node res;
    res.lv = lv, res.rv = b.rv;
    res.sz = sz + b.sz;
    res.llen = llen;
    if (llen == sz and rv > b.lv) {
      res.llen = sz + b.llen;
    }
    res.rlen = b.rlen;
    if (b.rlen == b.sz and rv < b.lv) {
      res.rlen = rlen + b.sz;
    }
    res.mx = max(mx, b.mx);
    if (rv < b.lv) {
      res.mx = max(res.mx, rlen + b.lmx);
    }
    if (rv > b.lv) {
      res.mx = max(res.mx, rmx + b.llen);
    }
    res.lmx = lmx;
    if (rlen == sz and rv < b.lv) {
      res.lmx = max(res.lmx, sz + b.lmx);
    }
    if (lmx == sz and rv > b.lv) {
      res.lmx = max(res.lmx, sz + b.llen);
    }
    res.rmx = b.rmx;
    if (b.llen == b.sz and rv > b.lv) {
      res.rmx = max(res.rmx, rmx + b.sz);
    }
    if (b.rmx == b.sz and rv < b.lv) {
      res.rmx = max(res.rmx, rlen + b.sz);
    }
    return res;
  }
};
struct add {
  long long v = 0;
  add operator*(add g) const {
    return {v + g.v};
  }
  node operator()(node x) const {
    x.lv += v;
    x.rv += v;
    return x;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  lazy_segtree<node, add> seg(n);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    seg[i] = {a, a, 1, 1, 1, 1, 1, 1};
  }
  seg.build();
  int q;
  cin >> q;
  while (q--) {
    int l, r, d;
    cin >> l >> r >> d;
    --l;
    seg.act(l, r, {d});
    auto e = seg.fold(0, n);
    cout << e.mx << '\n';
  }
}