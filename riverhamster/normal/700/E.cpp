#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

const int N = 200005;
const int Node = 400005;

struct node {
  int lc, rc;
} t[Node * 20];
int segnc = 0;
void insert(int &x, int l, int r, int p) {
  ++segnc; t[segnc] = t[x]; x = segnc;
  if (l == r) return;
  int mid = (l + r) >> 1;
  p <= mid ? insert(t[x].lc, l, mid, p) : insert(t[x].rc, mid + 1, r, p);
}
bool query(int x, int l, int r, int ql, int qr) {
  if (!x) return false;
  if (ql <= l && r <= qr) return true;
  int mid = (l + r) >> 1;
  if (qr <= mid) return query(t[x].lc, l, mid, ql, qr);
  if (ql > mid) return query(t[x].rc, mid + 1, r, ql, qr);
  return query(t[x].lc, l, mid, ql, qr) || query(t[x].rc, mid + 1, r, ql, qr);
}
int find_first(int x, int l, int r) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  if (t[x].lc) return find_first(t[x].lc, l, mid);
  return find_first(t[x].rc, mid + 1, r);
}
int combine(int x, int y) {
  if (!x || !y) return x | y;
  int id = ++segnc;
  t[id].lc = combine(t[x].lc, t[y].lc);
  t[id].rc = combine(t[x].rc, t[y].rc);
  return id;
}

int fa[Node], c[Node][26], len[Node];
int nc = 0, last = 0, pos = 0;
vector<int> G[Node];
int res = 0;
int right[Node], tr[Node], f[Node];
int n;

void extend(int ch) {
  int np = ++nc, p = last; len[np] = len[last] + 1; last = np;
  insert(right[np], 1, n, ++pos);
  for (; p != -1 && !c[p][ch]; p = fa[p]) c[p][ch] = np;
  if (p == -1) { fa[np] = 0; return; }
  int q = c[p][ch];
  if (len[q] == len[p] + 1) { fa[np] = q; return; }
  int nq = ++nc; copy_n(c[q], 26, c[nq]); len[nq] = len[p] + 1;
  fa[nq] = fa[q]; fa[np] = fa[q] = nq;
  for (; p != -1 && c[p][ch] == q; p = fa[p]) c[p][ch] = nq;
}

void build(int x) {
  for (int v : G[x])
    build(v), right[x] = combine(right[x], right[v]);
}

void solve(int x) {
  res = max(res, f[x]);
  for (int v : G[x]) {
    int r = find_first(right[v], 1, n);
    int minpos = r - len[v] + len[tr[x]];
    if (!x || query(right[tr[x]], 1, n, minpos, r - 1))
      f[v] = f[x] + 1, tr[v] = v;
    else
      f[v] = f[x], tr[v] = tr[x];
    solve(v);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  scanf("%d", &n);
  static char s[N];
  scanf("%s", s);
  fa[0] = -1;
  for (char *p = s; *p; ++p) extend(*p - 'a');
  for (int i = 1; i <= nc; ++i)
    G[fa[i]].push_back(i);
  build(0);
  solve(0);
  printf("%d\n", res);
  return 0;
}