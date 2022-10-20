#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> struct segtree {
  const int n;
  vector<T> t;
  segtree(int _n = 0) : n(_n), t(2 * n) {}
  T& operator[](int i) { return t[n + i]; }
  void build() { for (int i = n; i--; ) t[i] = t[2 * i] * t[2 * i + 1]; }
  T fold(int l, int r) const {
    T a, b;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = a * t[l++];
      if (r & 1) b = t[--r] * b;
    }
    return a * b;
  }
  void set(int i, T a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = t[2 * i] * t[2 * i + 1];
  }
};

struct mini {
  int v = 1e9, i = -1;
  mini operator*(mini b) const {
    return b.v < v ? b : *this;
  }
};

template <class T> struct fenwick {
  const int n;
  vector<T> t;
  fenwick(int _n = -1) : n(_n), t(n + 1) {}
  void add(int i, T a) { for (++i; i <= n; i += i & -i) t[i] += a; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
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
  segtree<mini> seg(2 * n);
  fenwick<int> ft(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    seg[i] = {a[i % n], i};
    ft.add(i, 1);
  }
  seg.build();
  auto res = 0LL;
  int l = 0;
  for (int _ = n; _--; ) {
    int i = seg.fold(l, l + n).i;
    res += ft.sum(l, i + 1);
    DEBUG(l, i);
    i %= n;
    seg.set(i, mini());
    seg.set(n + i, mini());
    ft.add(i, -1);
    ft.add(n + i, -1);
    l = (i + 1) % n;
  }
  cout << res << '\n';
}