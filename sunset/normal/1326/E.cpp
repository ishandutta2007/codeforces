#include <bits/stdc++.h>

using namespace std;

struct node {
  int sum;
  int val;
};

class segtree {
 public:
  vector<node> tree;
  int n;

  node unite(const node &l, const node &r) {
    node res;
    res.sum = l.sum + r.sum;
    res.val = min(l.val, r.val + l.sum);
    return res;
  }

  segtree(int n): n(n) {
    tree.resize(n * 2 - 1);
  }

  void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  void modify(int x, int l, int r, int p, int v) {
    if (l == r) {
      tree[x].sum += v;
      tree[x].val = min(0, tree[x].sum);
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

  bool query() {
    return tree[0].sum == tree[0].val;
  }

  void modify(int p, int v) {
    modify(0, 0, n - 1, p, v);
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
  vector<int> p(n);
  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    pos[--p[i]] = i;
  }
  vector<int> q(n);
  for (int i = 0; i < n; ++i) {
    cin >> q[i];
    --q[i];
  }
  vector<int> ans(n);
  segtree seg(n);
  function<void(int, int, int, int)> solve = [&](int l, int r, int ll, int rr) {
    if (l > r) {
      return;
    }
    int m = (l + r) >> 1;
    for (int i = max(l - 1, 0); i < m; ++i) {
      seg.modify(q[i], -1);
    }
    int mm = rr;
    while (true) {
      seg.modify(pos[mm--], 1);
      if (!seg.query()) {
        break;
      }
    }
    ans[m] = mm + 1;
    seg.modify(pos[++mm], -1);
    solve(m + 1, r, ll, mm);
    for (int i = mm + 1; i <= rr; ++i) {
      seg.modify(pos[i], -1);
    }
    for (int i = max(l - 1, 0); i < m; ++i) {
      seg.modify(q[i], 1);
    }
    solve(l, m - 1, mm, rr);
  };
  solve(0, n - 1, 0, n - 1);
  for (int i = 0; i < n; ++i) {
    if (i) {
      cout << " ";
    }
    cout << ans[i] + 1;
  }
  cout << "\n";
  return 0;
}