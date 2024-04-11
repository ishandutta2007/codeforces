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

const int N = 300005;

bool d[N][2];

struct edge {
  int v, dir, nt;
} E[N * 4];
int hd[N * 2];
int ec = 0;
char dir[N * 2];
bool vis[N * 2];

void link(int x, int y) {
  E[++ec] = {y, 1, hd[x]}; hd[x] = ec;
  E[++ec] = {x, 2, hd[y]}; hd[y] = ec;
}

void DFS(int u) {
  for (int &i = hd[u]; i; i = E[i].nt) {
    if (vis[(i + 1) / 2]) continue;
    vis[(i + 1) / 2] = true;
    dir[(i + 1) / 2] = E[i].dir + '0';
    DFS(E[i].v);
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  read(n, m);
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    read(u, v, w);
    --w;
    d[u][w] ^= 1; d[v][w] ^= 1;
    link(w * n + u, w * n + v);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += d[i][0];
    if (d[i][0] && d[i][1]) link(i, i + n);
    else if (d[i][0]) link(2 * n + 1, i);
    else if (d[i][1]) link(2 * n + 1, i + n);
  }
  for (int i = 1; i <= 2 * n + 1; ++i)
   DFS(i);
  printf("%d\n", ans);
  for (int i = 1; i <= m; ++i)
    putchar(dir[i]);
  putchar('\n');
  return 0;
}