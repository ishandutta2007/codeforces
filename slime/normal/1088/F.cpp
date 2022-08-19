#include <bits/stdc++.h>
#define maxn 500005
#define vi vector<int> 
#define ll long long
#define pb push_back
using namespace std;
vi eg[maxn];
int fa[maxn][20];
int w[maxn];
ll ans = 0;
int rt;
void dfs(int a) {
	if (fa[a][0]) {
		ll mn = 1e18;
		for (int i = 0; i < 20; i++) {
			int ed = fa[a][i];
			if (!ed) ed = rt;
			ll nans = w[ed] + w[a] + 1ll * i * min(w[ed], w[a]);
			mn = min(mn, nans);
		}
		ans += mn;
	}
	for (auto v: eg[a]) {
		if (v == fa[a][0]) continue;
		fa[v][0] = a;
		for (int i = 1; i < 20; i++)
			fa[v][i] = fa[fa[v][i - 1]][i - 1];
		dfs(v);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int mpl = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		if (w[i] < w[mpl]) mpl = i;
	}
	rt = mpl;
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		eg[x].pb(y), 
		eg[y].pb(x);
	}
	dfs(mpl);
	cout << ans << endl;
	return 0;
}