#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 400100;
const int maxv = 20;
int n, m, q;
int beg[maxn], nex[maxn << 1], tto[maxn << 1], e;
void putin(int s, int t) {
  tto[++e] = t;
  nex[e] = beg[s];
  beg[s] = e;
}
int f[maxn][maxv], pre[maxn];
int vr[maxn], dfs_time;
int dep[maxn];
struct node {
  int x, y, lca;
} qus[maxn], w[maxn];
struct Node {
  int id, l, r, op;
};
vector<Node> vec[maxn];
vector<int> pot[maxn];
int top;
int cnt[maxn];
void dfs(int u) {
  dep[u] = dep[f[u][0]] + 1;
  pre[u] = ++dfs_time;
  for (int i = beg[u]; i; i = nex[i]) {
    if (tto[i] == f[u][0])
      continue;
    f[tto[i]][0] = u;
    dfs(tto[i]);
  }
  vr[u] = dfs_time;
}
int nexv[maxn][maxv];
int getlca(int x, int y) {
  if (dep[x] > dep[y])
    swap(x, y);
  if (dep[y] > dep[x]) {
    for (int i = maxv - 1; i >= 0; i--)
      if (dep[f[y][i]] >= dep[x])
        y = f[y][i];
  }
  for (int i = maxv - 1; i >= 0; i--)
    if (f[x][i] != f[y][i])
      x = f[x][i], y = f[y][i];
  if (x != y)
    x = f[x][0], y = f[y][0];
  return x;
}
node ask(int x, int y, int lca) {
  node res;
  res.lca = 0;
  for (int i = maxv - 1; i >= 0; i--)
    if (dep[nexv[x][i]] > dep[lca]) {
      x = nexv[x][i];
      res.lca += 1 << i;
    }
  for (int i = maxv - 1; i >= 0; i--)
    if (dep[nexv[y][i]] > dep[lca]) {
      y = nexv[y][i];
      res.lca += 1 << i;
    }
  res.x = x, res.y = y;
  if (dep[nexv[x][0]] > dep[lca])
    res.lca = -1;
  if (dep[nexv[y][0]] > dep[lca])
    res.lca = -1;
  return res;
}
int save_ans[maxn];
bool vis[maxn];
int tr[maxn];
void add(int x) {
  while (x <= n) {
    tr[x]++;
    x += x & (-x);
  }
}
int getsum(int x) {
  int res = 0;
  while (x) {
    res += tr[x];
    x -= x & (-x);
  }
  return res;
}
void deal(int u) {
  for (int i = beg[u]; i; i = nex[i]) {
    if (f[u][0] == tto[i])
      continue;
    deal(tto[i]);
    if (dep[nexv[tto[i]][0]] < dep[nexv[u][0]])
      nexv[u][0] = nexv[tto[i]][0];
  }
}
int main() {
  scanf("%d", &n);
  for (int s = 2; s <= n; s++) {
    int t;
    scanf("%d", &t);
    putin(s, t);
    putin(t, s);
  }
  dfs(1);
  for (int j = 1; j < maxv; j++)
    for (int i = 1; i <= n; i++)
      f[i][j] = f[f[i][j - 1]][j - 1];
  for (int i = 1; i <= n; i++)
    nexv[i][0] = i;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &w[i].x, &w[i].y);
    w[i].lca = getlca(w[i].x, w[i].y);
    if (dep[w[i].lca] < dep[nexv[w[i].x][0]])
      nexv[w[i].x][0] = w[i].lca;
    if (dep[w[i].lca] < dep[nexv[w[i].y][0]])
      nexv[w[i].y][0] = w[i].lca;
    pot[pre[w[i].x]].push_back(pre[w[i].y]);
    pot[pre[w[i].y]].push_back(pre[w[i].x]);
  }
  deal(1);
  for (int j = 1; j < maxv; j++)
    for (int i = 1; i <= n; i++)
      nexv[i][j] = nexv[nexv[i][j - 1]][j - 1];

  node st;
  Node stt;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &qus[i].x, &qus[i].y);
    qus[i].lca = getlca(qus[i].x, qus[i].y);
    st = ask(qus[i].x, qus[i].y, qus[i].lca);
    save_ans[i] = st.lca;
    if (save_ans[i] == -1) {
      vis[i] = 1;
      continue;
    }
    if (qus[i].x != qus[i].lca && qus[i].y != qus[i].lca) {
      stt = (Node){i, pre[st.y], vr[st.y], -1};
      vec[pre[st.x] - 1].push_back(stt);
      stt = (Node){i, pre[st.y], vr[st.y], 1};
      vec[vr[st.x]].push_back(stt);
    } else {
      vis[i] = 1;
      save_ans[i]++;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < (int)pot[i].size(); j++)
      add(pot[i][j]);
    for (int j = 0; j < (int)vec[i].size(); j++) {
      stt = vec[i][j];
      cnt[stt.id] += (getsum(stt.r) - getsum(stt.l - 1)) * stt.op;
    }
  }
  for (int i = 1; i <= q; i++)
    if (!vis[i]) {
      if (cnt[i])
        save_ans[i]++;
      else
        save_ans[i] += 2;
    }
  for (int i = 1; i <= q; i++) {
    printf("%d\n", save_ans[i]);
  }
  return 0;
}