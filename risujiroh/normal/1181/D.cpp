#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

#pragma GCC target ("avx")
struct Bitvector {
  using T = uint32_t;
  static constexpr int W = 32;
  static int popcnt(T x) { return __builtin_popcount(x); }

  const int n;
  V<T> b;
  V<> c;
  Bitvector(int n) : n(n), b(n / W + 1), c(n / W + 1) {}
  void set(int i) { b[i / W] |= (T)1 << i % W; }
  void build() { for (int i = 0; i < n / W; ++i) c[i + 1] = c[i] + popcnt(b[i]); }
  bool operator[](int i) const { return b[i / W] >> i % W & 1; }
  int rank(int i) const { return c[i / W] + popcnt(b[i / W] & ~(~(T)0 << i % W)); }
  int rank(bool v, int i) const { return v ? rank(i) : i - rank(i); }
};
template<class T> struct WaveletMatrix {
  const int n, h;
  V<Bitvector> b;
  V<> z;
  template<class Itr> WaveletMatrix(Itr first, Itr last) :
    n(distance(first, last)), h(__lg(2 * *max_element(first, last) + 1)), b(h, Bitvector(n)), z(h) {
    assert(*min_element(first, last) >= 0);
    V<T> a(first, last), na(n);
    for (int j = 0; j < h; ++j) {
      for (int i = 0; i < n; ++i) {
        if (a[i] >> h + ~j & 1) b[j].set(i);
        else ++z[j];
      }
      b[j].build();
      int p = 0, q = z[j];
      for (int i = 0; i < n; ++i) (b[j][i] ? na[q++] : na[p++]) = a[i];
      swap(a, na);
    }
  }
  T operator[](int i) const {
    T res = 0;
    for (int j = 0; j < h; ++j) {
      T v = b[j][i];
      res |= v << h + ~j;
      i = v * z[j] + b[j].rank(v, i);
    }
    return res;
  }
  int rank(int l, int r, T x) const {
    if (x < 0 or x >= (T)1 << h) return 0;
    for (int j = 0; j < h; ++j) {
      int v = x >> h + ~j & 1;
      l = v * z[j] + b[j].rank(v, l);
      r = v * z[j] + b[j].rank(v, r);
    }
    return r - l;
  }
  T kth(int l, int r, int k) const {
    assert(0 <= k and k < r - l);
    T res = 0;
    for (int j = 0; j < h; ++j) {
      int p = b[j].rank(0, l), q = b[j].rank(0, r);
      T v = k >= q - p;
      k -= v * (q - p);
      res |= v << h + ~j;
      l = v * z[j] + (v ? l - p : p);
      r = v * z[j] + (v ? r - q : q);
    }
    return res;
  }
  T rkth(int l, int r, int k) const { return kth(l, r, r - l + ~k); }
  int cnt(int l, int r, T x) const {
    if ((x = max<T>(x, 0)) >= (T)1 << h) return 0;
    int res = 0;
    for (int j = 0; j < h; ++j) {
      int p = b[j].rank(1, l), q = b[j].rank(1, r);
      int v = x >> h + ~j & 1;
      res += !v * (q - p);
      l = v * z[j] + (v ? p : l - p);
      r = v * z[j] + (v ? q : r - q);
    }
    return res + r - l;
  }
  int cnt(int l, int r, T x, T y) const { return cnt(l, r, x) - cnt(l, r, y); }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m, q; cin >> n >> m >> q;
  V<> a(m);
  for (int _ = 0; _ < n; ++_) {
    int i; cin >> i, --i;
    ++a[i];
  }
  int mx = *max_element(begin(a), end(a));
  lint c = (lint)mx * m - n;
  WaveletMatrix<int> wm(begin(a), end(a));
  V<lint> b(mx + 1);
  for (int i = 1; i <= mx; ++i) b[i] = b[i - 1] + wm.cnt(0, m, 0, i);
  while (q--) {
    lint k; cin >> k, k -= n + 1;
    if (k >= c) {
      cout << (k - c) % m + 1 << '\n';
    } else {
      int j = prev(upper_bound(begin(b), end(b), k)) - begin(b);
      k -= b[j];
      int ok = 0, ng = m;
      while (ng - ok > 1) {
        int mid = ok + ng >> 1;
        (wm.cnt(0, mid, 0, j + 1) <= k ? ok : ng) = mid;
      }
      cout << ok + 1 << '\n';
    }
  }
}