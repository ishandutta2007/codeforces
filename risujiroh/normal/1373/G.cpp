#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> struct fenwick {
  int n;
  vector<T> t;
  fenwick(int _n = -1) : n(_n), t(n + 1) {}
  void add(int i, T a) { for (++i; i <= n; i += i & -i) t[i] += a; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
  int kth(T k) const {
    int i = 0;
    for (int w = 1 << __lg(n); w; w >>= 1)
      if (i + w <= n and t[i + w] <= k) k -= t[i += w];
    return i;
  }
};

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

struct maxi {
  int v = -inf<int>;
  maxi operator*(maxi b) const {
    return v < b.v ? b : *this;
  }
};
struct add {
  int v = 0;
  add operator*(add g) const {
    return {v + g.v};
  }
  maxi operator()(maxi x) const {
    return {x.v + v};
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k, m;
  cin >> n >> k >> m;
  --k;
  vector<int> x(m), y(m);
  map<pair<int, int>, int> mp;
  vector<pair<int, int>> v;
  vector<int> tp(m);
  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i];
    --x[i], --y[i];
    if (mp.count({x[i], y[i]})) {
      mp.erase({x[i], y[i]});
      tp[i] = 1;
    } else {
      mp[{x[i], y[i]}] = i;
      v.emplace_back(y[i] + abs(x[i] - k), i);
    }
  }
  sort(begin(v), end(v));
  int sz = size(v);
  vector<int> pos(m);
  for (int t = 0; t < sz; ++t) {
    pos[v[t].second] = t;
  }
  fenwick<int> ft(sz);
  lazy_segtree<maxi, add> seg(sz);
  for (int i = 0; i < m; ++i) {
    int z = y[i] + abs(x[i] - k);
    if (tp[i] == 0) {
      ft.add(pos[i], 1);
      seg.set(pos[i], {z + (ft.sum(pos[i] + 1, sz) + 1)});
      seg.act(0, pos[i], {1});
      mp[{x[i], y[i]}] = i;
    } else {
      int p = pos[mp[{x[i], y[i]}]];
      ft.add(p, -1);
      seg.set(p, maxi());
      seg.act(0, p, {-1});
    }
    int res = seg.fold(0, sz).v;
    cout << max(res - n, 0) << '\n';
  }
}