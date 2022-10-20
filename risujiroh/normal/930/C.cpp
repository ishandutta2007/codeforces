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

template <class T> struct max_monoid {
  T v = 0;
  max_monoid operator*(max_monoid b) const {
    return v < b.v ? b : *this;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(m + 1);
  while (n--) {
    int l, r;
    cin >> l >> r;
    --l;
    ++a[l];
    --a[r];
  }
  for (int i = 0; i < m; ++i) {
    a[i + 1] += a[i];
  }
  a.pop_back();
  DEBUG(a);
  segtree<max_monoid<int>> segl(m), segr(m);
  {
    vector<int> ord(m);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) {
      return a[i] != a[j] ? a[i] < a[j] : i > j;
    });
    for (int i : ord) {
      segr.set(i, {1 + segr.fold(i + 1, m).v});
    }
  }
  {
    vector<int> ord(m);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) {
      return a[i] != a[j] ? a[i] < a[j] : i < j;
    });
    for (int i : ord) {
      segl.set(i, {segl.fold(0, i).v + 1});
    }
  }
  int res = -1;
  for (int i = 0; i < m; ++i) {
    res = max(res, segl[i].v + segr[i].v - 1);
  }
  cout << res << '\n';
}