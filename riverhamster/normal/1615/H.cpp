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

const int N = 1005;
const int NC = 1005, EC = 4005;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

struct edge {
  int v, nt;
  ll f;
} e[EC * 2];
int h[NC], cur[NC], hd[NC], ec = 0;
int s, t;
bool iss[NC];

void clear() {
  memset(hd, -1, sizeof(hd));
  ec = 0;
}

void link(int u, int v, ll f) {
  e[ec] = {v, hd[u], f}; hd[u] = ec++;
  e[ec] = {u, hd[v], 0}; hd[v] = ec++;
}

bool BFS() {
  static int q[NC];
  int ql = 0, qr = 0;
  memset(h, -1, sizeof(h));
  q[++qr] = s; h[s] = 0;
  while (ql < qr) {
    int u = q[++ql];
    for (int i = hd[u]; ~i; i = e[i].nt)
      if (h[e[i].v] == -1 && e[i].f)
        h[e[i].v] = h[u] + 1, q[++qr] = e[i].v;
  }
  return ~h[t];
}

ll DFS(int u, ll fl) {
  if (u == t) return fl;
  ll res = 0;
  for (int &i = cur[u]; ~i; i = e[i].nt) {
    if (h[e[i].v] == h[u] + 1 && e[i].f) {
      ll aug = min(fl, e[i].f);
      aug = min(aug, DFS(e[i].v, aug));
      e[i].f -= aug; e[i ^ 1].f += aug;
      res += aug; fl -= aug;
      if (!fl) break;
    }
  }
  if (!res) h[u] = -1;
  return res;
}

ll maxflow() {
  ll ans = 0;
  while (BFS()) {
    memcpy(cur, hd, sizeof(cur));
    ans += DFS(s, 0x3f3f3f3f3f3f3f3fLL);
    if (ans >= INF) return ans;
  }
  return ans;
}
void cons(int u) {
  iss[u] = true;
  for (int i = hd[u]; ~i; i = e[i].nt)
    if (e[i].f && !iss[e[i].v])
      cons(e[i].v);
}

int a[N];
int u[N], v[N];
ll l[N], r[N], mid[N];
int n, m;

bool finished() {
  for (int i = 1; i <= n; ++i)
    if (l[i] != r[i]) return false;
  return true;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  clear();
  read(n, m);
  for (int i = 1; i <= n; ++i)
    read(a[i]);
  for (int i = 1; i <= m; ++i)
    read(u[i], v[i]);
  fill(l + 1, l + 1 + n, (ll)-1e15);
  fill(r + 1, r + 1 + n, (ll)1e15);
  while (!finished()) {
    clear();
    for (int i = 1; i <= n; ++i)
      mid[i] = (l[i] + r[i]) >> 1;
    s = n + 1; t = n + 2;
    for (int i = 1; i <= n; ++i)
      link(i, t, llabs(mid[i] - a[i]));
    for (int i = 1; i <= n; ++i)
      link(s, i, llabs(mid[i] + (l[i] != r[i]) - a[i]));
    for (int i = 1; i <= m; ++i) {
      assert(r[u[i]] <= r[v[i]]);
      if (l[u[i]] == l[v[i]] && r[u[i]] == r[v[i]])
        link(v[i], u[i], INF);
    }
    maxflow();
    memset(iss, 0, sizeof(iss));
    cons(s);
    for (int i = 1; i <= n; ++i)
      if (iss[i]) r[i] = mid[i];
      else if (l[i] != r[i]) l[i] = mid[i] + 1;
  }
  for (int i = 1; i <= n; ++i)
    printf("%lld%c", l[i], " \n"[i == n]);
  return 0;
}