#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 1000005;
int n, m, a[M], b[M], e[M], id[M], fa[N][20], mx[N][20], pa[N], dep[N];
bool onMST[M];
vector<int> g[N];

int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }

void dfs(int u) {
  for (int x : g[u]) {
    int v = a[x] + b[x] - u, w = e[x];
    if (v == fa[u][0]) continue;
    dep[v] = dep[u] + 1;
    fa[v][0] = u;
    mx[v][0] = w;
    dfs(v);
  }
}

int query(int u, int v) {
  int res = 0;
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 16; i >= 0; --i)
    if (fa[u][i] && dep[fa[u][i]] >= dep[v])
      res = max(res, mx[u][i]), u = fa[u][i];
  if (u == v)
    return res;
  for (int i = 16; i >= 0; --i)
    if (fa[u][i] && fa[v][i] && fa[u][i] != fa[v][i])
      res = max(res, max(mx[v][i], mx[u][i])), u = fa[u][i], v = fa[v][i];
  res = max(res, max(mx[u][0], mx[v][0]));
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i)
    scanf("%d%d%d", a + i, b + i, e + i), id[i] = i;
  sort(id + 1, id + 1 + m, [](int x, int y) { return e[x] < e[y]; });
  for (int i = 1; i <= n; ++i) pa[i] = i;
  for (int i = 1; i <= m; ++i)
    if (find(a[id[i]]) != find(b[id[i]]))
      pa[find(a[id[i]])] = find(b[id[i]]), g[a[id[i]]].push_back(id[i]), g[b[id[i]]].push_back(id[i]), onMST[id[i]] = true;
  dfs(1);
  for (int j = 1; j <= 16; ++j)
    for (int i = 1; i <= n; ++i) {
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
      mx[i][j] = max(mx[i][j - 1], mx[fa[i][j - 1]][j - 1]);
    }
  for (int i = 1; i <= m; ++i)
    if (!onMST[i]) printf("%d\n", query(a[i], b[i]));
  return 0;
}