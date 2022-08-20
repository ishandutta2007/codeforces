#include <bits/stdc++.h>

using namespace std;

class node {
 public:
  int id;
  node* l;
  node* r;
  node* p;
  bool rev;
  int sz;
  // declare extra variables:
  long long add;
  long long val;
  long long sum;


  node(int _id, long long v) {
    id = _id;
    l = r = p = NULL;
    rev = false;
    sz = 1;
    // init extra variables:
    add = 0;
    val = v;
    sum = v;
  }

  void unsafe_reverse() {
    rev ^= 1;
    swap(l, r);
    pull();
  }

  // apply changes:
  void unsafe_apply(long long v) {
    add += v;
    val += v;
    sum += sz * v;
  }

  void push() {
    if (rev) {
      if (l != NULL) {
        l->unsafe_reverse();
      }
      if (r != NULL) {
        r->unsafe_reverse();
      }
      rev = 0;
    }
    // now push everything else:
    if (add) {
      if (l != NULL) {
        l->unsafe_apply(add);
      }
      if (r != NULL) {
        r->unsafe_apply(add);
      }
      add = 0;
    }
  }

  void pull() {
    sz = 1;
    // now init from self:
    sum = val;
    if (l != NULL) {
      l->p = this;
      sz += l->sz;
      // now pull from l:
      sum += l->sum;
    }
    if (r != NULL) {
      r->p = this;
      sz += r->sz;
      // now pull from r:
      sum += r->sum;
    }
  }
};

void debug_node(node* v, string pref = "") {
#ifdef LOCAL
  if (v != NULL) {
    debug_node(v->r, pref + " ");
    cerr << pref << "-" << " " << v->id << '\n';
    debug_node(v->l, pref + " ");
  } else {
    cerr << pref << "-" << " " << "NULL" << '\n';
  }
#endif
}

namespace splay_tree {
bool is_bst_root(node* v) {
  if (v == NULL) {
    return false;
  }
  return (v->p == NULL || (v->p->l != v && v->p->r != v));
}

void rotate(node* v) {
  node* u = v->p;
  assert(u != NULL);
  u->push();
  v->push();
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
  if (v == NULL) {
    return;
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

pair<node*, int> find(node* v, const function<int(node*)> &go_to) {
  // go_to returns: 0 -- found; -1 -- go left; 1 -- go right
  // find returns the last vertex on the descent and its go_to
  if (v == NULL) {
    return {NULL, 0};
  }
  splay(v);
  int dir;
  while (true) {
    v->push();
    dir = go_to(v);
    if (dir == 0) {
      break;
    }
    node* u = (dir == -1 ? v->l : v->r);
    if (u == NULL) {
      break;
    }
    v = u;
  }
  splay(v);
  return {v, dir};
}

node* get_leftmost(node* v) {
  return find(v, [&](node*) {
    return -1;
  }).first;
}

node* get_rightmost(node* v) {
  return find(v, [&](node*) {
    return 1;
  }).first;
}

node* get_kth(node* v, int k) { // 0-indexed
  pair<node*, int> p = find(v, [&](node* u) {
    if (u->l != NULL) {
      if (u->l->sz > k) {
        return -1;
      }
      k -= u->l->sz;
    }
    if (k == 0) {
      return 0;
    }
    k--;
    return 1;
  });
  return (p.second == 0 ? p.first : NULL);
}

int get_position(node* v) { // 0-indexed
  splay(v);
  return (v->l != NULL ? v->l->sz : 0);
}

node* get_bst_root(node* v) {
  splay(v);
  return v;
}

pair<node*, node*> split(node* v, const function<bool(node*)> &is_right) {
  if (v == NULL) {
    return {NULL, NULL};
  }
  pair<node*, int> p = find(v, [&](node* u) {
    return is_right(u) ? -1 : 1;
  });
  v = p.first;
  v->push();
  if (p.second == -1) {
    node* u = v->l;
    if (u == NULL) {
      return {NULL, v};
    }
    v->l = NULL;
    u->p = v->p;
    u = get_rightmost(u);
    v->p = u;
    v->pull();
    return {u, v};
  } else {
    node* u = v->r;
    if (u == NULL) {
      return {v, NULL};
    }
    v->r = NULL;
    v->pull();
    return {v, u};
  }
}

pair<node*, node*> split_leftmost_k(node* v, int k) {
  return split(v, [&](node* u) {
    int left_and_me = (u->l != NULL ? u->l->sz : 0) + 1;
    if (k >= left_and_me) {
      k -= left_and_me;
      return false;
    }
    return true;
  });
}

node* merge(node* v, node* u) {
  if (v == NULL) {
    return u;
  }
  if (u == NULL) {
    return v;
  }
  v = get_rightmost(v);
  assert(v->r == NULL);
  splay(u);
  v->push();
  v->r = u;
  v->pull();
  return v;
}

int count_left(node* v, const function<bool(node*)> &is_right) {
  if (v == NULL) {
    return 0;
  }
  pair<node*, int> p = find(v, [&](node* u) {
    return is_right(u) ? -1 : 1;
  });
  node* u = p.first;
  return (u->l != NULL ? u->l->sz : 0) + (p.second == 1);
}

node* add(node* r, node* v, const function<bool(node*)> &go_left) {
  pair<node*, node*> p = split(r, go_left);
  return merge(p.first, merge(v, p.second));
}

node* remove(node* v) { // returns the new root
  splay(v);
  v->push();
  node* x = v->l;
  node* y = v->r;
  v->l = v->r = NULL;
  node* z = merge(x, y);
  if (z != NULL) {
    z->p = v->p;
  }
  v->p = NULL;
  v->push();
  v->pull(); // now v might be reusable...
  return z;
}

node* next(node* v) {
  splay(v);
  v->push();
  if (v->r == NULL) {
    return NULL;
  }
  v = v->r;
  while (v->l != NULL) {
    v->push();
    v = v->l;
  }
  splay(v);
  return v;
}

node* prev(node* v) {
  splay(v);
  v->push();
  if (v->l == NULL) {
    return NULL;
  }
  v = v->l;
  while (v->r != NULL) {
    v->push();
    v = v->r;
  }
  splay(v);
  return v;
}

int get_size(node* v) {
  splay(v);
  return (v != NULL ? v->sz : 0);
}

template <typename... T>
void apply(node* v, T... args) {
  splay(v);
  v->unsafe_apply(args...);
}

void reverse(node* v) {
  splay(v);
  v->unsafe_reverse();
}
}

using namespace splay_tree;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  node* root = NULL;
  for (int i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    int res = i + 1;
    int foo = 0;
    node* l;
    node* r;
    tie(l, r) = split(root, [&](node* u) {
      int bar = foo + (u->l != NULL ? u->l->sz : 0) + 1;
      if (x * bar >= u->val) {
        res = bar;
        return true;
      } else {
        foo = bar;
        return false;
      }
    });
    if (r != NULL) {
      r->unsafe_apply(x);
    }
    root = merge(l, merge(new node(i, x * res), r));
  }
  long long cur = 0;
  long long ans = 0;
  function<void(node*)> dfs = [&](node* v) {
    if (v == NULL) {
      return;
    }
    v->push();
    dfs(v->l);
    cur += v->val;
    ans = max(ans, cur);
    dfs(v->r);
  };
  dfs(root);
  cout << ans << "\n";
  return 0;
}