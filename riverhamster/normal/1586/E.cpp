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

vector<int> G[N];
vector<vector<int>> ans;
int fa[N], dfn[N], dfc = 0;
int d[N];
bool x[N];

void DFS(int u) {
  dfn[++dfc] = u;
  for (int v : G[u]) {
    if (d[v]) continue;
    d[v] = d[u] + 1;
    fa[v] = u;
    DFS(v);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  read(n, m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v); G[v].push_back(u);
  }
  d[1] = 1;
  DFS(1);
  int q;
  read(q);
  while (q--) {
    int u, v;
    read(u, v);
    vector<int> du, dv;
    while (u != v) {
      if (d[u] > d[v]) {
        du.push_back(u);
        x[u] ^= 1;
        u = fa[u];
      }
      else {
        dv.push_back(v);
        x[v] ^= 1;
        v = fa[v];
      }
    }
    ans.push_back(du);
    ans.back().push_back(u);
    ans.back().insert(ans.back().end(), dv.rbegin(), dv.rend());
  }
  if (find(x + 1, x + 1 + n, true) == x + 1 + n) {
    puts("YES");
    for (const auto &p : ans) {
      printf("%d\n", (int)p.size());
      for (int x : p)
        printf("%d ", x);
      putchar('\n');
    }
  }
  else {
    puts("NO");
    int sum = 0;
    for (int i = n; i >= 1; --i) {
      int u = dfn[i];
      int cnt = 0;
      for (int v : G[u])
        cnt += x[v] && (d[v] == d[u] + 1);
      if (x[u]) --cnt;
      sum += (cnt + 1) / 2;
    }
    printf("%d\n", sum);
  }
  return 0;
}