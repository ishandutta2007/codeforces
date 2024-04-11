#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 2.1e9;

const int N = 200010;

vector < pair <int, int> > g[N];
int x[N], pr[N];
int path[N], new_path[N];
bool alive[N];
int from[N], to[N], cost[N];

int n, m;

void get_path(int s, int t, int &len, int *p) {
  for (int i = 0; i < n; i++) {
    pr[i] = -1;
  }
  int b = 0, e = 1;
  x[0] = s;
  pr[s] = -2;
  while (b < e) {
    int sz = g[x[b]].size();
    for (int j = 0; j < sz; j++) {
      int tov = g[x[b]][j].first;
      int id = g[x[b]][j].second;
      if (pr[tov] != -1 || !alive[id]) {
        continue;
      }
      x[e] = tov;
      pr[tov] = id;
      e++;
    }
    b++;
  }
  if (pr[t] == -1) {
    len = 0;
    return;
  }
  len = 0;
  int cur = t;
  while (cur != s) {
    p[len++] = pr[cur];
    cur = from[pr[cur]] + to[pr[cur]] - cur;
  }
}

bool was[N];
int depth[N], md[N];
bool bridge[N];

void dfs(int v, int pe) {
  was[v] = true;
  int sz = g[v].size();
  md[v] = depth[v];
  for (int j = 0; j < sz; j++) {
    int u = g[v][j].first;
    int id = g[v][j].second;
    if (id == pe || !alive[id]) {
      continue;
    }
    if (!was[u]) {
      depth[u] = depth[v] + 1;
      dfs(u, id);
      md[v] = min(md[v], md[u]);
    } else {
      md[v] = min(md[v], depth[u]);
    }
  }
  if (pe != -1 && md[v] == depth[v]) {
    bridge[pe] = true;
  }
}

void get_bridges() {
  for (int i = 0; i < m; i++) {
    bridge[i] = false;
  }
  for (int i = 0; i < n; i++) {
    was[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      depth[i] = 0;
      dfs(i, -1);
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  int s, t;
  scanf("%d %d", &s, &t);
  s--; t--;
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", from + i, to + i, cost + i);
    from[i]--; to[i]--;
    if (from[i] != to[i]) {
      g[from[i]].push_back(make_pair(to[i], i));
      g[to[i]].push_back(make_pair(from[i], i));
      alive[i] = true;
    }
  }
  get_bridges();
  int plen = 0;
  get_path(s, t, plen, path);
  int best = inf;
  vector <int> res;
  res.clear();
  if (plen == 0) {
    best = 0;
  }
  for (int pos = 0; pos < plen; pos++) {
    int id_a = path[pos];
    alive[id_a] = false;
    int new_plen = 0;
    get_path(s, t, new_plen, new_path);
    if (new_plen == 0) {
      if (cost[id_a] < best) {
        best = cost[id_a];
        res.clear();
        res.push_back(id_a);
      }
    } else {
      get_bridges();
      for (int new_pos = 0; new_pos < new_plen; new_pos++) { 
        int id_b = new_path[new_pos];
        if (bridge[id_b]) {
          if (cost[id_a] + cost[id_b] < best) {
            best = cost[id_a] + cost[id_b];
            res.clear();
            res.push_back(id_a);
            res.push_back(id_b);
          }
        }
      }
    }
    alive[id_a] = true;
  }
  if (best == inf) {
    printf("%d\n", -1);
    return 0;
  }
  sort(res.begin(), res.end());
  printf("%d\n", best);
  int sz = res.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", 1 + res[i]);
  }
  printf("\n");
  return 0;
}