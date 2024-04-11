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

const int N = 100005;

vector<int> G[N], DAG[N];
vector<int> scc[N];
int q[N], ql = 0, qr = 0;
int low[N], dfn[N], scnt = 0, dfc = 0;
int stk[N], top = 0, id[N];
bool instk[N];
int ind[N];

void DFS(int x) {
  low[x] = dfn[x] = ++dfc;
  stk[++top] = x; instk[x] = true;
  for (int v : G[x])
    if (!dfn[v]) DFS(v), low[x] = min(low[x], low[v]);
    else if (instk[v]) low[x] = min(low[x], dfn[v]);
  if (low[x] == dfn[x]) {
    ++scnt;
    int tp = 0;
    do {
      tp = stk[top--];
      instk[tp] = false;
      id[tp] = scnt;
      scc[scnt].push_back(tp);
    } while (tp != x);
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  read(n, m);
  vector<pair<int, int>> e;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u, v);
    e.emplace_back(u, v);
    G[u].push_back(v);
  }
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) DFS(i);
  for (auto p : e) {
    if (id[p.first] == id[p.second]) continue;
    DAG[id[p.first]].push_back(id[p.second]);
    ++ind[id[p.second]];
  }
  for (int i = 1; i <= scnt; ++i)
    if (!ind[i]) q[++qr] = i;
  assert(qr);
  while (ql + 1 < qr) {
    int &u = q[ql + 1], &v = q[ql + 2];
    printf("? %d %d\n", scc[u].back(), scc[v].back());
    fflush(stdout);
    int dir;
    read(dir);
    if (dir == 1) swap(u, v);
    scc[u].pop_back();
    if (scc[u].empty()) {
      for (int w : DAG[u]) {
        --ind[w];
        if (!ind[w]) q[++qr] = w;
      }
      ++ql;
    }
  }
  printf("! %d\n", scc[q[qr]].back());
  return 0;
}