#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Abs(const T &a) {return a < 0 ? -a : a;}

typedef long long ll;

const int N = 2e5 + 5;

int n, d, a[N], fa[N], dep[N];
ll f[N];
std::vector<int> son[N], ds[N];

void dfs(int u)
{
  ds[dep[u]].push_back(u);
  if (dep[u] > d) d = dep[u];
  for (int i = 0; i < son[u].size(); i++)
  	dep[son[u][i]] = dep[u] + 1, dfs(son[u][i]);
}

void work() {
  int u; read(n); d = 0;
  for (int i = 1; i <= n; i++) son[i].clear(), ds[i].clear();
  for (int i = 2; i <= n; i++) read(u), son[fa[i] = u].push_back(i);
  for (int i = 2; i <= n; i++) read(a[i]);
  dfs(dep[1] = 1); f[1] = 0;
  for (int T = 2; T <= d; T++) {
  	int mina = 1e9 + 20050131, maxa = -1e9 - 20050131;
  	ll max1 = -1e18 - 20050131, max2 = -1e18 - 20050131;
  	for (int i = 0; i < ds[T].size(); i++)
  	  mina = Min(mina, a[ds[T][i]]), maxa = Max(maxa, a[ds[T][i]]);
  	for (int i = 0; i < ds[T].size(); i++) {
  	  f[ds[T][i]] = Max(a[ds[T][i]] - mina, maxa - a[ds[T][i]]) + f[fa[ds[T][i]]],
	  max1 = Max(max1, f[fa[ds[T][i]]] - a[ds[T][i]]);
	  max2 = Max(max2, f[fa[ds[T][i]]] + a[ds[T][i]]);
    }
    for (int i = 0; i < ds[T].size(); i++)
      f[ds[T][i]] = Max(f[ds[T][i]], Max(max1 + a[ds[T][i]], max2 - a[ds[T][i]]));
  }
  ll ans = -1e18 - 20050131;
  for (int i = 0; i < ds[d].size(); i++) ans = Max(ans, f[ds[d][i]]);
  printf("%lld\n", ans);
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}