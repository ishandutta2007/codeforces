#include <bits/stdc++.h>

using namespace std;

#define N 100100
#define ls id << 1
#define rs id << 1 | 1

int n, m, tot, tt, ans;
int dis[N], fin[N];
int head[N], to[N << 1], nxt[N << 1], bin[N], f[N];
vector <int> v[N];

int mn[N << 2], sz[N << 2], addv[N << 2];

void add(int x, int y) {
  nxt[++ tot] = head[x]; head[x] = tot; to[tot] = y;
  nxt[++ tot] = head[y]; head[y] = tot; to[tot] = x;
}

void dfs(int r, int pa = 0) {
  dis[r] = ++ tt;
  for(int i = head[r]; i; i = nxt[i]) {
    if(to[i] == pa) continue;
    dfs(to[i], r);
  }
  fin[r] = tt;
}

void up(int id) {
  mn[id] = min(mn[ls], mn[rs]);
  sz[id] = 0;
  if(mn[id] == mn[ls]) sz[id] += sz[ls];
  if(mn[id] == mn[rs]) sz[id] += sz[rs];
}

void down(int id) {
  if(addv[id]) {
    addv[ls] += addv[id]; mn[ls] += addv[id];
    addv[rs] += addv[id]; mn[rs] += addv[id];
    addv[id] = 0;
  }
}

void update(int l, int r, int id, int L, int R, int v) {
  if(L <= l && r <= R) {
    mn[id] += v; addv[id] += v;
    if(v == mn[id]) ans += sz[id];
    if(v < 0 && !mn[id]) ans -= sz[id];
    return ;
  }
  down(id);
  int md = (l + r) >> 1;
  if(L <= md) update(l, md, ls, L, R, v);
  if(R > md) update(md + 1, r, rs, L, R, v);
  up(id);
}

void build(int l, int r, int id) {
  sz[id] = r - l + 1;
  if(l == r) return;
  int md = (l + r) >> 1;
  build(l, md, ls); build(md + 1, r, rs);
}

void run(int r, int pa = 0) {
  if(bin[r] || (int)v[r].size() > 0) update(1, n, 1, dis[r], fin[r], 1);
  for(int i = 0; i < (int)v[r].size(); i ++) update(1, n, 1, dis[v[r][i]], fin[v[r][i]], 1);
  f[r] = ans;
  if(f[r]) f[r] --;
  for(int i = head[r]; i; i = nxt[i]) {
    if(to[i] == pa) continue;
    run(to[i], r);
  }
  if(bin[r] || (int)v[r].size() > 0) update(1, n, 1, dis[r], fin[r], -1);
  for(int i = 0; i < (int)v[r].size(); i ++) update(1, n, 1, dis[v[r][i]], fin[v[r][i]], -1);
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i < n; i ++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
  }
  dfs(1);
  build(1, n, 1);
  for(int i = 1; i <= m; i ++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if(dis[x] <= dis[y] && fin[y] <= fin[x]) {
      bin[x] = 1;
    } else if(dis[y] <= dis[x] && fin[x] <= fin[y]) {
      bin[y] = 1;
    } else {
      v[x].push_back(y); v[y].push_back(x);
    }
  }
  run(1);
  for(int i = 1; i <= n; i ++) printf("%d ", f[i]); puts("");
  return 0;
}