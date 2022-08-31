#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}

const int N = 100005;

int n, m, h, ans, tim, tot, top, a[N], dfn[N], low[N], scc[N], sta[N];
vector <int> adj[N], all[N];
bool vis[N];

inline int DFS(int x) {
  dfn[x] = low[x] = ++tim, sta[++top] = x;
  for (auto y : adj[x]) {
    if (!dfn[y]) {
      DFS(y), CheckMin(low[x], low[y]);
    } else if (!scc[y]) {
      CheckMin(low[x], dfn[y]);
    }
  }
  if (low[x] == dfn[x]) {
    ++tot;
    for (int t = 0; t != x; t = sta[top--], all[tot].pb(t), scc[t] = tot);
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m), Read(h);
  for (int i = 1; i <= n; ++i) {
    Read(a[i]);
  }
  for (int i = 1, x, y; i <= m; ++i) {
    Read(x), Read(y);
    if ((a[x] + 1) % h == a[y]) {
      adj[x].pb(y);
    }
    if ((a[y] + 1) % h == a[x]) {
      adj[y].pb(x);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!dfn[i]) {
      DFS(i);
    }
  }
  for (int x = 1; x <= n; ++x) {
    for (auto y : adj[x]) {
      if (scc[x] != scc[y]) {
        vis[scc[x]] = true;
      }
    }
  }
  for (int i = 1; i <= tot; ++i) {
    if (!vis[i]) {
      if (!ans || all[ans].size() > all[i].size()) {
        ans = i;
      }
    }
  }
  printf("%d\n", all[ans].size());
  for (int i = 0; i < all[ans].size(); ++i) {
    printf("%d%c", all[ans][i], i == all[ans].size() - 1 ? '\n' : ' ');
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}