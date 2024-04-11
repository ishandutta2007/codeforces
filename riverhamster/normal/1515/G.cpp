#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 200005;

vector<int> G[N];
vector<tuple<int, int, int>> uG[N];
int dfn[N], low[N], dfc = 0;
int stk[N], top = 0;
bool instk[N];
int scc[N], scnt = 0;

void tarjan(int u) {
  dfn[u] = low[u] = ++dfc;
  stk[++top] = u; instk[u] = true;
  for (int v : G[u])
    if (!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
    else if (instk[v]) low[u] = min(low[u], dfn[v]);
  if (low[u] == dfn[u]) {
    int t;
    ++scnt;
    do {
      t = stk[top--];
      scc[t] = scnt;
      instk[t] = false;
    } while (t != u);
  }
}

ll dis[N];
ll sgcd[N];

void DFS(int u, int from_e = -1) {
  for (auto [v, w, eid] : uG[u]) {
    if (scc[u] != scc[v]) continue;
    if (dis[v] == 0x3f3f3f3f3f3f3f3f)
      dis[v] = dis[u] + w, DFS(v, eid);
    else if ((eid ^ from_e) != 1)
      sgcd[scc[u]] = gcd(sgcd[scc[u]], dis[u] - dis[v] + w);
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  read(n, m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    read(u, v, w);
    G[u].emplace_back(v);
    uG[u].emplace_back(v, w, 2 * i); uG[v].emplace_back(u, -w, 2 * i + 1);
  }
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) tarjan(i);
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 1; i <= n; ++i)
    if (dis[i] == 0x3f3f3f3f3f3f3f3f) dis[i] = 0, DFS(i);

  int qc;
  read(qc);
  while (qc--) {
    int u, r, M;
    read(u, r, M);
    int d = gcd(M, sgcd[scc[u]]);
    puts(r % d == 0 ? "YES" : "NO");
  }
  return 0;
}