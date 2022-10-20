#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

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

const int N = 100005;

vector<int> G[N];
int c[N];

int l[N], r[N];

void fail() { puts("IMPOSSIBLE"); exit(0); }

void DFS(int x) {
  int col_v = 3 - c[x];
  for (int v : G[x]) {
    if (c[v]) {
      if (c[v] != col_v) fail();
      continue;
    }
    c[v] = col_v;
    DFS(v);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t, T, n, m, n1 = numeric_limits<int>::max(), n2 = numeric_limits<int>::min();
  read(t, T, n, m);
  for (int i = 1; i <= n; ++i) {
    read(l[i], r[i]);
    n1 = min(n1, r[i]);
    n2 = max(n2, l[i]);
  }
  if (n1 + n2 < t) n2 += t - n1 - n2;
  else if (n1 + n2 > T) n1 -= n1 + n2 - T;
  if (n1 < 0 || n2 < 0) fail();
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u, v);
    G[u].emplace_back(v); G[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    bool A = l[i] <= n1 && n1 <= r[i];
    bool B = l[i] <= n2 && n2 <= r[i];
    if (!A && !B) fail();
    else if (!(A && B)) {
      int col = A ? 1 : 2;
      if (c[i] && c[i] != col) fail();
      c[i] = col;
      DFS(i);
    }
  }
  for (int i = 1; i <= n; ++i)
    if (!c[i])
      c[i] = 1, DFS(i);
  puts("POSSIBLE");
  printf("%d %d\n", n1, n2);
  for (int i = 1; i <= n; ++i)
    printf("%d", c[i]);
  putchar('\n');
  return 0;
}