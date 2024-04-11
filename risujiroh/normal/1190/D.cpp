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
  T get(int i) const { return sum(i, i + 1); }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> x(n), y(n); for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  {
    auto xs = x;
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
    for (auto&& e : x) e = lower_bound(begin(xs), end(xs), e) - begin(xs);
    auto ys = y;
    sort(begin(ys), end(ys));
    ys.erase(unique(begin(ys), end(ys)), end(ys));
    for (auto&& e : y) e = lower_bound(begin(ys), end(ys), e) - begin(ys);
  }
  VV<> xs(n);
  for (int i = 0; i < n; ++i) {
    xs[y[i]].push_back(x[i]);
  }
  for (auto&& v : xs) sort(begin(v), end(v));
  lint res = 0;
  FenwickTree<int> ft(n);
  for (int a = n - 1; a >= 0; --a) if (!xs[a].empty()) {
    auto v = xs[a];
    v.insert(begin(v), -1);
    v.push_back(n);
    int m = v.size();
    for (int i = 0; i + 1 < m; ++i) {
      lint s = ft.sum(v[i] + 1, v[i + 1]);
      res -= s * (s + 1) / 2;
    }
    for (int e : xs[a]) {
      if (!ft.get(e)) ft.add(e, 1);
    }
    lint s = ft.sum(0, n);
    res += s * (s + 1) / 2;
  }
  cout << res << '\n';
}