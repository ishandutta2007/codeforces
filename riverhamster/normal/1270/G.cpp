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

const int N = 1000005;

int a[N];
int vis[N];
int stk[N], top = 0;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n;
    read(n);
    fill(vis + 1, vis + 1 + n, 0);
    for (int i = 1; i <= n; ++i) {
      read(a[i]);
      a[i] = i - a[i];
    }
    int u = 1;
    top = 0;
    while (!vis[u]) {
      stk[++top] = u;
      vis[u] = top;
      u = a[u];
    }
    printf("%d\n", top - vis[u] + 1);
    for (int i = vis[u]; i <= top; ++i)
      printf("%d ", stk[i]);
    puts("");
  }
  return 0;
}