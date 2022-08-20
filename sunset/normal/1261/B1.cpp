#include <bits/stdc++.h>

using namespace std;

class node {
 public:
  int cnt = 0;
  int val = 0;
  
  void apply(int l, int r, int v) {
    cnt = 1;
    val = v;
  }
};

class segtree {
 public:
  vector<node> tree;
  int n;

  node unite(const node &l, const node &r) {
    node res;
    res.cnt = l.cnt + r.cnt;
    return res;
  }

  segtree(int n): n(n) {
    tree.resize(n * 2 - 1);
  }

  void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  void push(int x, int l, int r) {
    int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
    /*
    if (tree[x].tag) {
      tree[x + 1].apply(l, y, tree[x].tag);
      tree[z].apply(y + 1, r, tree[x].tag);
      tree[x].tag = 0;
    }
    */
  }

  void build(int x, int l, int r) {
    if (l != r) {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      build(x + 1, l, y);
      build(z, y + 1, r);
      pull(x, z);
    }
  }

  template<typename T>
  void build(int x, int l, int r, const vector<T> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      build(x + 1, l, y, v);
      build(z, y + 1, r, v);
      pull(x, z);
    }
  }

  template<typename... T>
  void modify(int x, int l, int r, int ll, int rr, const T&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      push(x, l, r);
      if (ll <= y) {
        modify(x + 1, l, y, ll, rr, v...);
      }
      if (rr > y) {
        modify(z, y + 1, r, ll, rr, v...);
      }
      pull(x, z);
    }
  }

  int query(int x, int l, int r, int k) {
    if (l == r) {
      return tree[x].val;
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      if (tree[x + 1].cnt >= k) {
        return query(x + 1, l, y, k);
      } else {
        return query(z, y + 1, r, k - tree[x + 1].cnt);
      }
    }
  }

  void build() {
    build(0, 0, n - 1);
  }

  template<typename T>
  void build(const vector<T> &v) {
    build(0, 0, n - 1, v);
  }

  template<typename... T>
  void modify(int l, int r, const T&... v) {
    modify(0, 0, n - 1, l, r, v...);
  }

  int query(int k) {
    return query(0, 0, n - 1, k);
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].first *= -1;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  int m;
  cin >> m;
  vector<vector<pair<int, int>>> queries(n);
  vector<int> ans(m);
  for (int i = 0; i < m; ++i) {
    int foo, bar;
    cin >> foo >> bar;
    queries[foo - 1].emplace_back(bar, i);
  }
  segtree seg(n);
  for (int i = 0; i < n; ++i) {
    seg.modify(a[i].second, a[i].second, -a[i].first);
    for (auto p : queries[i]) {
      ans[p.second] = seg.query(p.first);
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}