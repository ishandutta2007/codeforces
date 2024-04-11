#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline int mul(int x, int y) {
  return (long long)x * y % md;
}

class segtree_t {
 public:
  struct node_t {
    int sum_a = 0, sum_b = 0, tag_a = 0, tag_b = 0, answer = 0;
    
    void apply(int l, int r, int add_a, int add_b) {
      add(answer, mul(add_a, sum_b));
      add(answer, mul(add_b, sum_a));
      add(answer, mul(mul(add_a, add_b), r - l + 1));
      add(sum_a, mul(add_a, r - l + 1));
      add(sum_b, mul(add_b, r - l + 1));
      add(tag_a, add_a);
      add(tag_b, add_b);
    }
  };
  
  vector<node_t> tree;
  int n;

  node_t unite(const node_t &l, const node_t &r) {
    node_t result;
    add(result.sum_a, l.sum_a);
    add(result.sum_a, r.sum_a);
    add(result.sum_b, l.sum_b);
    add(result.sum_b, r.sum_b);
    add(result.answer, l.answer);
    add(result.answer, r.answer);
    return result;
  }

  segtree_t(int n):n(n) {
    tree.resize((n << 1) - 1);
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  inline void push(int x, int l, int r) {
    int y = l + r >> 1, z = x + (y - l + 1 << 1);
    if (tree[x].tag_a || tree[x].tag_b) {
      tree[x + 1].apply(l, y, tree[x].tag_a, tree[x].tag_b);
      tree[z].apply(y + 1, r, tree[x].tag_a, tree[x].tag_b);
      tree[x].tag_a = tree[x].tag_b = 0;
    }
  }

  void build(int x, int l, int r) {
    if (l == r) {
      tree[x].sum_a = (l + md - 1) % md;
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      build(x + 1, l, y);
      build(z, y + 1, r);
      pull(x, z);
    }
  }

  void build() {
    build(0, 0, n - 1);
  }

  template<typename... T> void modify(int x, int l, int r, int ql, int qr, const T&... v) {
    if (l == ql && r == qr) {
      tree[x].apply(l, r, v...);
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      push(x, l, r);
      if (qr <= y) {
        modify(x + 1, l, y, ql, qr, v...);
      } else if (ql > y) {
        modify(z, y + 1, r, ql, qr, v...);
      } else {
        modify(x + 1, l, y, ql, y, v...);
        modify(z, y + 1, r, y + 1, qr, v...);
      }
      pull(x, z);
    }
  }

  template<typename... T> void modify(int l, int r, const T&... v) {
    if (l <= r) {
      modify(0, 0, n - 1, l, r, v...);
    }
  }

  node_t query(int x, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) {
      return tree[x];
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      push(x, l, r);
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
    return l <= r ? query(0, 0, n - 1, l, r) : node_t();
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  map<int, int> last;
  vector<int> pre(n);
  for (int i = 0; i < n; ++i) {
    last[a[i]] = -1;
  }
  for (int i = 0; i < n; ++i) {
    pre[i] = last[a[i]];
    last[a[i]] = i;
  }
  vector<int> nxt(n);
  for (int i = 0; i < n; ++i) {
    last[a[i]] = n;
  }
  for (int i = n - 1; ~i; --i) {
    nxt[i] = last[a[i]];
    last[a[i]] = i;
  }
  segtree_t segtree(n);
  segtree.build();
  stack<pair<int, int>> stack_a, stack_b;
  int answer = 0;
  int low = 0;
  for (int i = 0; i < n; ++i) {
    low = max(low, pre[i] + 1);
    int pos_a = i;
    while (!stack_a.empty() && stack_a.top().second < pre[i]) {
      segtree.modify(stack_a.top().first, pos_a - 1, (md + stack_a.top().second) % md, 0);
      pos_a = stack_a.top().first;
      stack_a.pop();
    }
    segtree.modify(pos_a, i, (md - pre[i]) % md, 0);
    stack_a.emplace(pos_a, pre[i]);
    int pos_b = i;
    while (!stack_b.empty() && stack_b.top().second > nxt[i]) {
      segtree.modify(stack_b.top().first, pos_b - 1, 0, md - stack_b.top().second);
      pos_b = stack_b.top().first;
      stack_b.pop();
    }
    segtree.modify(pos_b, i, 0, nxt[i]);
    stack_b.emplace(pos_b, nxt[i]);
    segtree.modify(low, i, 0, md - (i + 1));
    add(answer, segtree.query(low, i).answer);
    segtree.modify(low, i, 0, i + 1);
  }
  printf("%d\n", answer);
  return 0;
}