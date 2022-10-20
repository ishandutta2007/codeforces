#include <bits/stdc++.h>
using namespace std;

template<class T> struct FenwickTree {
  const int n;
  vector<T> t;
  FenwickTree(int _n) : n(_n), t(n + 1) {}
  void add(int i, T x) { for (++i; i <= n; i += i & -i) t[i] += x; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
  int lower_bound(T s) const {
    if (s <= 0) return 0;
    int i = 0;
    for (int k = 1 << __lg(n); k; k >>= 1) {
      if (i + k <= n and t[i + k] < s) s -= t[i += k];
    }
    return i + 1;
  }
  int kth(T k) const { return lower_bound(k + 1) - 1; }
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
  int m;
  cin >> m;
  vector<int> k(m), pos(m);
  for (int j = 0; j < m; ++j) {
    cin >> k[j] >> pos[j];
    --pos[j];
  }
  vector<int> js(m);
  iota(begin(js), end(js), 0);
  sort(begin(js), end(js), [&](int l, int r) {
    return k[l] < k[r];
  });
  vector<int> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) {
    return a[i] != a[j] ? a[i] > a[j] : i < j;
  });
  int t = 0;
  FenwickTree<int> ft(n);
  vector<int> res(m);
  for (int j : js) {
    while (t < k[j]) {
      ft.add(idx[t], 1);
      ++t;
    }
    res[j] = a[ft.kth(pos[j])];
  }
  for (int e : res) {
    cout << e << '\n';
  }
}