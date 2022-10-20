#include <bits/stdc++.h>
using namespace std;

template <class T> struct FenwickTree {
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
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto&& e : a) {
      cin >> e;
      --e;
    }
    vector<bool> ex(n);
    for (auto&& e : b) {
      cin >> e;
      --e;
      ex[e] = true;
    }
    vector<int> ia(n);
    for (int i = 0; i < n; ++i) {
      ia[a[i]] = i;
    }
    long long res = m;
    int mi = -1;
    FenwickTree<int> ft(n);
    for (int i = 0; i < n; ++i) {
      ft.add(i, 1);
    }
    for (int j = 0; j < m; ++j) {
      int i = ia[b[j]];
      if (i > mi) {
        res += 2 * ft.sum(i);
        mi = i;
      }
      ft.add(i, -1);
    }
    cout << res << '\n';
  }
}