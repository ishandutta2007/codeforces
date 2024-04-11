#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while (isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 2005;

int M;

vector<int> G[N];

void reduceR(int &x) { x += M & (x >> 31); }
int reduceN(int x) { return x + (M & (x >> 31)); }
int add(int x, int y) { return reduceN(x + y - M); }
int sub(int x, int y) { return reduceN(x - y); }
void inc(int &x, int y) { reduceR(x += y - M); }
void dec(int &x, int y) { reduceR(x -= y); }
int power(int x, int y, int p = 1) {
  for (; y; y >>= 1, x = (ll)x * x % M)
    if (y & 1) p = (ll)p * x % M;
  return p;
}
int inv(int x) { return power(x, M - 2); }

int n;
int C[N][N];
int dp[N][N], ps[N][N];
int sum[N], cur[N];

void DFS(int u, int fa = 0) {
  if (fa) G[u].erase(find(all(G[u]), fa));
  for (int v : G[u]) {
    DFS(v, u);
    for (int i = 1; i <= n; ++i)
      ps[v][i] = add(ps[v][i - 1], dp[v][i]);
  }
  for (int i = 1; i <= n; ++i) {
    int prod = 1;
    for (int v : G[u]) {
      dp[u][i] = (dp[u][i] + (ll)sum[v] * dp[v][i]) % M;
      prod = (ll)prod * ps[v][i] % M;
    }
    if (u == 1) dp[u][i] = prod;
    else inc(dp[u][i], prod);
    prod = 1;
    for (int v : G[u]) {
      cur[v] = prod;
      prod = (ll)prod * ps[v][i] % M;
    }
    prod = 1;
    for (auto v = G[u].rbegin(); v != G[u].rend(); ++v) {
      cur[*v] = (ll)cur[*v] * prod % M;
      prod = (ll)prod * ps[*v][i] % M;
    }
    for (int v : G[u])
      inc(sum[v], cur[v]);
  }
}

void single() {
  read(n, M);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v); G[v].push_back(u);
  }
  DFS(1);
  for (int i = 0; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
  }
  printf("%d ", dp[1][1]);
  for (int i = 2; i < n; ++i) {
    for (int j = 1; j < i; ++j)
      dp[1][i] = (dp[1][i] - (ll)dp[1][j] * C[i][j]) % M;
    dp[1][i] = (dp[1][i] + M) % M;
    printf("%d ", dp[1][i]);
  }
  puts("");
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T = 1;
  // read(T);
  while (T--) single();
  return 0;
}