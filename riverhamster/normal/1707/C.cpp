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
  do x = x * 10 + (ch - '0'); while (isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 100005;
const int logN = 19;

int n, m;
int fa[N];
bool vis[N];
vector<int> G[N];
bool del[N];

int find(int x) { return !fa[x] ? x : fa[x] = find(fa[x]); }

int dep[N], F[N], lb[N], rb[N], anc[N][logN], dfc = 0;

void DFS(int u) {
  lb[u] = ++dfc;
  anc[u][0] = F[u];
  for (int i = 1; i <= 17; ++i)
    anc[u][i] = anc[anc[u][i - 1]][i - 1];
  for (int v : G[u])
    if (!dep[v]) F[v] = u, dep[v] = dep[u] + 1, DFS(v);
  rb[u] = dfc;
}

int tr[N];
void ins(int p, int v) {
  for (; p < N; p += p & -p)
    tr[p] += v;
}
int query(int p) {
  int s = 0;
  for (; p; p &= p - 1)
    s += tr[p];
  return s;
}

void single() {
  read(n, m);
  vector<pair<int, int>> nt;
  for (int i = 0; i < m; ++i) {
    int u, v, tu, tv;
    read(u, v), tu = u, tv = v;
    u = find(u), v = find(v);
    if (u == v) nt.emplace_back(tu, tv);
    else G[tu].push_back(tv), G[tv].push_back(tu), fa[u] = v;
  }
  dep[1] = 1, DFS(1);
  for (auto p : nt) {
    int u = p.first, v = p.second;
    if (lb[u] > lb[v]) swap(u, v);
    auto Ins = [](int l, int r) { if (l <= r) ins(l, +1), ins(r + 1, -1); };
    if (lb[u] <= lb[v] && lb[v] <= rb[u]) {
      int d = dep[v] - dep[u] - 1, fv = v;
      for (int i = 0; d; d >>= 1, ++i)
        if (d & 1) fv = anc[fv][i];
      Ins(lb[fv], lb[v] - 1);
      Ins(rb[v] + 1, rb[fv]);
    }
    else {
      Ins(1, lb[u] - 1);
      Ins(rb[u] + 1, lb[v] - 1);
      Ins(rb[v] + 1, n);
    }
  }
  for (int i = 1; i <= n; ++i)
    putchar(query(lb[i]) ? '0' : '1');
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T = 1;
  // read(T);
  while (T--) single();
  return 0;
}