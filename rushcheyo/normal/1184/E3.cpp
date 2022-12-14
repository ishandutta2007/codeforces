#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 1000005;
int n, m, a[M], b[M], e[M], id[M], fa[N][20], mx[N][20], pa[N], dep[N], fae[N], ans[M];
bool onMST[M];
vector<int> ev[N], g[N];
multiset<int> s[N];

int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }

void dfs(int u) {
  for (int x : g[u]) {
    int v = a[x] + b[x] - u, w = e[x];
    if (v == fa[u][0]) continue;
    dep[v] = dep[u] + 1;
    fae[v] = x;
    fa[v][0] = u;
    mx[v][0] = w;
    dfs(v);
  }
}

pair<int, int> query(int u, int v) {
  int res = 0;
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 16; i >= 0; --i)
    if (fa[u][i] && dep[fa[u][i]] >= dep[v])
      res = max(res, mx[u][i]), u = fa[u][i];
  if (u == v)
    return make_pair(u, res);
  for (int i = 16; i >= 0; --i)
    if (fa[u][i] && fa[v][i] && fa[u][i] != fa[v][i])
      res = max(res, max(mx[v][i], mx[u][i])), u = fa[u][i], v = fa[v][i];
  res = max(res, max(mx[u][0], mx[v][0]));
  return make_pair(fa[u][0], res);
}

void solve(int u) {
  for (int e : g[u]) {
    int v = a[e] + b[e] - u;
    if (v == fa[u][0]) continue;
    solve(v);
    if (s[u].size() < s[v].size()) s[u].swap(s[v]);
    for (int x : s[v]) s[u].insert(x);
    s[v].clear();
  }
  for (int x : ev[u]) {
    if (x >= 0) s[u].insert(x);
    else s[u].erase(s[u].find(x + (1 << 30)));
  }
  if (s[u].empty()) ans[fae[u]] = 1000000000;
  else ans[fae[u]] = *s[u].begin();
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
  for (int i = 1; i <= m; ++i) {
    if (onMST[id[i]]) continue;
    pair<int, int> tmp = query(a[id[i]], b[id[i]]);
    int lca = tmp.first;
    ans[id[i]] = tmp.second;
    ev[a[id[i]]].push_back(e[id[i]]);
    ev[b[id[i]]].push_back(e[id[i]]);
    ev[lca].push_back(-(1 << 30) + e[id[i]]);
    ev[lca].push_back(-(1 << 30) + e[id[i]]);
  }
  solve(1);
  for (int i = 1; i <= m; ++i)
    printf("%d\n", ans[i]);
  return 0;
}