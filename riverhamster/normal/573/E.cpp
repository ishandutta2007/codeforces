#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <random>
#include <chrono>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100005;

struct node {
  ll val, tag;
  int sz;
  unsigned int pr;
  node *lc, *rc;
} t[N], *alloc = t;

node *root = nullptr;

void up(node *x) {
  x->sz = (x->lc ? x->lc->sz : 0) + (x->rc ? x->rc->sz : 0) + 1;
}
void tag(node *x, ll v) {
  if (x) {
    x->tag += v;
    x->val += v;
  }
}
void down(node *x) {
  if (x->tag) {
    tag(x->lc, x->tag);
    tag(x->rc, x->tag);
    x->tag = 0;
  }
}
void split(node *x, node *&l, node *&r, ll val, int left_size = 0) {
  if (!x) {
    l = r = nullptr;
    return;
  }
  down(x);
  int lsz = x->lc ? x->lc->sz + 1 : 1;
  if (x->val > (left_size + lsz) * val) {
    l = x;
    split(x->rc, x->rc, r, val, left_size + lsz);
  }
  else {
    r = x;
    split(x->lc, l, x->lc, val, left_size);
  }
  up(x);
}
void splice(node *&x, node *l, node *r) {
  if (!l) return void(x = r);
  if (!r) return void(x = l);
  if (l->pr < r->pr) {
    down(l);
    x = l;
    splice(x->rc, x->rc, r);
  }
  else {
    down(r);
    x = r;
    splice(x->lc, l, x->lc);
  }
  up(x);
}
node *create_node(ll val) {
  alloc->pr = rng();
  alloc->sz = 1;
  alloc->val = val;
  return alloc++;
}

ll cur = 0, res = 0;

void DFS(node *x) {
  if (!x) return;
  down(x);
  DFS(x->lc);
  cur += x->val;
  res = max(res, cur);
  DFS(x->rc);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  for (int i = 1; i <= n; ++i) {
    int val;
    read(val);
    node *r;
    split(root, root, r, val);
    int lsz = root ? root->sz + 1 : 1;
    splice(root, root, create_node((ll)val * lsz));
    tag(r, val);
    splice(root, root, r);
  }
  DFS(root);
  printf("%lld\n", res);
  return 0;
}