#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <random>
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

const int ST = 11 * 11 * 11 + 5;
using ull = unsigned long long;
const ull B = 8471584165667979465;
const ull B1 = 7075933990017200075;
const ull I = 5863869706745844183;
const int SIG = 10;

int t[ST][10], nt[ST][10], rt[11][10];
int init[10];
ull h[ST], h1[ST];
int mp[ST];
bool vis[ST];
int dp[100005][11];
char s[100005];

int id(int x, int y, int z) { return x * 121 + y * 11 + z; }

int DFAminimize(int n) {
  fill(h, h + n, I);
  int last = -1;
  while (true) {
    memset(h1, 0, sizeof(h1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < SIG; ++j)
        h1[i] = h1[i] * B + (t[i][j] == -1 ? 0 : h[t[i][j]]);
    }
    ull t = 0;
    for (int i = 0; i < n; ++i)
      t = t * B1 + h1[i];
    memcpy(h, h1, sizeof(h));
    sort(h1, h1 + n);
    int cnt = 1;
    for (int i = 1; i < n; ++i)
      cnt += h[i] != h[i - 1];
    if (cnt == last) break;
    last = cnt;
  }
  int nc = unique(h1, h1 + n) - h1;
  for (int i = 0; i < n; ++i)
    mp[i] = lower_bound(h1, h1 + nc, h[i]) - h1;
  memset(nt, -1, sizeof(nt));
  for (int i = 0; i < n; ++i) {
    if (vis[mp[i]]) continue;
    vis[mp[i]] = true;
    for (int j = 0; j < SIG; ++j)
      if (~t[i][j]) nt[mp[i]][j] = mp[t[i][j]];
  }
  return nc;
}

void DFS(int u) {
  if (vis[u]) return;
  vis[u] = true;
  for (int v : nt[u])
    if (~v) DFS(v);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  memset(t, -1, sizeof(t));
  for (int r = 0; r < 11; ++r)
    for (int c0 = 0; c0 < 11; ++c0)
      for (int c1 = 0; c1 < 11; ++c1) {
        for (int v = 0; v < r; ++v) {
          int _c0 = (v + c0 * r - c0 * (c0 + 1) / 2 + 121) % 11;
          int _c1 = (r - v - 1 + c1 * r + c1 * (c1 + 1) / 2) % 11;
          int _r = (r + c1 + _c0 + 1) % 11;
          t[id(r, c0, c1)][v] = id(_r, _c0, _c1);
        }
      }
  int nc = DFAminimize(11 * 11 * 11);
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i < 10; ++i)
    DFS(mp[id(i, i - 1, 9 - i)]);
  vector<int> states;
  for (int i = 0; i < nc; ++i)
    if (vis[i]) states.push_back(i);

  memset(rt, -1, sizeof(rt));
  for (int i = 0, li = states.size(); i < li; ++i) {
    int s = states[i];
    for (int j = 0; j < SIG; ++j)
      if (~nt[s][j]) rt[i][j] = lower_bound(all(states), nt[s][j]) - states.begin();
  }
  for (int i = 1; i < 10; ++i) {
    init[i] = lower_bound(all(states), mp[id(i, i - 1, 9 - i)]) - states.begin();
  }

  scanf("%s", s);
  int n = 0;
  ll ans = 0;
  for (; s[n]; ++n) {
    int v = s[n] - '0';
    for (int i = 0; i < 11; ++i)
      if (~rt[i][v]) dp[n + 1][rt[i][v]] += dp[n][i];
    if (v) ++dp[n + 1][init[v]];
    ans += accumulate(dp[n + 1], dp[n + 1] + 11, 0);
  }
  printf("%lld\n", ans);
  return 0;
}