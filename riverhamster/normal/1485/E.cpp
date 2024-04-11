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

template<class T> void read(T &x){
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 200005;
vector<int> dep[N], G[N];
int mxdep = 0, fa[N], a[N];
ll f[N];

void dfs(int x, int d) {
  mxdep = max(mxdep, d);
  dep[d].push_back(x);
  for (int v : G[x])
    if (v != fa[x]) fa[v] = x, dfs(v, d + 1);
}

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
    for (int i = 1; i <= n; ++i) dep[i].clear(), G[i].clear();
    fill(f + 1, f + 1 + n, 0);
    mxdep = 0;
    for (int i = 2; i <= n; ++i) {
      int v; read(v);
      G[i].push_back(v); G[v].push_back(i);
    }
    for (int i = 2; i <= n; ++i) read(a[i]);
    dfs(1, 0);
    for (int i = mxdep; i > 0; --i) {
      sort(dep[i].begin(), dep[i].end(), [](int x, int y) { return a[x] < a[y]; });
      ll mx = -1e18, mxv = -1e18;
      for (int u : dep[i]) {
        f[fa[u]] = max(f[fa[u]], f[u]);
        f[fa[u]] = max(f[fa[u]], a[u] + mx);
        f[fa[u]] = max(f[fa[u]], a[u] + mxv + f[u]);
        mx = max(mx, f[u] - a[u]); mxv = max(mxv, (ll)-a[u]);
      }
      reverse(dep[i].begin(), dep[i].end());
      mx = mxv = -1e18;
      for (int u : dep[i]) {
        f[fa[u]] = max(f[fa[u]], mx - a[u]);
        f[fa[u]] = max(f[fa[u]], mxv - a[u] + f[u]);
        mx = max(mx, f[u] + a[u]);
        mxv = max(mxv, (ll)a[u]);
      }
    }
    printf("%lld\n", f[1]);
  }
  return 0;
}