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

const int N = 200005;

bool drw, all[N], vis[N];
int n, m, top, sta[N];
vector <int> adj[N];

inline void DFS(int x) {
  vis[x] = all[x] = true, sta[++top] = x;
  if (adj[x].empty() && (x & 1)) {
    puts("Win");
    for (int i = 1; i <= top; ++i) {
      printf("%d%c", sta[i] >> 1, i == top ? '\n' : ' ');
    }
    exit(0);
  }
  for (auto y : adj[x]) {
    if (vis[y]) {
      drw = true;
    } else if (!all[y]) {
      DFS(y);
    }
  }
  vis[x] = false, --top;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 1, x, j; i <= n; ++i) {
    for (Read(x); x; --x) {
      Read(j), adj[i << 1].pb(j << 1 | 1), adj[i << 1 | 1].pb(j << 1);
    }
  }
  Read(m), DFS(m << 1), puts(drw ? "Draw" : "Lose");
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}