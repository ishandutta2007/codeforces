#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <set>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x){
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

char notspace() {
  char ch;
  while (isspace(ch = getchar()));
  return ch;
}

const int N = 200005;

struct segment_tree { // 0-indexed
  int t[N * 2];
  int len;
  void init(int *a, int n) {
    len = n;
    copy(a, a + n, t + n);
    for (int i = n - 1; i >= 1; --i) t[i] = min(t[i << 1], t[i << 1 | 1]);
  }
  void update(int p, int v) {
    p += len; t[p] = v;
    for (p >>= 1; p; p >>= 1) t[p] = min(t[p << 1], t[p << 1 | 1]);
  }
  int query(int l, int r) {
    int res = numeric_limits<int>::max();
    for (l += len, r += len; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = min(res, t[l++]);
      if (r & 1) res = min(res, t[--r]);
    }
    return res;
  }
} seg;

vector<int> G[N], T[N];
multiset<int> block[N];
int n, m, q;

namespace HLD {
  int fa[N], top[N], sz[N], son[N], dep[N], id[N], idx = 0;
  void dfs1(int x) {
    sz[x] = 1;
    for (int v : T[x]) {
      if (v == fa[x]) continue;
      fa[v] = x; dep[v] = dep[x] + 1;
      dfs1(v);
      sz[x] += sz[v];
      if (sz[v] > sz[son[x]]) son[x] = v;
    }
  }
  void dfs2(int x) {
    id[x] = idx++;
    if (!son[x]) return;
    top[son[x]] = top[x];
    dfs2(son[x]);
    for (int v : T[x]) {
      if (v == fa[x] || v == son[x]) continue;
      top[v] = v; dfs2(v);
    }
  }
  int query(int u, int v) { // block LCA handled
    int res = numeric_limits<int>::max();
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]]) swap(u, v);
      res = min(res, seg.query(id[top[u]], id[u] + 1));
      u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    res = min(res, seg.query(id[u], id[v] + 1));
    if (u > n) res = min(res, seg.query(id[fa[u]], id[fa[u]] + 1));
    return res;
  }
}
using HLD::fa;

int w[N], idw[N];

int nc = 0;
namespace BlockForest {
  int low[N], dfn[N], idx = 0;
  int stk[N], top = 0;

  void tarjan(int x) {
    low[x] = dfn[x] = ++idx;
    stk[++top] = x;
    for (int v : G[x])
      if (!dfn[v]) {
        tarjan(v);
        low[x] = min(low[x], low[v]);
        if (low[v] == dfn[x]) {
          ++nc;
          int tp = -1;
          while (tp != v) {
            tp = stk[top--];
            T[tp].push_back(nc); T[nc].push_back(tp);
          }
          T[x].push_back(nc); T[nc].push_back(x);
        }
      }
      else low[x] = min(low[x], dfn[v]);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, m, q);
  nc = n;
  for (int i = 1; i <= n; ++i) read(w[i]);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v); G[v].push_back(u);
  }
  BlockForest::tarjan(1);
  HLD::dfs1(1); HLD::dfs2(1);
  for (int i = 1; i <= n; ++i)
    if (fa[i] > n)
      block[fa[i]].insert(w[i]);
  for (int i = n + 1; i <= nc; ++i)
    idw[HLD::id[i]] = *block[i].begin();
  for (int i = 1; i <= n; ++i) idw[HLD::id[i]] = w[i];
  seg.init(idw, nc);
  while (q--) {
    if (notspace() == 'C') {
      int u, w; read(u, w);
      int org = seg.query(HLD::id[u], HLD::id[u] + 1);
      seg.update(HLD::id[u], w);
      if (fa[u] > n) {
        auto nh = block[fa[u]].extract(org);
        nh.value() = w; block[fa[u]].insert(move(nh));
        seg.update(HLD::id[fa[u]], *block[fa[u]].begin());
      }
    }
    else {
      int u, v; read(u, v);
      printf("%d\n", HLD::query(u, v));
    }
  }
  return 0;
}