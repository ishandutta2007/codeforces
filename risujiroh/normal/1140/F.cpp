#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct UnionFind {
  const int n;
  struct D { int par, xsz, ysz; };
  V<D> t;
  V< pair<int, D> > his;
  lint sum = 0;
  UnionFind(int n) : n(n), t(n) {
    for (int v = 0; v < n; ++v) t[v] = {v, v < n / 2, v >= n / 2};
  }
  int find(int v) const { return t[v].par == v ? v : find(t[v].par); }
  bool same(int u, int v) const { return find(u) == find(v); }
  void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (t[u].xsz + t[u].ysz < t[v].xsz + t[v].ysz) swap(u, v);
    his.emplace_back(v, t[v]);
    his.emplace_back(u, t[u]);
    sum -= (lint) t[u].xsz * t[u].ysz;
    sum -= (lint) t[v].xsz * t[v].ysz;
    t[u].xsz += t[v].xsz;
    t[u].ysz += t[v].ysz;
    t[v].par = u;
    sum += (lint) t[u].xsz * t[u].ysz;
  }
  void pop() {
    assert(his.size() >= 2);
    sum -= (lint) t[his.back().first].xsz * t[his.back().first].ysz;
    for (int _ = 0; _ < 2; ++_) {
      t[his.back().first] = his.back().second;
      sum += (lint) t[his.back().first].xsz * t[his.back().first].ysz;
      his.pop_back();
    }
  }
};

struct SegmentTree {
  const int n;
  VV< pair<int, int> > t;
  SegmentTree(int _n) : n(1 << __lg(2 * _n - 1)), t(2 * n) {}
  void add(int l, int r, int x, int y) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) t[l++].emplace_back(x, y);
      if (r & 1) t[--r].emplace_back(x, y);
    }
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  map< pair<int, int>, int > mp;
  SegmentTree st(q);
  for (int i = 0; i < q; ++i) {
    int x, y; cin >> x >> y, --x, --y;
    y += 3e5;
    if (mp.count({x, y})) {
      st.add(mp[{x, y}], i, x, y);
      mp.erase({x, y});
    } else {
      mp[{x, y}] = i;
    }
  }
  for (const auto& e : mp) {
    st.add(e.second, q, e.first.first, e.first.second);
  }
  UnionFind uf(6e5);
  auto dfs = [&](const auto& dfs, int i) -> void {
    int cnt = 0;
    for (const auto& e : st.t[i]) {
      if (uf.same(e.first, e.second)) continue;
      uf.unite(e.first, e.second);
      ++cnt;
    }
    if (i < st.n) {
      dfs(dfs, 2 * i);
      dfs(dfs, 2 * i + 1);
    } else {
      if (i - st.n < q) {
        cout << uf.sum << " \n"[i - st.n == q - 1];
      }
    }
    while (cnt--) {
      uf.pop();
    }
  };
  dfs(dfs, 1);
}