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

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

template <class T> struct mini {
  T v = inf<T>;
  mini operator*(mini b) const {
    return b.v < v ? b : *this;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    segtree<mini<int>> seg(x);
    int c = 0;
    seg.set(c, {0});
    int res = -1;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      c += a;
      c %= x;
      res = max(res, i + 1 - (seg.fold(0, c) * seg.fold(c + 1, x)).v);
      seg.set(c, {min(seg[c].v, i + 1)});
    }
    cout << res << '\n';
  }
}