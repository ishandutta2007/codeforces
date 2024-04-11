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
const int M = 1048580;

int n, a[N], siz[N], cnt[M];
vector <int> adj[N];
LL ans[N], tag[N];
bool vis[N];
char s[N];

inline void FindRoot(int x, int p, int Siz, int &c) {
  bool flg = true;
  siz[x] = 1;
  for (auto y : adj[x]) {
    if (y != p && !vis[y]) {
      FindRoot(y, x, Siz, c), siz[x] += siz[y], flg &= siz[y] <= Siz >> 1;
    }
  }
  flg &= siz[x] >= Siz >> 1;
  if (flg) {
    c = x;
  }
}

inline void FindSize(int x, int p) {
  siz[x] = 1;
  for (auto y : adj[x]) {
    if (y != p && !vis[y]) {
      FindSize(y, x), siz[x] += siz[y];
    }
  }
}

inline void Query(int x, int p, int s) {
  s ^= 1 << a[x];
  tag[x] = cnt[s];
  for (int i = 0; i < 20; ++i) {
    tag[x] += cnt[s ^ 1 << i];
  }
  for (auto y : adj[x]) {
    if (y != p && !vis[y]) {
      Query(y, x, s);
    }
  }
}

inline void Pushup(int x, int p) {
  for (auto y : adj[x]) {
    if (y != p && !vis[y]) {
      Pushup(y, x), tag[x] += tag[y];
    }
  }
  ans[x] += tag[x];
}

inline void Modify(int x, int p, int s, int f) {
  s ^= 1 << a[x];
  cnt[s] += f;
  for (auto y : adj[x]) {
    if (y != p && !vis[y]) {
      Modify(y, x, s, f);
    }
  }
}

inline void Solve(int x, int Siz) {
  int c;
  FindRoot(x, 0, Siz, c);
  vis[x = c] = true;
  FindSize(x, 0);
  ++ans[x];
  cnt[1 << a[x]] = 1;
  for (auto y : adj[x]) {
    if (!vis[y]) {
      Query(y, x, 0), Pushup(y, x), ans[x] += tag[y], Modify(y, x, 1 << a[x], 1);
    }
  }
  for (auto y : adj[x]) {
    if (!vis[y]) {
      Modify(y, x, 1 << a[x], -1);
    }
  }
  cnt[1 << a[x]] = 0;
  reverse(adj[x].begin(), adj[x].end());
  for (auto y : adj[x]) {
    if (!vis[y]) {
      Query(y, x, 0), Pushup(y, x), Modify(y, x, 1 << a[x], 1);
    }
  }
  for (auto y : adj[x]) {
    if (!vis[y]) {
      Modify(y, x, 1 << a[x], -1);
    }
  }
  for (auto y : adj[x]) {
    if (!vis[y]) {
      Solve(y, siz[y]);
    }
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 1, x, y; i < n; ++i) {
    Read(x), Read(y);
    adj[x].pb(y), adj[y].pb(x);
  }
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = s[i] - 'a';
  }
  Solve(1, n);
  for (int i = 1; i <= n; ++i) {
    printf("%lld%c", ans[i], i == n ? '\n' : ' ');
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}