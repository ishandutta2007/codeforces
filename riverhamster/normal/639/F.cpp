#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
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

const int N = 300005;
const int inf = 1e9;

int n, m, q;

struct node {
  int fa;
  int c[2];
  int mn, val, tag;
  bool rev;
} t[N * 2];
int nc;

void addtag(int x, int v) { t[x].mn += v; t[x].val += v; t[x].tag += v; }
void revtag(int x) { swap(t[x].c[0], t[x].c[1]); t[x].rev ^= 1; }
void down(int x) {
  if (t[x].tag) {
    if (t[x].c[0]) addtag(t[x].c[0], t[x].tag);
    if (t[x].c[1]) addtag(t[x].c[1], t[x].tag);
    t[x].tag = 0;
  }
  if (t[x].rev) {
    if (t[x].c[0]) revtag(t[x].c[0]);
    if (t[x].c[1]) revtag(t[x].c[1]);
    t[x].rev = false;
  }
}
void up(int x) { t[x].mn = min({t[t[x].c[0]].mn, t[t[x].c[1]].mn, t[x].val}); }

bool ident(int x) { return t[t[x].fa].c[1] == x; }
bool nroot(int x) { return t[t[x].fa].c[0] == x || t[t[x].fa].c[1] == x; }

void rotate(int x) {
  int f = t[x].fa, r = t[f].fa;
  bool dx = ident(x), df = ident(f);
  t[f].c[dx] = t[x].c[dx ^ 1]; if (t[x].c[dx ^ 1]) t[t[x].c[dx ^ 1]].fa = f;
  t[x].fa = r; if (nroot(f)) t[r].c[df] = x;
  t[x].c[dx ^ 1] = f; t[f].fa = x;
  up(f);
}

void down_all(int x) {
  if (nroot(x)) down_all(t[x].fa);
  down(x);
}
void splay(int x) {
  assert(x);
  down_all(x);
  for (; nroot(x); rotate(x))
    if (nroot(t[x].fa)) rotate(ident(x) == ident(t[x].fa) ? t[x].fa : x);
  up(x);
}

int access(int x) {
  int y;
  for (y = 0; x; y = x, x = t[x].fa)
    splay(x), t[x].c[1] = y, up(x);
  return y;
}

void makeroot(int x) { revtag(access(x)); }
int findroot(int x) {
  x = access(x);
  while (t[x].c[0]) x = t[x].c[0], down(x);
  splay(x);
  return x;
}
int split(int u, int v) { makeroot(u); return access(v); }
void link(int u, int v) { makeroot(v); splay(v); t[v].fa = u; }
void cut(int u, int v) {
  makeroot(u);
  (void)access(v); splay(v);
  t[v].c[ident(u)] = 0; t[u].fa = 0; up(v);
}

int R;
int decrypt(int e) {
  e = (e + R) % n;
  return !e ? n : e;
}

int v[N];
struct operation {
  int u, v;
  bool cut;
} op[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, m, q);
  t[0].mn = t[0].val = inf;
  nc = n;
  for (int i = 1; i <= n; ++i) t[i].mn = t[i].val = inf;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u, v);
    if (findroot(u) == findroot(v)) {
      int rt = split(u, v);
      addtag(rt, 1);
    }
    else {
      ++nc; t[nc].mn = t[nc].val = t[nc].tag = 0;
      link(u, nc); link(v, nc);
      assert(findroot(u) == findroot(nc) && findroot(nc) == findroot(v));
    }
  }
  for (int qid = 1; qid <= q; ++qid) {
    int vc, ec;
    read(vc, ec);
    for (int i = 1; i <= vc; ++i)
      read(v[i]), v[i] = decrypt(v[i]);
    for (int i = 1; i <= ec; ++i) {
      int u, v;
      read(u, v);
      u = decrypt(u), v = decrypt(v);
      op[i].u = u; op[i].v = v;
      if (findroot(u) == findroot(v)) {
        addtag(split(u, v), 1);
        op[i].cut = false;
      }
      else {
        op[i].cut = true;
        ++nc; t[nc].val = t[nc].mn = t[nc].tag = 0;
        link(u, nc); link(v, nc);
      }
    }
    bool flag = true;
    makeroot(v[1]);
    for (int i = 2; i <= vc; ++i) {
      int r = access(v[i]);
      if (t[r].mn == 0) { flag = false; break; }
      while (t[r].c[0]) r = t[r].c[0], down(r);
      if (r != v[1]) { flag = false; break; }
    }
    if (flag) puts("YES"), R = (R + qid) % n;
    else puts("NO");
    for (int i = ec; i >= 1; --i) {
      if (op[i].cut) cut(op[i].u, nc), cut(op[i].v, nc), --nc;
      else {
        int r = split(op[i].u, op[i].v);
        addtag(r, -1);
      }
    }
  }
  return 0;
}