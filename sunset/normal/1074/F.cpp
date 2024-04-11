#include <bits/stdc++.h>

using namespace std;

struct node_t {
  int cnt, tag, value;

  node_t() {
    tag = value = 0;
    cnt = 1;
  }

  void apply(int v) {
    tag += v;
    value += v;
  }
};

node_t unite(const node_t &l, const node_t &r) {
  node_t result;
  result.value = max(l.value, r.value);
  result.cnt = 0;
  if (result.value == l.value) {
    result.cnt += l.cnt;
  }
  if (result.value == r.value) {
    result.cnt += r.cnt;
  }
  return result;
}

class segtree_t {
 private:
  vector<node_t> tree;
  int n;

  void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  void push(int x, int z) {
    if (tree[x].tag) {
      tree[x + 1].apply(tree[x].tag);
      tree[z].apply(tree[x].tag);
      tree[x].tag = 0;
    }
  }

  void build(int x, int l, int r) {
    if (l == r) {
      tree[x] = node_t();
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      build(x + 1, l, y);
      build(z, y + 1, r);
      pull(x, z);
    }
  }

  void modify(int x, int l, int r, int ql, int qr, int value) {
    if (l == ql && r == qr) {
      tree[x].apply(value);
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      push(x, z);
      if (qr <= y) {
        modify(x + 1, l, y, ql, qr, value);
      } else if (ql > y) {
        modify(z, y + 1, r, ql, qr, value);
      } else {
        modify(x + 1, l, y, ql, y, value);
        modify(z, y + 1, r, y + 1, qr, value);
      }
      pull(x, z);
    }
  }

 public:
  segtree_t(int n):n(n) {
    tree.resize((n << 1) - 1);
    build(0, 0, n - 1);
  }

  void modify(int l, int r, int value) {
    modify(0, 0, n - 1, l, r, value);
  }

  pair<int, int> query() {
    return make_pair(tree[0].value, tree[0].cnt);
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, q;
  scanf("%d %d", &n, &q);
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int log_n = 0;
  while (1 << log_n < n) {
    ++log_n;
  }
  vector<vector<int>> parent(log_n, vector<int> (n, -1));
  vector<int> dfn_l(n), dfn_r(n), depth(n);
  int dfn_t = 0;
  function<void(int)> dfs = [&](int x) {
    dfn_l[x] = dfn_t++;
    for (int i = 1; depth[x] >> i; ++i) {
      parent[i][x] = parent[i - 1][parent[i - 1][x]];
    }
    for (auto y : adj[x]) {
      if (y != parent[0][x]) {
        depth[y] = depth[x] + 1;
        parent[0][y] = x;
        dfs(y);
      }
    }
    dfn_r[x] = dfn_t - 1;
  };
  dfs(0);
  set<pair<int, int>> edges;
  segtree_t segtree(n);
  auto jump = [&](int x, int d) {
    for (int i = 0; d >> i; ++i) {
      if (d >> i & 1) {
        x = parent[i][x];
      }
    }
    return x;
  };
  auto lca = [&](int x, int y) {
    if (depth[x] < depth[y]) {
      swap(x, y);
    }
    x = jump(x, depth[x] - depth[y]);
    if (x == y) {
      return x;
    }
    for (int i = log_n - 1; ~i; --i) {
      if (parent[i][x] != parent[i][y]) {
        x = parent[i][x];
        y = parent[i][y];
      }
    }
    return parent[0][x];
  };
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    if (dfn_l[x] > dfn_l[y]) {
      swap(x, y);
    }
    int value = 0;
    if (edges.find(make_pair(x, y)) == edges.end()) {
      value = 1;
      edges.insert(make_pair(x, y));
    } else {
      value = -1;
      edges.erase(make_pair(x, y));
    }
    if (dfn_r[x] >= dfn_r[y]) {
      int z = jump(y, depth[y] - depth[x] - 1);  
      segtree.modify(0, n - 1, value);
      segtree.modify(dfn_l[z], dfn_r[z], -value);
      segtree.modify(dfn_l[y], dfn_r[y], value);
    } else {
      segtree.modify(dfn_l[x], dfn_r[x], value);
      segtree.modify(dfn_l[y], dfn_r[y], value);
    }
    pair<int, int> answer = segtree.query();
    if (answer.first != edges.size()) {
      answer.second = 0;
    }
    printf("%d\n", answer.second);
  }
  return 0;
}