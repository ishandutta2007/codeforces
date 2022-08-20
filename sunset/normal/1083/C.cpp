#include <bits/stdc++.h>

using namespace std;

class tree_t {
 public:
  vector<int> pre, post, zeros, depth, parent;
  vector<vector<int>> adj, rmq;
  int n, tt, log_n;

  inline int lower(int x, int y) {
    return depth[x] < depth[y] ? x : y;
  }

  void dfs(int x) {
    pre[x] = tt;
    rmq[0][tt++] = x;
    for (auto y : adj[x]) {
      dfs(y);
    }
    post[x] = tt;
  }

  void init(int v) {
    n = v;
    adj.resize(n);
    pre.resize(n);
    post.resize(n);
    zeros.resize(n);
    depth.resize(n);
    parent.resize(n);
    parent[0] = -1;
    for (int i = 1; i < n; ++i) {
      scanf("%d", &parent[i]);
      --parent[i];
      depth[i] = depth[parent[i]] + 1;
      adj[parent[i]].push_back(i);
    }
    for (int i = 2; i < n; ++i) {
      zeros[i] = zeros[i >> 1] + 1;
    }
    rmq = vector<vector<int>> (zeros[n - 1] + 1, vector<int> (n));
    dfs(0);
    for (int i = 1; i <= zeros[n - 1]; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        rmq[i][j] = lower(rmq[i - 1][j], rmq[i - 1][j + (1 << i - 1)]);
      }
    }
  }

  inline int lca(int x, int y) {
    if (pre[x] >= pre[y]) {
      swap(x, y);
    }
    if (post[x] >= post[y]) {
      return x;
    }
    int k = zeros[pre[y] - pre[x]];
    return parent[lower(rmq[k][pre[x]], rmq[k][pre[y] - (1 << k) + 1])];
  }

  inline int dist(int x, int y) {
    return depth[x] + depth[y] - depth[lca(x, y)] * 2;
  }
};

class segtree_t {
 public:
  vector<pair<int, int>> segtree;
  tree_t tree;
  int n;

  segtree_t(int n): n(n) {
    segtree = vector<pair<int, int>> (n * 2 - 1, make_pair(-1, -1));
    tree.init(n);
  }

  pair<int, int> merge(int x, int y, int z) {
    int xy = tree.dist(x, y), yz = tree.dist(y, z), zx = tree.dist(z, x);
    if (xy + yz == zx) {
      return make_pair(z, x);
    } else if (yz + zx == xy) {
      return make_pair(x, y);
    } else if (zx + xy == yz) {
      return make_pair(y, z);
    } else {
      return make_pair(-1, -1);
    }
  }

  pair<int, int> unite(pair<int, int> p, pair<int, int> q) {
    if (~p.first && ~q.first) {
      p = merge(p.first, p.second, q.first);
      if (~p.first) {
        p = merge(p.first, p.second, q.second);
      }
      return p;
    } else {
      return make_pair(-1, -1);
    }
  }

  void modify(int x, int l, int r, int pos, int value) {
    if (l == r) {
      segtree[x] = make_pair(value, value);
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      if (pos <= y) {
        modify(x + 1, l, y, pos, value);
      } else {
        modify(z, y + 1, r, pos, value);
      }
      segtree[x] = unite(segtree[x + 1], segtree[z]);
    }
  }

  int query(int x, int l, int r, pair<int, int> p) {
    if (l == r) {
      return r;
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      pair<int, int> q = unite(p, segtree[x + 1]);
      if (!~q.first) {
        return query(x + 1, l, y, p);
      } else {
        return query(z, y + 1, r, q);
      }
    }
  }

  int query(pair<int, int> p) {
    if (~segtree[0].first) {
      return n;
    } else {
      return query(0, 0, n - 1, p);
    }
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> p(n), q(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    q[p[i]] = i;
  }
  segtree_t segtree(n);
  for (int i = 0; i < n; ++i) {
    segtree.modify(0, 0, n - 1, i, q[i]);
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int x, y;
      scanf("%d %d", &x, &y);
      --x;
      --y;
      swap(p[x], p[y]);
      swap(q[p[x]], q[p[y]]);
      segtree.modify(0, 0, n - 1, p[x], q[p[x]]);
      segtree.modify(0, 0, n - 1, p[y], q[p[y]]);
    } else {
      printf("%d\n", segtree.query(make_pair(q[0], q[0])));
    }
  }
  return 0;
}