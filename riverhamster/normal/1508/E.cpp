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
using ull = unsigned long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 300005;

int a[N], b[N];
vector<int> G[N];
int dfn[N], idfn[N], ipost[N], dep[N], dfc = 0, postc = 0;
mt19937_64 rng;
ull k[N];
bool vis[N];

void DFS1(int x) {
  dfn[x] = ++dfc;
  idfn[dfc] = x;
  sort(all(G[x]), [](int x, int y) { return a[x] < a[y]; });
  for (int v : G[x])
    dep[v] = dep[x] + 1, DFS1(v);
  ipost[++postc] = x;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  for (int i = 1; i <= n; ++i)
    read(a[i]);
  ull H = 0;
  for (int i = 1; i <= n; ++i) {
    k[i] = rng();
    while (~k[i] & 1) k[i] = rng();
  }
  for (int i = 1; i <= n; ++i)
    H ^= a[i] * k[i];
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v);
  }
  DFS1(1);
  int rt = a[1];
  int lim = max(rt - 2, 0);
  ll ans = 0;
  for (int i = 1; i <= lim; ++i) {
    b[ipost[i]] = i;
    vis[ipost[i]] = true;
    ans += dep[ipost[i]];
  }
  vector<int> V1;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) V1.push_back(i);
  sort(all(V1), [](int x, int y) { return dfn[x] < dfn[y]; });
  for (int i = 0, li = V1.size(); i < li; ++i)
    b[V1[i]] = lim + 1 + i;
  ull H1 = 0;
  for (int i = 1; i <= n; ++i)
    H1 ^= b[i] * k[i];
  auto swp = [&](int i, int j) {
    H1 ^= b[i] * k[i];
    H1 ^= b[j] * k[j];
    swap(b[i], b[j]);
    H1 ^= b[i] * k[i];
    H1 ^= b[j] * k[j];
  };
  b[0] = 1 << 30;
  for (int round = 0; round < 2; ++round) {
    int p = 0, q = 0;
    for (int u = 1; u <= n; ++u)
      for (int v : G[u])
        if (b[u] < b[v] && (b[u] < b[p] || (b[u] == b[p] && b[v] < b[q])))
          p = u, q = v;
    while (!G[p].empty()) {
      int v = 0;
      for (int t : G[p])
        if (b[p] < b[t] && b[t] < b[v]) v = t;
      if (!v) goto finish;
      swp(p, v);
      p = v;
      ++ans;
      if (H == H1) {
        puts("YES");
        printf("%lld\n", ans);
        for (int i = 1; i <= n; ++i)
          printf("%d ", dfn[i]);
        putchar('\n');
        return 0;
      }
    }
  }
finish:
  puts("NO");
  return 0;
}