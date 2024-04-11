#include <bits/stdc++.h>

using namespace std;

// copied from tourist's template

class node {
 public:
  node* l;
  node* r;
  node* p;
  bool rev;
  // declare extra variables:
  int tl;
  int tr;
  int tv;
  int ml;
  int mr;
  int mv;
  int sm;
  int id;

  void init(int _tl, int _tr, int _tv, int _id) {
    l = r = p = NULL;
    rev = false;
    // init extra variables:
    tl = _tl;
    tr = _tr;
    tv = _tv;
    ml = tl;
    mr = tr;
    mv = tv;
    sm = tv;
    id = _id;
  }

  void unsafe_reverse() {
    rev ^= 1;
    swap(l, r);
    pull();
  }

  // apply changes:
  void unsafe_apply() {
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
  }

  void pull() {
    // now init from self:
    ml = tl;
    mr = tr;
    mv = tv;
    sm = tv;
    if (l != NULL) {
      l->p = this;
      // now pull from l:
      ml = min(ml, l->ml);
      mr = max(mr, l->mr);
      mv = max(mv, l->mv);
      sm += l->sm;
    }
    if (r != NULL) {
      r->p = this;
      // now pull from r:
      ml = min(ml, r->ml);
      mr = max(mr, r->mr);
      mv = max(mv, r->mv);
      sm += r->sm;
    }
  }
};

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

node* get_bst_root(node* v) {
  splay(v);
  return v;
}

pair<node*, node*> split(node* v, const function<bool(node*)> &is_right) {
  if (v == NULL) {
    return {NULL, NULL};
  }
  pair<node*, int> p = find(v, [&](node * u) {
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

template<typename... T>
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

const int N = 1234567;
const int M = 2234567;

int n, m, q, ptr, a[N], l[N], r[N], tl[N], tr[N], tv[N], cur[N];
node* root = NULL;
vector<int> ev[N];
node* erased[N];
set<int> st[N];
stack<int> pl;
node pool[M];

node* new_node(int tl, int tr, int tv) {
  node* v;
  int id;
  if (pl.empty()) {
    v = &pool[ptr];
    id = ptr++;
  } else {
    id = pl.top();
    pl.pop();
    v = &pool[id];
  }
  v->init(tl, tr, tv, id);
  return v;
}

void erase_node(node* v) {
  pl.push(v->id);
}

void add(int x, int l, int r, int ll, int rr, int i) {
  if (ll <= l && r <= rr) {
    ev[x].push_back(i);
  } else {
    int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
    if (ll <= y) {
      add(x + 1, l, y, ll, rr, i);
    }
    if (rr > y) {
      add(z, y + 1, r, ll, rr, i);
    }
  }
}

void solve(int x, int l, int r) {
  for (int i : ev[x]) {
    node* left;
    node* middle;
    node* right;
    node* temp;
    tie(left, temp) = split(root, [&](node* v) { return v->tr >= tl[i]; });
    tie(middle, right) = split(temp, [&](node* v) { return v->tl > tr[i]; });
    node* v = new_node(tl[i], tr[i], tv[i]);
    if (middle != NULL) {
      v->tl = min(v->tl, middle->ml);
      v->tr = max(v->tr, middle->mr);
      v->tv = max(v->tv, middle->mv);
      v->pull();
    }
    erased[i] = middle;
    root = merge(left, merge(v, right));
  }
  reverse(ev[x].begin(), ev[x].end());
  if (l == r) {
    cout << (n - root->sm) << "\n";
  } else {
    int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
    solve(x + 1, l, y);
    solve(z, y + 1, r);
  }
  for (int i : ev[x]) {
    node* left;
    node* middle;
    node* right;
    node* temp;
    tie(left, temp) = split(root, [&](node* v) { return v->tr >= tl[i]; });
    tie(middle, right) = split(temp, [&](node* v) { return v->tl > tr[i]; });
    root = merge(left, merge(erased[i], right));
    erase_node(middle);
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    st[a[i]].insert(i);
  }
  for (int i = 0; i < N; ++i) {
    if (!st[i].empty()) {
      cur[i] = m;
      tl[m] = *st[i].begin();
      tr[m] = *st[i].rbegin();
      tv[m] = st[i].size();
      l[m] = 0;
      r[m] = q;
      m++;
    } else {
      cur[i] = -1;
    }
  }
  for (int i = 1; i <= q; ++i) {
    int p;
    cin >> p;
    --p;
    st[a[p]].erase(p);
    r[cur[a[p]]] = i - 1;
    if (!st[a[p]].empty()) {
      cur[a[p]] = m;
      tl[m] = *st[a[p]].begin();
      tr[m] = *st[a[p]].rbegin();
      tv[m] = st[a[p]].size();
      l[m] = i;
      r[m] = q;
      m++;
    } else {
      cur[a[p]] = -1;
    }
    cin >> a[p];
    st[a[p]].insert(p);
    if (cur[a[p]] != -1) {
      r[cur[a[p]]] = i - 1;
    }
    cur[a[p]] = m;
    tl[m] = *st[a[p]].begin();
    tr[m] = *st[a[p]].rbegin();
    tv[m] = st[a[p]].size();
    l[m] = i;
    r[m] = q;
    m++;
  }
  for (int i = 0; i < m; ++i) {
    if (l[i] <= r[i]) {
      add(0, 0, q, l[i], r[i], i);
    }
  }
  solve(0, 0, q);
  return 0;
}