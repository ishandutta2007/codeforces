#include <bits/stdc++.h>

using namespace std;

const vector<int> dx = {1, -1, 0, 0};
const vector<int> dy = {0, 0, 1, -1};

class node {
 public:
  int id;
  node* l;
  node* r;
  node* p;
  bool rev;

  node(int id): id(id) {
    l = r = p = NULL;
    rev = false;
  }

  void apply() {
    rev ^= 1;
  }

  void push() {
    if (rev) {
      swap(l, r);
      if (l != NULL) {
        l->apply();
      }
      if (r != NULL) {
        r->apply();
      }
      rev = false;
    }
  }

  void pull() {
    if (l != NULL) {
      l->p = this;
    }
    if (r != NULL) {
      r->p = this;
    }
  }
};

bool is_bst_root(node* v) {
  return (v->p == NULL || (v->p->l != v && v->p->r != v));
}

void rotate(node* v) {
  node* u = v->p;
  v->p = u->p;
  if (v->p != NULL) {
    if (v->p->l == u) {
      v->p->l = v;
    }
    if (v->p->r == u) {
      v->p->r = v;
    }
  }
  if (v == u->l) {
    u->l = v->r;
    v->r = u;
  } else {
    u->r = v->l;
    v->l = u;
  }
  u->pull();
  v->pull();
}

void splay(node* v) {
  stack<node*> st;
  st.push(v);
  for (node* u = v; !is_bst_root(u); u = u->p) {
    st.push(u->p);
  }
  while (!st.empty()) {
    st.top()->push();
    st.pop();
  }
  while (!is_bst_root(v)) {
    node* u = v->p;
    if (!is_bst_root(u)) {
      if ((u->l == v) ^ (u->p->l == u)) {
        rotate(v);
      } else {
        rotate(u);
      }
    }
    rotate(v);
  }
}

void access(node* v) {
  node* u = NULL;
  while (v != NULL) {
    splay(v);
    v->r = u;
    u = v;
    v = v->p;
  }
}

void make_root(node* v) {
  access(v);
  splay(v);
  v->apply();
}

int find_root(node* v) {
  access(v);
  splay(v);
  while (v->push(), v->l != NULL) {
    v = v->l;
  }
  splay(v);
  return v->id;
}

bool link(node* v, node* u) {
  if (find_root(v) == find_root(u)) {
    return false;
  } else {
    make_root(v);
    v->p = u;
    return true;
  }
}

void cut(node* v, node* u) {
  make_root(v);
  access(u);
  splay(u);
  u->l = v->p = NULL;
}

class segtree {
 public:
  class node {
   public:
    int value = 0;
    int cnt = 0;
    int tag = 0;

    void apply(int l, int r, int v) {
      value += v;
      tag += v;
    }
  };

  vector<node> tree;
  int n;

  inline node unite(const node &l, const node &r) {
    node res;
    res.value = min(l.value, r.value);
    if (res.value == l.value) {
      res.cnt += l.cnt;
    }
    if (res.value == r.value) {
      res.cnt += r.cnt;
    }
    return res;
  }

  segtree(int n): n(n) {
    tree.resize(n * 2 - 1);
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
    if (l == r) {
      tree[x].value = l;
      tree[x].cnt = 1;
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      build(x + 1, l, y);
      build(z, y + 1, r);
      pull(x, z);
    }
  }

  template<typename... T>
  void modify(int x, int l, int r, int ll, int rr, const T&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      push(x, l, r);
      if (ll <= y) {
        modify(x + 1, l, y, ll, rr, v...);
      }
      if (rr > y) {
        modify(z, y + 1, r, ll, rr, v...);
      }
      pull(x, z);
    }
  }

  node query(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
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

  void build() {
    build(0, 0, n - 1);
  }

  template<typename... T>
  void modify(int l, int r, const T&... v) {
    modify(0, 0, n - 1, l, r, v...);
  }

  node query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> board(n, vector<int>(m));
  vector<pair<int, int>> pos(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
      --board[i][j];
      pos[board[i][j]] = make_pair(i, j);
    }
  }
  vector<node*> tree(n * m);
  for (int i = 0; i < n * m; ++i) {
    tree[i] = new node(i);
  }
  vector<int> right(n * m);
  for (int i = 0, j = 0; i < n * m; ++i) {
    while (j < n * m) {
      int x = pos[j].first, y = pos[j].second;
      vector<int> sons;
      vector<int> roots;
      for (int k = 0; k < 4; ++k) {
        int xx = x + dx[k], yy = y + dy[k];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && board[xx][yy] < j && board[xx][yy] >= i) {
          sons.push_back(board[xx][yy]);
          roots.push_back(find_root(tree[board[xx][yy]]));
        }
      }
      bool can = true;
      for (int k = 0; k < (int) roots.size(); ++k) {
        for (int l = 0; l < k; ++l) {
          if (roots[k] == roots[l]) {
            can = false;
            break;
          }
        }
        if (!can) {
          break;
        }
      }
      if (can) {
        for (auto k : sons) {
          link(tree[j], tree[k]);
        }
        ++j;
      } else {
        break;
      }
    }
    right[i] = j - 1;
    int x = pos[i].first, y = pos[i].second;
    for (int k = 0; k < 4; ++k) {
      int xx = x + dx[k], yy = y + dy[k];
      if (xx >= 0 && xx < n && yy >= 0 && yy < m && board[xx][yy] < j && board[xx][yy] >= i) {
        cut(tree[i], tree[board[xx][yy]]);
      }
    }
  }
  segtree seg(n * m);
  seg.build();
  long long ans = 0;
  for (int i = n * m - 1; ~i; --i) {
    int x = pos[i].first, y = pos[i].second;
    for (int j = 0; j < 4; ++j) {
      int xx = x + dx[j], yy = y + dy[j];
      if (xx >= 0 && xx < n && yy >= 0 && yy < m && board[xx][yy] >= i) {
        seg.modify(board[xx][yy], n * m - 1, -1);
      }
    }
    segtree::node res = seg.query(i, right[i]);
    if (res.value == i) {
      ans += res.cnt;
    }
  }
  cout << ans << "\n";
  return 0;
}