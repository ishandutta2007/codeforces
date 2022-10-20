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

template <class T> struct maxi {
  T v = -inf<T>;
  maxi operator*(maxi b) const {
    return v < b.v ? b : *this;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  segtree<maxi<int>> seg(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    seg[i] = {a[i]};
  }
  seg.build();
  vector<int> res(n + 1);
  for (int i = 0; 2 * i + 2 <= n; ++i) {
    res[2 * i + 2] = seg.fold(i, n - i).v;
  }
  res[1] = seg.fold(0, n).v;
  for (int i = 0; i < n - 1; ++i) {
    seg[i] = {min(a[i], a[i + 1])};
  }
  seg.build();
  for (int i = 0; 2 * i + 3 <= n; ++i) {
    res[2 * i + 3] = seg.fold(i, n - 1 - i).v;
  }
  for (int i = n; i; --i) {
    cout << res[i] << " \n"[i == 1];
  }
}