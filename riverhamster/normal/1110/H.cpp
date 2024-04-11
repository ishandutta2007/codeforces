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

const int N = 805;
const int NC = 2 * N * 10;
const int LEN = 2005;

char L[N], R[N];
int lenL, lenR, n;

int c[NC][10], fa[NC];
int g[NC][N];
int nc = 0;

void construct_acam() {
  static int q[NC];
  int ql = 0, qr = 0;
  for (int v : c[0])
    if (v) q[++qr] = v;
  while (ql < qr) {
    int u = q[++ql];
    partial_sum(g[u], g[u] + lenR + 1, g[u]);
    if (fa[u])
      for (int j = 0; j <= lenR; ++j)
        g[u][j] += g[fa[u]][j];
    for (int i = 0; i < 10; ++i)
      (c[u][i] ? q[++qr] = c[u][i], fa[c[u][i]] : c[u][i]) = c[fa[u]][i];
  }
}

void add_prefix(const char *a, int len, int val) {
  int u = 0;
  for (const char *p = a; *p; ++p) {
    int v = *p - '0';
    for (int w = p == a; w < v; ++w) {
      if (!c[u][w]) c[u][w] = ++nc;
      g[c[u][w]][len - 1 - (p - a)] += val;
    }
    if (!c[u][v]) c[u][v] = ++nc;
    u = c[u][v];
  }
  g[u][0] += val;
}

int dp[LEN][NC];
int pre[LEN][NC];
bool pot[LEN][NC];

void DFS(int i, int u) {
  if (i == n) return;
  int L = min(n - 1 - i, lenR);
  for (int v = 0; v < 10; ++v)
    if (pot[i + 1][c[u][v]] && dp[i][u] + g[c[u][v]][L] == dp[i + 1][c[u][v]]) {
      printf("%d", v);
      DFS(i + 1, c[u][v]);
      break;
    }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  scanf("%s%s%d", L, R, &n);
  lenL = strlen(L); lenR = strlen(R);
  if (lenL < lenR) {
    for (int i = 1; i <= 9; ++i) {
      c[0][i] = ++nc;
      fill(g[nc] + lenL - 1, g[nc] + lenR - 1, 1);
    }
  }
  for (int i = lenL - 1; i >= 0; --i)
    if (L[i] == '0') L[i] = '9';
    else { --L[i]; break; }
  add_prefix(R, lenR, +1);
  if (lenL > 1 || *L != '0') add_prefix(L, lenL, -1);
  construct_acam();

  memset(dp, 0xaf, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    int L = min(lenR, n - 1 - i);
    for (int u = 0; u <= nc; ++u)
      for (int v : c[u])
        if (dp[i + 1][v] < dp[i][u] + g[v][L]) {
          dp[i + 1][v] = dp[i][u] + g[v][L];
          pre[i + 1][v] = u;
        }        
  }
  int ans = *max_element(dp[n], dp[n] + nc + 1);
  printf("%d\n", ans);
  for (int i = 0; i <= nc; ++i)
    if (dp[n][i] == ans) pot[n][i] = true;
  for (int i = n - 1; i >= 0; --i) {
    int L = min(lenR, n - 1 - i);
    for (int u = 0; u <= nc; ++u)
      for (int v : c[u])
        if (pot[i + 1][v] && dp[i][u] + g[v][L] == dp[i + 1][v]) {
          pot[i][u] = true;
          break;
        }
  }
  DFS(0, 0);
  return 0;
}