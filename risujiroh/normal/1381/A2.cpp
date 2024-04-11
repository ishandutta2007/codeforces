#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

namespace treap {
struct node {
  int pri, sz;
  node *l, *r;
  char c;
  bool rev;
} *nil = new node();
node *new_node(char c) {
  static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  static node pool[(64 << 20) / sizeof(node)], *a = pool;
  a->pri = mt(), a->sz = 1;
  a->l = a->r = nil;
  a->c = c;
  return a++;
}
node *update(node *a) {
  a->sz = a->l->sz + 1 + a->r->sz;
  return a;
}
void reverse(node *a) {
  if (a == nil) return;
  swap(a->l, a->r);
  a->c ^= 1;
  a->rev ^= true;
}
void push(node *a) {
  if (a->rev) {
    reverse(a->l), reverse(a->r);
    a->rev = false;
  }
}
node *merge(node *a, node *b) {
  if (a == nil) return b;
  if (b == nil) return a;
  if (a->pri < b->pri) {
    push(b);
    b->l = merge(a, b->l);
    return update(b);
  } else {
    push(a);
    a->r = merge(a->r, b);
    return update(a);
  }
}
pair<node *, node *> split(node *a, int i) {
  if (a == nil) return {nil, nil};
  push(a);
  node *b;
  if (a->l->sz < i) {
    tie(a->r, b) = split(a->r, i - a->l->sz - 1);
    return {update(a), b};
  } else {
    tie(b, a->l) = split(a->l, i);
    return {b, update(a)};
  }
}
node *insert(node *a, int i, node *b) {
  assert(b->sz == 1);
  if (a == nil or a->pri < b->pri) {
    push(b);
    tie(b->l, b->r) = split(a, i);
    return update(b);
  }
  push(a);
  if (a->l->sz < i) {
    a->r = insert(a->r, i - a->l->sz - 1, b);
  } else {
    a->l = insert(a->l, i, b);
  }
  return update(a);
}
node *erase(node *a, int i) {
  if (a == nil) return a;
  push(a);
  if (i == a->l->sz) {
    return merge(a->l, a->r);
  }
  if (a->l->sz < i) {
    a->r = erase(a->r, i - a->l->sz - 1);
  } else {
    a->l = erase(a->l, i);
  }
  return update(a);
}
node *access(node *a, int i) {
  if (a == nil or i == a->l->sz) return a;
  push(a);
  if (a->l->sz < i) {
    return access(a->r, i - a->l->sz - 1);
  } else {
    return access(a->l, i);
  }
}
} // namespace treap

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    auto t = treap::nil;
    for (char c : a) {
      t = insert(t, t->sz, treap::new_node(c));
    }
    vector<int> res;
    auto op = [&](int p) {
      auto [l, r] = split(t, p);
      reverse(l);
      t = merge(l, r);
      res.push_back(p);
    };
    for (int i = n; i--; ) {
      if (access(t, i)->c == b[i]) continue;
      if (access(t, 0)->c != b[i]) {
        op(i + 1);
        continue;
      }
      op(1);
      op(i + 1);
    }
    cout << size(res);
    for (auto e : res) {
      cout << ' ' << e;
    }
    cout << '\n';
  }
}