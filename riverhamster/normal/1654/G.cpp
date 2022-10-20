#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int logN = 19;

int h[N], n;
vector<int> G[N];
int dp[N];

void BFS() {
  static int q[N];
  int ql = 0, qr = 0;
  for (int i = 1; i <= n; ++i)
    if (!h[i]) q[++qr] = i;
  while (ql < qr) {
    int u = q[++ql];
    for (int v : G[u])
      if (h[v] > h[u] + 1) h[v] = h[u] + 1, q[++qr] = v;
  }
}

int sz[N], son[N];
bool del[N];
int tfa[N], tdep[N];
int _pol[N * logN * 2], *alloc = _pol;
int *mn[N];
int dis_up[logN][N], dis_down[logN][N], *cdis;

void getsiz(int u, int fa = 0) {
  sz[u] = 1; son[u] = 0;
  for (int v : G[u])
    if (v != fa && !del[v]) {
      getsiz(v, u), sz[u] += sz[v];
      if (sz[v] > sz[son[u]]) son[u] = v;
    }
}

void subDFS1(int u, int fa = 0, int d = 0, int mxd = 0) {
  cdis[u] = d == mxd ? d : INF;
  for (int v : G[u]) {
    if (v == fa || del[v]) continue;
    if (h[v] > h[u]) subDFS1(v, u, d + 1, max(d + 1, mxd));
    else if (h[v] == h[u]) subDFS1(v, u, d - 1, mxd);
  }
}

void subDFS2(int u, int fa = 0, int d = 0, int mxd = 0) {
  cdis[u] = d == mxd ? d : INF;
  for (int v : G[u]) {
    if (v == fa || del[v]) continue;
    if (h[v] < h[u]) subDFS2(v, u, d - 1, mxd);
    else if (h[v] == h[u]) subDFS2(v, u, d + 1, max(mxd, d + 1));
  }
}

void work(int u, int dep) {
  cdis = dis_up[dep];
  subDFS1(u);
  cdis = dis_down[dep];
  subDFS2(u);
}

int build(int u, int dep = 0) {
  getsiz(u);
  int g = u, tot = sz[u];
  while (sz[son[g]] * 2 > tot) g = son[g];
  del[g] = true; tdep[g] = dep;
  work(g, dep);
  mn[g] = alloc + sz[u]; alloc += 2 * sz[u] + 1;
  for (int v : G[g])
    if (!del[v]) {
      int r = build(v, dep + 1);
      tfa[r] = g;
    }
  return g;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  memset(_pol, 0x3f, sizeof(_pol));
  memset(dis_up, 0x3f, sizeof(dis_up)); memset(dis_down, 0x3f, sizeof(dis_down));
  read(n);
  memset(h, 0x3f, sizeof(h));
  for (int i = 1; i <= n; ++i) {
    int x; read(x);
    if (x) h[i] = 0;
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v); G[v].push_back(u);
  }
  BFS();
  build(1);
  vector<int> perm(n);
  iota(all(perm), 1);
  sort(all(perm), [](int x, int y) { return h[x] < h[y]; });
  memset(dp, 0x3f, sizeof(dp));
  for (int u : perm) {
    for (int v : G[u]) {
      if (h[u] > h[v]) dp[u] = min(dp[u], dp[v]);
      else if (h[u] == h[v]) dp[u] = min(dp[u], h[u]);
    }
    for (int p = u, d = tdep[p]; p; p = tfa[p], --d)
      if (dis_up[d][u] != INF) {
        dp[u] = min(dp[u], mn[p][dis_up[d][u]]);
      }
    for (int p = u, d = tdep[p]; p; p = tfa[p], --d)
      if (dis_down[d][u] != INF) {
        mn[p][dis_down[d][u]] = min(mn[p][dis_down[d][u]], dp[u]);
      }
  }
  for (int i = 1; i <= n; ++i)
    if (dp[i] == INF) printf("%d%c", h[i], " \n"[i == n]);
    else printf("%d%c", 2 * h[i] - dp[i], " \n"[i == n]);
  return 0;
}