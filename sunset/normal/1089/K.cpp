#include <bits/stdc++.h>

using namespace std;

class segtree_t {
 public:
  struct node_t {
    long long tag = 0, value = 0;
    
    void apply(int l, int r, long long v) {
      tag += v;
      value += v;
    }
  };
  
  vector<node_t> tree;
  int n;

  node_t unite(const node_t &l, const node_t &r) {
    node_t result;
    result.value = min(l.value, r.value);
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
    if (tree[x].tag) {
      tree[x + 1].apply(l, y, tree[x].tag);
      tree[z].apply(y + 1, r, tree[x].tag);
      tree[x].tag = 0;
    }
  }

  void build(int x, int l, int r) {
    if (l != r) {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      build(x + 1, l, y);
      build(z, y + 1, r);
      pull(x, z);
    } else {
      tree[x].value = -l;
    }
  }

  template<typename T> void build(int x, int l, int r, const vector<T> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
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
    modify(0, 0, n - 1, l, r, v...);
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
    return query(0, 0, n - 1, l, r);
  }
};

const int MAX = 1000000;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  segtree_t segtree(MAX + 1);
  segtree.build(0, 0, MAX);
  int tt;
  cin >> tt;
  vector<pair<int, int>> a(tt);
  for (int qq = 0; qq < tt; ++qq) {
    string type;
    cin >> type;
    if (type == "+") {
      int t, d;
      cin >> t >> d;
      a[qq] = make_pair(t, d);
      segtree.modify(t, MAX, d);
    } else if (type == "-") {
      int i;
      cin >> i;
      --i;
      int t = a[i].first, d = a[i].second;
      segtree.modify(t, MAX, -d);
    } else {
      int t;
      cin >> t;
      printf("%lld\n", segtree.query(t, t).value - segtree.query(0, t - 1).value + 1);
    }
  }
  return 0;
}