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

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

template <class T> struct node {
  T mx = -inf<T>;
  node operator*(node b) const {
    return {max(mx, b.mx)};
  }
};
template <class T> struct affine_clamp {
  T a = 1, b = 0, l = -inf<T>, u = inf<T>;
  auto operator*(affine_clamp g) const {
    auto f = *this;
    f.a *= g.a;
    f.b = f.b * g.a + g.b;
    f.l = f.l * g.a + g.b;
    f.u = f.u * g.a + g.b;
    if (f.l > f.u) swap(f.l, f.u);
    f.l = clamp(f.l, g.l, g.u);
    f.u = clamp(f.u, g.l, g.u);
    return f;
  }
  node<T> operator()(node<T> x) const {
    x.mx = clamp(x.mx * a + b, l, u);
    return x;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  vector<long long> p(n);
  for (auto&& e : p) {
    cin >> e;
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (auto&& e : b) {
    cin >> e;
  }
  lazy_segtree<node<long long>, affine_clamp<long long>> seg(m);
  for (int i = 0; i < n; ++i) {
    int j = lower_bound(begin(b), end(b), a[i]) - begin(b);
    if (j == m) {
      continue;
    }
    if (p[i] > 0) {
      seg.act(j, m, {1, p[i], -inf<long long>, inf<long long>});
    }
    if (a[i] == b[j]) {
      if (j == 0) {
        seg.set(0, {max(seg.get(0).mx, p[i])});
      } else {
        seg.set(j, {max(seg.get(j).mx, seg.get(j - 1).mx + p[i])});
      }
    }
  }
  auto res = accumulate(begin(p), end(p), 0LL);
  res -= seg.get(m - 1).mx;
  if (res >= 1e15) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";
  cout << res << '\n';
}