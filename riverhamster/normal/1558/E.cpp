#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <unistd.h>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

#define DEBUG
#ifdef DEBUG
#define DBG(f...) printf(f)
#else
#define DBG(f...) void()
#endif

const int N = 1005;

int a[N], b[N];
vector<int> G[N];

ll P;
int dep[N], from[N];
bool S[N];
int n, m, sc;

void add(int x) {
  if (!S[x]) {
    sc += !S[x];
    P += b[x];
    S[x] = true;
  }
}

bool DFS(int x, ll curP, int fa = 0) {
  dep[x] = dep[fa] + 1;
  if (!S[x]) curP += b[x];
  for (int v : G[x]) {
    if (v == fa) continue;
    if ((dep[v] && dep[v] < dep[x]) || (S[v] && !S[x])) {
      add(x);
      return true;
    }
    if (S[v]) continue;
    if (curP > a[v] && from[v]) {
      add(x);
      for (int t = v; !S[t]; t = from[t])
        add(t);
      return true;
    }
    from[v] = x;
    if (curP > a[v] && DFS(v, curP, x)) {
      add(x);
      return true;
    }
  }
  return false;
}

bool check(int _P) {
  P = _P;
  memset(S, 0, sizeof(S));
  sc = 1; S[1] = true;
  while (sc != n) {
    memset(dep, 0, sizeof(dep));
    memset(from, 0, sizeof(from));
    bool flag = false;
    for (int i = 1; i <= n; ++i)
      if (!dep[i] && S[i])
        if (DFS(i, P)) {
          flag = true;
          break;
        }
    if (!flag) return false;
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  setbuf(stdout, nullptr);
#endif
  int T;
  read(T);
  while (T--) {
    read(n, m);
    for (int i = 1; i <= n; ++i)
      G[i].clear();
    for (int i = 2; i <= n; ++i)
      read(a[i]);
    for (int i = 2; i <= n; ++i)
      read(b[i]);
    for (int i = 1; i <= m; ++i) {
      int u, v;
      read(u, v);
      G[u].push_back(v); G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
      sort(all(G[i]));
    int ans = (1 << 30) - 1;
    for (int i = 29; i >= 0; --i)
      if (check(ans ^ (1 << i))) ans ^= (1 << i);
    if (ans > 1000000001) puts("-1");
    else printf("%d\n", ans);
  }
  return 0;
}