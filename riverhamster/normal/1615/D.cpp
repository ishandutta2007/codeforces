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

const int N = 200005;

int u[N], v[N], w[N];
vector<pair<int, int>> G[N];
bool contra;
int col[N];

void DFS(int u) {
  for (auto [v, w] : G[u]) {
    if (col[v]) {
      int ev = w ? 3 - col[u] : col[u];
      if (col[v] != ev) {
        contra = true;
        return;
      }
      continue;
    }
    col[v] = w ? 3 - col[u] : col[u];
    DFS(v);
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n, m;
    read(n, m);
    for (int i = 1; i <= n; ++i)
      G[i].clear();
    fill(col + 1, col + 1 + n, 0);
    for (int i = 1; i < n; ++i) {
      read(u[i], v[i], w[i]);
      if (w[i] >= 0) {
        G[u[i]].emplace_back(v[i], __builtin_parity(w[i]));
        G[v[i]].emplace_back(u[i], __builtin_parity(w[i]));
      }
    }
    for (int i = 1; i <= m; ++i) {
      int u, v, w;
      read(u, v, w);
      G[u].emplace_back(v, w);
      G[v].emplace_back(u, w);
    }
    contra = false;
    for (int i = 1; i <= n; ++i)
      if (!col[i]) col[i] = 1, DFS(i);
    if (contra) puts("NO");
    else {
      puts("YES");
      for (int i = 1; i < n; ++i) {
        printf("%d %d ", u[i], v[i]);
        if (w[i] != -1) printf("%d\n", w[i]);
        else printf("%d\n", col[u[i]] != col[v[i]]);
      }
    }
  }
  return 0;
}