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
  int n; cin >> n;
  VV< pair<int, int> > ve(10001), ho(10001);
  for (int i = 0; i < n; ++i) {
    int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
    x0 += 5000, y0 += 5000;
    x1 += 5000, y1 += 5000;
    if (x0 == x1) {
      if (y0 > y1) swap(y0, y1);
      ve[x0].emplace_back(y0, y1);
    } else {
      if (x0 > x1) swap(x0, x1);
      ho[y0].emplace_back(x0, x1);
    }
  }
  lint res = 0;
  for (int x = 0; x <= 10000; ++x) for (auto p : ve[x]) {
    V< pair<int, int> > v;
    for (int y = p.first; y <= p.second; ++y) for (auto e : ho[y]) if (e.first <= x) {
      v.emplace_back(e.second, y);
    }
    sort(begin(v), end(v));
    FenwickTree<int> ft(10001);
    for (int r = 10000; r > x; --r) {
      while (!v.empty() and v.back().first >= r) {
        ft.add(v.back().second, 1);
        v.pop_back();
      }
      for (auto q : ve[r]) {
        lint s = ft.sum(q.first, q.second + 1);
        res += s * (s - 1) / 2;
      }
    }
  }
  cout << res << '\n';
}