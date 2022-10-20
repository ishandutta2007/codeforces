#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class T> struct FenwickTree {
  const int n;
  V<T> t;
  FenwickTree(int n) : n(n), t(n + 1) {}
  void add(int i, T x) { for (++i; i <= n; i += i & -i) t[i] += x; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> x(m); for (auto&& e : x) cin >> e, --e;
  VV<> v(n);
  for (int j = 0; j < m - 1; ++j) {
    if (x[j] == x[j + 1]) continue;
    v[x[j]].push_back(x[j + 1]);
    v[x[j + 1]].push_back(x[j]);
  }

  V<lint> res(n);
  for (int j = 0; j < m - 1; ++j) {
    res[0] += abs(x[j + 1] - x[j]);
  }

  FenwickTree<int> ft(n);
  for (int e : v[0]) {
    ft.add(e, 1);
  }
  for (int i = 1; i < n; ++i) {
    res[i] = res[0];
    res[i] -= ft.sum(i + 1, n);
    for (int e : v[i]) {
      if (e < i) {
        res[i] -= i - e;
        res[i] += e + 1;
      } else {
        res[i] -= e - i;
        res[i] += e;
      }
    }
    for (int e : v[i]) {
      ft.add(e, 1);
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << res[i] << " \n"[i == n - 1];
  }
}