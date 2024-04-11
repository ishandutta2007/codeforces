#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

const int MaxN = 55, MaxE = 2505;

struct edge {
  int v, nt, f, c;
};
edge e[MaxE * 2];
int hd[MaxN], cur[MaxN], ec = 0;
int n, m;
void link(int x, int y, int flow, int cost) {
  e[ec] = {y, hd[x], flow, cost}; hd[x] = ec++;
  e[ec] = {x, hd[y], 0, -cost}; hd[y] = ec++;
}

const int INF = 1000000000;

vector<pair<long long, int>> V;
int h[MaxN];
bool vis[MaxN];

bool shortest_path() {
  static int q[MaxN * MaxN * MaxN];
  static bool instk[MaxN];
  fill(instk + 1, instk + 1 + n, false);
  fill(h + 1, h + 1 + n, INF);
  h[1] = 0;
  int l = 0, r = 1; q[r] = 1;
  while (l < r) {
    int x = q[++l];
    instk[x] = false;
    for (int i = hd[x]; i != -1; i = e[i].nt) {
      if (e[i].f > 0 && h[x] + e[i].c < h[e[i].v]) {
        h[e[i].v] = h[x] + e[i].c;
        if (!instk[e[i].v]) q[++r] = e[i].v;
      }
    }
  }
  return h[n] != INF;
}
int dfs(int x, int fl) {
  if (!fl) return 0;
  if (x == n) return fl;
  int flow = 0;
  vis[x] = true;
  for (int &i = cur[x]; i != -1; i = e[i].nt) {
    if (h[e[i].v] != h[x] + e[i].c || vis[e[i].v]) continue;
    int aug = min(e[i].f, fl);
    aug = min(aug, dfs(e[i].v, aug));
    flow += aug; fl -= aug;
    e[i].f -= aug; e[i ^ 1].f += aug;
    if (!fl) { vis[x] = false; return flow; }
  }
  vis[x] = false;
  if (!flow) h[x] = -INF;
  return flow;
}

void mincost_flow() {
  int flow = 0;
  long long cost = 0;
  while (shortest_path()) {
    copy(hd + 1, hd + 1 + n, cur + 1);
    int f = dfs(1, INF);
    flow += f; cost += 1LL * h[n] * f;
    V.emplace_back(cost, flow);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  memset(hd, -1, sizeof(hd));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v, dist;
    scanf("%d%d%d", &u, &v, &dist);
    link(u, v, 1, dist);
  }

  mincost_flow();

  int q;
  for (scanf("%d", &q); q; --q) {
    int cost;
    scanf("%d", &cost);
    double res = 1e30;
    for (auto p : V)
      res = min(res, 1.0 * (p.first + cost) / p.second);
    printf("%.12lf\n", res);
  }
  return 0;
}