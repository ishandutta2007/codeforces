#include <bits/stdc++.h>

using namespace std;

struct node_t {
  int left, right;
};

class segtree_t {
 public:
  vector<node_t> tree;
  int n;

  node_t unite(const node_t &l, const node_t &r) {
    node_t result;
    result.left = min(l.left, r.left);
    result.right = max(l.right, r.right);
    return result;
  }

  segtree_t(int n):n(n) {
    tree.resize((n << 1) - 1);
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  template<typename T> void build(int x, int l, int r, const vector<T> &v) {
    if (l == r) {
      tree[x] = v[l];
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      build(x + 1, l, y, v);
      build(z, y + 1, r, v);
      pull(x, z);
    }
  }

  template<typename T> void build(const vector<T> &v) {
    build(0, 0, n - 1, v);
  }

  node_t query(int x, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) {
      return tree[x];
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      if (qr <= y) {
        return query(x + 1, l, y, ql, qr);
      } else if (ql > y) {
        return query(z, y + 1, r, ql, qr);
      } else {
        return unite(query(x + 1, l, y, ql, y), query(z, y + 1, r, y + 1, qr));
      }
    }
  }

  node_t query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  if (n == 1) {
    puts("0");
    return 0;
  }
  int m = n * 3;
  vector<int> a(m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i + n] = a[i + n + n] = a[i];
  }
  int log_n = 0;
  while (1 << log_n < n) {
    ++log_n;
  }
  vector<vector<node_t>> range(log_n, vector<node_t> (m));
  for (int i = 0; i < m; ++i) {
    range[0][i].left = max(0, i - a[i]);
    range[0][i].right = min(m - 1, i + a[i]);
  }
  vector<segtree_t> segtree(log_n, m);
  segtree[0].build(range[0]);
  for (int i = 1; i < log_n; ++i) {
    for (int j = 0; j < m; ++j) {
      range[i][j] = segtree[i - 1].query(range[i - 1][j].left, range[i - 1][j].right);
    }
    segtree[i].build(range[i]);
  }
  for (int i = 0; i < n; ++i) {
    int l = i + n, r = i + n, answer = 1;
    for (int j = log_n - 1; ~j; --j) {
      node_t range = segtree[j].query(l, r);
      if (range.right - range.left + 1 < n) {
        l = range.left;
        r = range.right;
        answer += 1 << j;
      }
    }
    printf("%d%c", answer, i == n - 1 ? '\n' : ' ');
  }
  return 0;
}