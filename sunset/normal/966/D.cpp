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

const int N = 300005;
const int inf = 0x3f3f3f3f;

int n, m, top, q[N], dis[N], pre[N];
vector <int> adj[N];
pii a[N];

inline void BFS(int s, int ban) {
  q[top = 1] = s, dis[s] = 0;
  for (int i = 1; i <= top; ++i) {
    int x = q[i];
    for (auto y : adj[x]) {
      if (y != ban && CheckMin(dis[y], dis[x] + 1)) {
        pre[q[++top] = y] = x;
      }
    }
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 1, x, y; i <= m; ++i) {
    Read(x), Read(y);
    adj[x].pb(y), adj[y].pb(x);
  }
  for (int i = 1; i <= n; ++i) {
    dis[i] = inf;
  }
  BFS(1, -1);
  if (dis[n] <= 4) {    
    printf("%d\n", dis[n]);
    int top = 0, seq[5];
    for (int i = n; i; seq[++top] = i, i = pre[i]);
    for (int i = top; i; --i) {
      printf("%d%c", seq[i], i == 1 ? '\n' : ' ');
    }
    return 0;
  }
  int p = -1;
  for (int i = 1; i <= n; ++i) {
    if (dis[i] == 2) {
      p = i;
    }
  }
  if (~p) {
    puts("4");
    printf("1 %d %d 1 %d\n", pre[p], p, n);
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    dis[i] = inf;
  }
  int top = 0;
  for (auto i : adj[1]) {
    a[++top] = mp(adj[i].size(), i);
  }
  sort(a + 1, a + top + 1);
  for (int i = 1; i <= top; ++i) {
    int x = a[i].Y;
    if (dis[x] == inf) {
      BFS(x, 1);
    } else if (dis[x] == 2) {
      puts("5");
      printf("1 %d %d %d %d %d\n", pre[pre[x]], pre[x], x, pre[pre[x]], n);
      return 0;
    }
  }
  puts("-1");
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}