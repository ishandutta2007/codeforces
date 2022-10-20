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
  int sz = 0;
  array<char, 2> cl, cr;
  array<int, 2> nl, nr;
  int mx, rev_mx;
  friend node operator*(const node& a, const node& b) {
    if (a.sz == 0) {
      return b;
    }
    if (b.sz == 0) {
      return a;
    }
    node c;
    c.sz = a.sz + b.sz;
    c.cl = a.cl, c.nl = a.nl;
    c.cr = b.cr, c.nr = b.nr;
    if (a.nl[0] == a.sz) {
      if (b.cl[0] == a.cl[0]) {
        c.nl[0] += b.nl[0];
        c.cl[1] = b.cl[1], c.nl[1] = b.nl[1];
      } else {
        c.cl[1] = b.cl[0], c.nl[1] = b.nl[0];
      }
    } else if (a.nl[0] + a.nl[1] == a.sz) {
      if (a.cl[1] == b.cl[0]) {
        c.nl[1] += b.nl[0];
      }
    }
    if (b.nr[0] == b.sz) {
      if (a.cr[0] == b.cr[0]) {
        c.nr[0] += a.nr[0];
        c.cr[1] = a.cr[1], c.nr[1] = a.nr[1];
      } else {
        c.cr[1] = a.cr[0], c.nr[1] = a.nr[0];
      }
    } else if (b.nr[0] + b.nr[1] == b.sz) {
      if (b.cr[1] == a.cr[0]) {
        c.nr[1] += a.nr[0];
      }
    }
    c.mx = max(a.mx, b.mx);
    c.rev_mx = max(a.rev_mx, b.rev_mx);
    if (a.cr[0] == '>' and b.cl[0] == '<') {
      c.mx = max(c.mx, a.nr[0] + b.nl[0]);
    } else if (a.cr[0] == '>') {
      if (b.nl[0] < b.sz) {
        c.mx = max(c.mx, a.nr[0] + b.nl[0] + b.nl[1]);
      }
      if (a.nr[0] < a.sz) {
        c.rev_mx = max(c.rev_mx, a.nr[1] + a.nr[0] + b.nl[0]);
      }
    } else if (b.cl[0] == '<') {
      if (a.nr[0] < a.sz) {
        c.mx = max(c.mx, a.nr[1] + a.nr[0] + b.nl[0]);
      }
      if (b.nl[0] < b.sz) {
        c.rev_mx = max(c.rev_mx, a.nr[0] + b.nl[0] + b.nl[1]);
      }
    } else {
      c.rev_mx = max(c.rev_mx, a.nr[0] + b.nl[0]);
    }
    return c;
  }
};
struct flip {
  bool v = false;
  flip operator*(flip g) const {
    return {v ^ g.v};
  }
  node operator()(node x) const {
    if (not v) {
      return x;
    }
    for (auto&& e : x.cl) if (e != '?') e ^= '<' ^ '>';
    for (auto&& e : x.cr) if (e != '?') e ^= '<' ^ '>';
    swap(x.mx, x.rev_mx);
    return x;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  lazy_segtree<node, flip> seg(n);
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    seg[i] = {1, {c, '?'}, {c, '?'}, {1, 0}, {1, 0}, 0, 0};
  }
  seg.build();
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    seg.act(l, r, {true});
    auto e = seg.fold(l, r);
    int res = e.mx;
    if (e.cl[0] == '<') {
      res = max(res, e.nl[0]);
    }
    if (e.cr[0] == '>') {
      res = max(res, e.nr[0]);
    }
    cout << res << '\n';
  }
}