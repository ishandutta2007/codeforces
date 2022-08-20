#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const int inf = 0x3f3f3f3f;

struct edge_t {
  int u, v, w;

  bool operator < (const edge_t &b) const {
    return w < b.w;
  }
} e[N];

int n, m, q, f[N], tag[N], depth[N], value[N], parent[N];
vector<pair<int, int>> adj[N];

int find(int x) {
  while (x != f[x]) {
    x = f[x] = f[f[x]];
  }
  return x;
}

void dfs(int x) {
  for (auto e : adj[x]) {
    if (e.first != parent[x]) {
      parent[e.first] = x;
      value[e.first] = e.second;
      depth[e.first] = depth[x] + 1;
      dfs(e.first);
    }
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d %d", &n, &q, &m);
  for (int i = 1; i <= q; ++i) {
    scanf("%d %d", &e[i].u, &e[i].v);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d", &e[i + q].u, &e[i + q].v, &e[i + q].w);
  }
  sort(e + 1, e + m + q + 1);
  for (int i = 1; i <= n; ++i) {
    f[i] = i;
  }
  for (int i = 1; i <= m + q; ++i) {
    if (find(e[i].u) != find(e[i].v)) {
      f[find(e[i].u)] = find(e[i].v);
      adj[e[i].u].push_back(make_pair(e[i].v, e[i].w));
      adj[e[i].v].push_back(make_pair(e[i].u, e[i].w));
    }
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    f[i] = i;
    tag[i] = inf;
  }
  for (int i = 1; i <= m; ++i) {
    int x = find(e[i + q].u), y = find(e[i + q].v), w = e[i + q].w;
    while (x != y) {
      if (depth[x] >= depth[y]) {
        tag[x] = w;
        f[x] = parent[x];
        x = find(x);
      } else {
        tag[y] = w;
        f[y] = parent[y];
        y = find(y);
      }
    }
  }
  long long answer = 0;
  for (int i = 2; i <= n; ++i) {
    if (!value[i]) {
      if (tag[i] == inf) {
        puts("-1");
        return 0;
      } else {
        answer += tag[i];
      }
    }
  }
  printf("%lld\n", answer);
  return 0;
}