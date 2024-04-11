#include <bits/stdc++.h>

using namespace std;

class node {
 public:
  node* l;
  node* r;
  node* p;
  long long square_light;
  int light;
  int size;
  int id;

  node(int id): id(id) {
    l = r = p = NULL;
    square_light = 0;
    light = size = 1;
  }

  void pull() {
    size = light;
    if (l != NULL) {
      l->p = this;
      size += l->size;
    }
    if (r != NULL) {
      r->p = this;
      size += r->size;
    }
  }
};

bool is_bst_root(node* v) {
  if (v == NULL) {
    return false;
  }
  return (v->p == NULL || (v->p->l != v && v->p->r != v));
}

void rotate(node* v) {
  node* u = v->p;
  assert(u != NULL);
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

void access(node* v) {
  node* u = NULL;
  while (v != NULL) {
    splay(v);
    if (v->r != NULL) {
      v->square_light += (long long) v->r->size * v->r->size;
      v->light += v->r->size;
    }
    v->r = u;
    if (v->r != NULL) {
      v->square_light -= (long long) v->r->size * v->r->size;
      v->light -= v->r->size;
    }
    u = v;
    v = v->p;
  }
}

node* find_root(node* v) {
  access(v);
  splay(v);
  while (v->l != NULL) {
    v = v->l;
  }
  splay(v);
  return v;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    --c[i];
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int from, to;
    cin >> from >> to;
    --from;
    --to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  vector<vector<pair<int, int>>> events(n);
  for (int i = 0; i < n; ++i) {
    events[c[i]].emplace_back(i, 0);
  }
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    events[c[x]].emplace_back(x, i);
    c[x] = y;
    events[c[x]].emplace_back(x, i);
  }
  vector<int> parent(n + 1);
  function<void(int)> dfs = [&](int x) {
    for (auto y : adj[x]) {
      if (y != parent[x]) {
        parent[y] = x;
        dfs(y);
      }
    }
  };
  parent[0] = n;
  dfs(0);
  vector<node*> tree(n + 1);
  for (int i = 0; i <= n; ++i) {
    tree[i] = new node(i);
  }
  long long ans = 0;
  auto link = [&](node* v, node* u) {
    access(v);
    splay(v);
    ans -= v->square_light;
    node* w = find_root(u);
    access(w);
    ans -= w->square_light;
    access(u);
    splay(u);
    v->p = u;
    u->square_light += (long long) v->size * v->size;
    u->light += v->size;
    u->pull();
    access(w);
    splay(w);
    ans += w->square_light;
  };
  auto cut = [&](node* v, node* u) {
    node* w = find_root(v);
    access(w);
    ans -= w->square_light;
    access(u);
    splay(u);
    v->p = NULL;
    u->square_light -= (long long) v->size * v->size;
    u->light -= v->size;
    u->pull();
    access(w);
    splay(w);
    ans += w->square_light;
    access(v);
    splay(v);
    ans += v->square_light;
  };
  for (int i = 0; i < n; ++i) {
    link(tree[i], tree[parent[i]]);
  }
  vector<bool> black(n, true);
  vector<long long> add(m + 1);
  for (int i = 0; i < n; ++i) {
    long long last = ans;
    add[0] += last;
    for (auto p : events[i]) {
      if (black[p.first]) {
        cut(tree[p.first], tree[parent[p.first]]);
      } else {
        link(tree[p.first], tree[parent[p.first]]);
      }
      black[p.first] = !black[p.first];
      add[p.second] += ans - last;
      last = ans;
    }
    for (auto p : events[i]) {
      if (!black[p.first]) {
        link(tree[p.first], tree[parent[p.first]]);
        black[p.first] = true;
      }
    }
  }
  long long cur = (long long) n * n * n;
  for (int i = 0; i <= m; ++i) {
    cur -= add[i];
    cout << cur << "\n";
  }
  return 0;
}