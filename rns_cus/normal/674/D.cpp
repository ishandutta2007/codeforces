#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define M 500010
#define sz(u) ((int)adj[u].size())
#define lft (id << 1)
#define rgt (id << 1 | 1)
#define INF 1e18

#define mx first
#define mn second

typedef pair <LL, LL> PLL;

const int D = 50;

int n, Q, vis[M], f[M];
set <int> adj[M], big;
multiset <LL> setv[M];
LL t[M], v[M];

inline LL F(int x) {return t[x] / (sz(x) + 2);}
inline LL G(int x) {return t[x] - (t[x] / (sz(x) + 2) * (sz(x) + 1));}

PLL nd[M];

void up(int id) {
  nd[id].mx = max(nd[lft].mx, nd[rgt].mx);
  nd[id].mn = min(nd[lft].mn, nd[rgt].mn);
}

void build(int id, int l, int r) {
  if (l == r) {
    nd[id] = PLL(-INF, INF); return;
  }
  int mid = (l + r) >> 1;
  build(lft, l, mid);
  build(rgt, mid + 1, r);
  up(id);
}

void update(int id, int l, int r, int x, LL v) {
  if (l == r) {
    if (v == INF) nd[id] = PLL(-INF, INF);
    else nd[id] = PLL(v, v);
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) update(lft, l, mid, x, v);
  else update(rgt, mid + 1, r, x, v);
  up(id);
}

void init() {
  for (int i = 1; i <= n; i++) v[i] = 0, vis[i] = 0;
  big.clear();
  for (int i = 1; i <= n; i++) setv[i].clear();

  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    for (auto it : adj[i]) v[i] += F(it);
    v[i] += G(i);
    if (sz(i) >= D) {
      big.insert(i); vis[i] = 1;
    }
    int u = f[i];
    if (sz(u) >= D) {
      setv[u].insert(v[i]);
    }
    else {
      update(1, 1, n, i, v[i] + F(u));
    }
  }
}

void upd(int x, LL val) {
  if (!vis[f[x]]) {
    update(1, 1, n, x, v[x] + F(f[x]));
  }
  else {
    int u = f[x];
    setv[u].erase(setv[u].find(val));
    setv[u].insert(v[x]);
  }
}

void del(int a, int b) {
  int c = f[b];
  LL tvb = v[b], tvc = v[c];

  v[b] -= F(a);
  v[b] -= G(b), v[c] -= F(b);
  adj[b].erase(a), v[c] += F(b);
  v[b] += G(b);
  upd(b, tvb); upd(c, tvc);
  if (!vis[b]) {
    LL vv = F(b);
    for (auto it : adj[b]) {
      update(1, 1, n, it, v[it] + vv);
    }
  }
  else {
    setv[b].erase(setv[b].find(v[a]));
  }
}

void add(int a, int b) {
  int c = f[b];
  LL tvb = v[b], tvc = v[c];

  v[b] += F(a);
  v[b] -= G(b), v[c] -= F(b);
  adj[b].insert(a), v[c] += F(b);
  v[b] += G(b);
  upd(b, tvb); upd(c, tvc);
  if (!vis[b]) {
    LL vv = F(b);
    for (auto it : adj[b]) {
      update(1, 1, n, it, v[it] + vv);
    }
  }
  else {
    setv[b].insert(v[a]); update(1, 1, n, a, INF);
  }
}

int main() {
  //freopen("D.in", "r", stdin);
  scanf("%d %d", &n, &Q);
  for (int i = 1; i <= n; i++) scanf("%I64d", t + i);
  for (int i = 1; i <= n; i++) {
    scanf("%d", f + i); adj[f[i]].insert(i);
  }

  init();

  int type, x, y, cnt(0);

  while (Q--) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d %d", &x, &y);
      if (f[x] == y) continue;
      del(x, f[x]);
      add(x, y);
      f[x] = y;
    }
    else if (type == 2) {
      scanf("%d", &x);
      printf("%I64d\n", v[x] + F(f[x]));
    }
    else {
      PLL tp = nd[1];
      for (auto it : big) {
        if (setv[it].empty()) continue;
        LL mn = *(setv[it].begin()) + F(it), mx = *(--setv[it].end()) + F(it);
        tp.mx = max(tp.mx, mx), tp.mn = min(tp.mn, mn);
      }
      printf("%I64d %I64d\n", tp.mn, tp.mx);
    }
  }
}