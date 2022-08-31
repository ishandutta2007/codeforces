#include <bits/stdc++.h>

using namespace std;

struct node {
  vector<pair<int, int>> v;
  int offset;

  void apply(int foo, int bar) {
    v = {{foo, bar}};
    offset = foo;
  }
};

class segtree {
  vector<node> tree;
  int n, m;

  vector<pair<int, int>> unite(vector<pair<int, int>> lhs, vector<pair<int, int>> rhs) {
    vector<pair<int, int>> res;
    for (int i = 0, j = 0; i < (int) lhs.size() || j < (int) rhs.size(); ) {
      if (i < (int) lhs.size() && j < (int) rhs.size() && lhs[i].first == rhs[j].first) {
        res.emplace_back(lhs[i].first, lhs[i].second + rhs[j].second);
        ++i;
        ++j;
      } else if (i < (int) lhs.size() && (j == (int) rhs.size() || lhs[i].first < rhs[j].first)) {
        res.emplace_back(lhs[i]);
        ++i;
      } else {
        res.emplace_back(rhs[j]);
        ++j;
      }
    }
    if ((int) res.size() > m) {
      sort(res.begin(), res.end(), [&](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });
      for (int i = (int) res.size() - 1; i >= m; --i) {
        for (int j = i - m; j < i; ++j) {
          res[j].second -= res[i].second;
        }
        res.pop_back();
      }
      sort(res.begin(), res.end());
    }
    return res;
  }

  void pull(int x, int z) {
    tree[x].v = unite(tree[x + 1].v, tree[z].v);
  }

  void push(int x, int l, int r) {
    int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
    if (tree[x].offset) {
      tree[x + 1].apply(tree[x].offset, y - l + 1);
      tree[z].apply(tree[x].offset, r - y);
      tree[x].offset = 0;
    }
  }

  void modify(int x, int l, int r, int ll, int rr, int v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(v, r - l + 1);
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      push(x, l, r);
      if (ll <= y) {
        modify(x + 1, l, y, ll, rr, v);
      }
      if (rr > y) {
        modify(z, y + 1, r, ll, rr, v);
      }
      pull(x, z);
    }
  }

  vector<pair<int, int>> query(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x].v;
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      push(x, l, r);
      if (rr <= y) {
        return query(x + 1, l, y, ll, rr);
      } else if (ll > y) {
        return query(z, y + 1, r, ll, rr);
      } else {
        return unite(query(x + 1, l, y, ll, rr), query(z, y + 1, r, ll, rr));
      }
    }
  }

 public:
  segtree(int n, int m) : n(n), m(m) {
    tree.resize(2 * n - 1);
  }

  void modify(int ll, int rr, int v) {
    modify(0, 0, n - 1, ll, rr, v);
  }

  vector<pair<int, int>> query(int ll, int rr) {
    return query(0, 0, n - 1, ll, rr);
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  segtree seg(n, 100 / p);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    seg.modify(i, i, a);
  }
  while (m--) {
    int type, l, r;
    cin >> type >> l >> r;
    --l; --r;
    if (type == 1) {
      int who;
      cin >> who;
      seg.modify(l, r, who);
    } else {
      vector<pair<int, int>> res = seg.query(l, r);
      cout << res.size();
      for (auto p : res) {
        cout << " " << p.first;
      }
      cout << "\n";
    }
  }
  return 0;
}