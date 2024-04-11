#include <bits/stdc++.h>

using namespace std;

class node {
 public:
  int cover = -1;
  bool flip = false;
  bool value = false;
  
  void apply(int l, int r, int tag) {
    if (tag == -1) {
      flip = !flip;
      value = !value;
    } else {
      cover = value = tag;
      flip = false;
    }
  }
};

class segtree {
 public:
  vector<node> tree;
  int n;

  segtree(int n): n(n) {
    tree.resize(n * 2 - 1);
  }

  void push(int x, int l, int r) {
    int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
    if (tree[x].cover != -1) {
      tree[x + 1].apply(l, y, tree[x].cover);
      tree[z].apply(y + 1, r, tree[x].cover);
      tree[x].cover = -1;
    }
    if (tree[x].flip) {
      tree[x + 1].apply(l, y, -1);
      tree[z].apply(y + 1, r, -1);
      tree[x].flip = false;
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
    }
  }

  bool query(int x, int l, int r, int p) {
    if (l == r) {
      return tree[x].value;
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      push(x, l, r);
      if (p <= y) {
        return query(x + 1, l, y, p);
      } else {
        return query(z, y + 1, r, p);
      }
    }
  }

  template<typename... T>
  void modify(int l, int r, const T&... v) {
    if (0 <= l && l <= r && r < n) {
      modify(0, 0, n - 1, l, r, v...);
    }
  }

  bool query(int p) {
    return query(0, 0, n - 1, p);
  }
};

const int MAX = (int) 1e5;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  segtree seg(MAX * 2 + 1);
  auto modify = [&](int l, int r, int v) {
    seg.modify(l + MAX, r + MAX, v);
  };
  while (q--) {
    string s;
    int x;
    cin >> s >> x;
    if (s == "<") {
      if (x <= 0) {
        modify(-MAX, x - 1, 1);
        modify(-(x - 1), MAX, 0);
      } else {
        modify(-MAX, -x, 1);
        modify(x, MAX, 0);
        modify(-(x - 1), x - 1, -1);
      }
    } else {
      if (x >= 0) {
        modify(-MAX, -(x + 1), 0);
        modify(x + 1, MAX, 1);
      } else {
        modify(-MAX, x, 0);
        modify(-x, MAX, 1);
        modify(x + 1, -(x + 1), -1);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i) {
      cout << " ";
    }
    cout << (seg.query(a[i] + MAX) ? -a[i] : a[i]);
  }
  cout << "\n";
  return 0;
}