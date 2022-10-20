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
int l[N], r[N], dep[N], dfc = 0;
int s[N], top[N];
vector<pair<int, int>> paths;
int ans = 0;

void DFS1(int u) {
  l[u] = ++dfc;
  for (int v : G[u])
    dep[v] = dep[u] + 1, DFS1(v);
  r[u] = dfc;
}

void DFS2(int u) {
  for (int v : G[u]) {
    DFS2(v);
    s[u] += s[v];
  }
  bool add = false;
  int upd = top[u];
  for (int v : G[u]) {
    if (s[v] && s[v] == s[u]) {
      if (top[v] == dep[u]) add = true;
      else upd = max(upd, top[v]);
    }
    else if (!s[v] && !s[u]) {
      if (top[v] == dep[u]) add = true;
      else upd = max(upd, top[v]);
    }
  }
  if (add) ++s[u];
  else top[u] = upd;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  read(n, m);
  for (int i = 2; i <= n; ++i) {
    int fa;
    read(fa);
    G[fa].push_back(i);
  }
  dep[1] = 1;
  DFS1(1);

  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u, v);
    if (dep[u] > dep[v]) swap(u, v);
    if (l[u] <= l[v] && l[v] <= r[u]) {
      if (dep[u] + 1 == dep[v]) {
        puts("-1");
        return 0;
      }
      top[v] = max(top[v], dep[u] + 1);
    }
    else
      paths.emplace_back(u, v);
  }
  DFS2(1);
  ans = s[1];

  for (auto [u, v] : paths)
    if (s[u] + s[v] == s[1]) {
      ++ans;
      break;
    }
  printf("%d\n", ans);
  return 0;
}