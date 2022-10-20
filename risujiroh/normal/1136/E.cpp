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
template<class T> struct AddSumTree {
  const int n;
  FenwickTree<T> d, e;
  AddSumTree(int n) : n(n), d(n), e(n) {}
  void add(int l, int r, T x) {
    d.add(l, x), e.add(l, l * x);
    if (r < n) d.add(r, -x), e.add(r, -r * x);
  }
  T sum(int i) const { return i * d.sum(i) - e.sum(i); }
  T sum(int l, int r) const { return sum(r) - sum(l); }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  V<> k(n - 1); for (auto&& e : k) cin >> e;
  AddSumTree<lint> t(n);
  map<int, lint> mp;
  for (int i = 0; i < n; ++i) {
    t.add(i, i + 1, a[i]);
    if (i + 1 < n and a[i + 1] - a[i] - k[i] > 0) mp[i] = a[i + 1] - a[i] - k[i];
  }
  auto query = [&](const auto& query, int i, lint x) -> void {
    if (x == 0) return;
    auto itr = mp.lower_bound(i);
    if (itr == end(mp)) {
      t.add(i, n, x);
      return;
    }
    int j = itr->first;
    t.add(i, j + 1, x);
    if (x < itr->second) {
      itr->second -= x;
      return;
    }
    x -= itr->second;
    mp.erase(itr);
    query(query, j + 1, x);
  };
  int q; cin >> q;
  while (q--) {
    char c; cin >> c;
    if (c == '+') {
      int i, x; cin >> i >> x, --i;
      if (i > 0) mp[i - 1] += x;
      query(query, i, x);
    } else {
      int l, r; cin >> l >> r, --l;
      cout << t.sum(l, r) << '\n';
    }
  }
}