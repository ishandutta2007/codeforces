#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e6 + 1;

class segtree {
  vector<pair<int, int>> tree;
  int n;

  void pull(int x, int z) {
    tree[x].first = tree[x + 1].first + tree[z].first;
    tree[x].second = max(tree[x + 1].second + tree[z].first, tree[z].second);
  }

  void modify(int x, int l, int r, int p, int v) {
    if (l == r) {
      tree[x].first += v;
      tree[x].second = max(tree[x].first, 0);
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      if (p <= y) {
        modify(x + 1, l, y, p, v);
      } else {
        modify(z, y + 1, r, p, v);
      }
      pull(x, z);
    }
  }

  int query(int x, int l, int r, int s) {
    if (l == r) {
      return l;
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      if (tree[z].second + s > 0) {
        return query(z, y + 1, r, s);
      } else {
        return query(x + 1, l, y, s + tree[z].first);
      }
    }
  }

 public:
  segtree(int n) : n(n) {
    tree.resize(2 * n - 1);
  }

  void modify(int p, int v) {
    modify(0, 0, n - 1, p, v);
  }

  int query() {
    return query(0, 0, n - 1, 0);
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  segtree st(MAX);
  st.modify(0, m + 1);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    st.modify(a[i], 1);
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    st.modify(b[i], -1);
  }
  int q;
  cin >> q;
  while (q--) {
    int type, x, y;
    cin >> type >> x >> y;
    --x;
    if (type == 1) {
      st.modify(a[x], -1);
      a[x] = y;
      st.modify(a[x], 1);
    } else {
      st.modify(b[x], 1);
      b[x] = y;
      st.modify(b[x], -1);
    }
    int ans = st.query();
    if (!ans) {
      ans = -1;
    }
    cout << ans << "\n";
  }
  return 0;
}