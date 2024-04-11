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

struct node {
  int d = 0, l = -inf<int>;
  node operator*(node b) const {
    return {d + b.d, max(l + b.d, b.l)};
  }
  int operator()(int x) const {
    return max(x + d, l);
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> x(n, -1);
  segtree<node> seg(n);
  for (int i = 0; i < n; ++i) {
    int p, t;
    cin >> p >> t;
    --p;
    if (t == 0) {
      seg.set(p, {-1, 0});
    } else {
      cin >> x[p];
      seg.set(p, {+1, 0});
    }
    if (seg.fold(0, n)(0)) {
      int ok = 0, ng = n;
      while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        (seg.fold(mid, n)(0) ? ok : ng) = mid;
      }
      cout << x[ok] << '\n';
    } else {
      cout << "-1\n";
    }
  }
}