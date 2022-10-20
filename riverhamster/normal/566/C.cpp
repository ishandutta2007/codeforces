#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <cmath>
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

using fp = long double;

const int N = 200005;

vector<pair<int, int>> G[N];
int a[N], sz[N], son[N];
bool del[N];

void getsize(int x, int fa = 0) {
  sz[x] = 1; son[x] = 0;
  for (const auto &[v, w] : G[x]) {
    if (v == fa || del[v]) continue;
    getsize(v, x);
    sz[x] += sz[v];
    if (sz[v] > sz[son[x]]) son[x] = v;
  }
}
int getg(int x) {
  int g = x;
  while (sz[son[g]] * 2 > sz[x]) g = son[g];
  return g;
}

int pos;
fp val = 1e100;

fp calc(int x, int fa = 0, int dis = 0) {
  fp res = a[x] * pow(dis, 1.5);
  for (const auto &[v, w] : G[x])
    if (v != fa)
      res += calc(v, x, dis + w);
  return res;
}

fp deriv(int x, int fa = 0, int dis = 0) {
  fp res = a[x] * sqrt(dis); // * 1.5
  for (const auto &[v, w] : G[x])
    if (v != fa)
      res += deriv(v, x, dis + w);
  return res;
}

void solve(int x) {
  getsize(x);
  int g = getg(x);
  fp v = calc(g);
  if (v < val)
    val = v, pos = g;
  del[g] = true;
  fp dsum = 0, mxder = 0;
  int mxv = 0;
  for (const auto &[v, w] : G[g]) {
    if (del[v]) continue;
    fp d = deriv(v, g, w);
    dsum += d;
    if (d > mxder)
      mxder = d, mxv = v;
  }
  if (mxv && mxder * 2 > dsum)
    solve(mxv);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    read(u, v, w);
    G[u].emplace_back(v, w); G[v].emplace_back(u, w);
  }
  solve(1);
  printf("%d %.15Lf\n", pos, val);
  return 0;
}