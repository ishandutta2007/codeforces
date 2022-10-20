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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  fenwick<int> ft(n);
  while (n--) {
    int a;
    cin >> a;
    --a;
    ft.add(a, 1);
  }
  while (q--) {
    int k;
    cin >> k;
    if (k < 0) {
      k = -k;
      --k;
      ft.add(ft.kth(k), -1);
    } else {
      --k;
      ft.add(k, 1);
    }
  }
  if (ft.sum(0, ft.n)) {
    cout << ft.kth(0) + 1 << '\n';
  } else {
    cout << "0\n";
  }
}