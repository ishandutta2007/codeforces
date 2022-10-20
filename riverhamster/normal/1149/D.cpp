#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <array>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
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

#define REP(i, r) for (int i = 0; i < int(r); ++i)

const int N = 71;

int n, m;
unsigned a, b;
vector<int> G[N];
vector<array<int, 3>> inp;
int id[N], oid[N], sz[N];
unsigned dp[1 << 17][N], in[N][N], ans[N];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, m, a, b);
  memset(in, 0x7f, sizeof(in));
  REP(i, m) {
    int u, v; unsigned w;
    read(u, v, w); --u; --v;
    inp.push_back({u, v, (int)w}); inp.push_back({v, u, (int)w});
    if (w == b) { G[u].push_back(v); G[v].push_back(u); }
    else in[u][v] = in[v][u] = a;
  }
  REP(i, n) in[i][i] = 0;
  REP(k, n) REP(i, n) REP(j, n) in[i][j] = min(in[i][j], in[i][k] + in[k][j]);
  REP(i, n) {
    int id = i;
    REP(j, i) if (in[i][j] < 0x7f7f7f7f) { id = j; break; }
    ::id[i] = oid[i] = id; ++sz[id];
  }
  int idc = 0;
  REP(i, n) {
    if (id[i] == i) {
      if (sz[i] < 4) id[i] = -1;
      else id[i] = idc++;
    }
    else id[i] = id[id[i]];
  }

  memset(dp, 0x7f, sizeof(int[1 << idc][N]));
  dp[0][0] = 0;
  memset(ans, 0x7f, sizeof(ans));
  REP(s, 1 << idc) {
    REP(i, n - 1)
      for (auto e : inp)
        if ((e[2] == (int)a && oid[e[0]] == oid[e[1]]) || (id[e[0]] == -1 && oid[e[0]] != oid[e[1]] && (id[e[1]] == -1 || ((~s >> id[e[1]]) & 1))))
          dp[s][e[1]] = min(dp[s][e[1]], dp[s][e[0]] + e[2]);
    REP(i, n) {
      ans[i] = min(ans[i], dp[s][i]);
      if (id[i] == -1) continue;
      for (int v : G[i])
        if (id[i] != id[v] && (id[v] == -1 || ((~s >> id[v]) & 1)))
          dp[s | (1 << id[i])][v] = min(dp[s | (1 << id[i])][v], dp[s][i] + b);
    }
  }
  
  REP(i, n) printf("%d%c", ans[i], " \n"[i == n - 1]);
  return 0;
}