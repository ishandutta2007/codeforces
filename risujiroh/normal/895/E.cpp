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
  double sum = 0;
  int len = 0;
  node operator*(node b) const {
    return {sum + b.sum, len + b.len};
  }
};
struct affine {
  double a = 1, b = 0;
  affine operator*(affine g) const {
    return {a * g.a, b * g.a + g.b};
  }
  node operator()(node x) const {
    return {x.sum * a + b * x.len, x.len};
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, q;
  cin >> n >> q;
  lazy_segtree<node, affine> seg(n);
  for (int i = 0; i < n; ++i) {
    double a;
    cin >> a;
    seg[i] = {a, 1};
  }
  seg.build();
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l[2], r[2];
      cin >> l[0] >> r[0] >> l[1] >> r[1];
      --l[0], --l[1];
      double x[2];
      for (int k : {0, 1}) {
        x[k] = seg.fold(l[k], r[k]).sum / (r[k] - l[k]);
      }
      for (int k : {0, 1}) {
        auto p = 1.0 / (r[k] - l[k]);
        seg.act(l[k], r[k], {1 - p, p * x[k ^ 1]});
      }
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      cout << seg.fold(l, r).sum << '\n';
    }
  }
}