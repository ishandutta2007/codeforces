#include <bits/stdc++.h>

using namespace std;

class node {
 public:
  int a;
  int b;
  int ans;
  int add_l;
  int sub_l;
  int add_r;
  int sub_r;

  void init(int type) {
    if (type == 1) {
      a = 0;
      b = 1;
      ans = 1;
      add_l = 1;
      sub_l = 1;
      add_r = 1;
      sub_r = 0;
    } else {
      a = 1;
      b = 0;
      ans = 1;
      add_l = 1;
      sub_l = 0;
      add_r = 1;
      sub_r = 1;
    }
  }
};

node unite(const node &l, const node &r) {
  node res;
  res.a = l.a + max(0, r.a - l.b);
  res.b = max(0, l.b - r.a) + r.b;
  res.ans = max(max(l.ans, r.ans), max(l.add_r + r.sub_l, l.sub_r + r.add_l));
  res.add_l = max(l.add_l, max(l.a - l.b + r.add_l, l.a + l.b + r.sub_l));
  res.sub_l = max(l.sub_l, l.b - l.a + r.sub_l);
  res.add_r = max(max(l.add_r + r.b - r.a, l.sub_r + r.b + r.a), r.add_r);
  res.sub_r = max(l.sub_r + r.a - r.b, r.sub_r);
  return res;
}

class segtree {
 public:
  vector<node> tree;
  int n;

  segtree(int n): n(n) {
    tree.resize(n * 2 - 1);
  }

  void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  template<typename T>
  void build(int x, int l, int r, const vector<T> &v) {
    if (l == r) {
      tree[x].init(v[l]);
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      build(x + 1, l, y, v);
      build(z, y + 1, r, v);
      pull(x, z);
    }
  }

  void modify(int x, int l, int r, int p, int v) {
    if (l == r) {
      tree[x].init(v);
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

  template<typename T>
  void build(const vector<T> &v) {
    build(0, 0, n - 1, v);
  }

  void modify(int p, int v) {
    modify(0, 0, n - 1, p, v);
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> a(n * 2 - 2);
  for (int i = 0; i < n * 2 - 2; ++i) {
    a[i] = s[i] == '(' ? 1 : -1;
  }
  segtree seg(n * 2 - 2);
  seg.build(a);
  cout << seg.tree[0].ans << "\n";
  while (q--) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    swap(a[x], a[y]);
    seg.modify(x, a[x]);
    seg.modify(y, a[y]);
    cout << seg.tree[0].ans << "\n";
  }
  return 0;
}