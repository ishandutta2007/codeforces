#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head#include <iostream>
int t;
int fa[maxn];
int dfn[maxn], low[maxn], sz[maxn];
int dfcnt;
vi eg[maxn];
int n, m;
int ans = 0;
void dfs1(int a) {
	dfn[a] = ++dfcnt;
	sz[a] = 1;
	for (auto v : eg[a]) {
		if (dfn[v]) continue;
		fa[v] = a;
		dfs1(v);
		sz[a] += sz[v];
	}
}
int fe[maxn][2];
bool check(int v) {
	// v 
	for (int i = 1; i <= n; i++)
		fa[i] = 0, sz[i] = 0, dfn[i] = 0;
	dfcnt = 0;
	dfs1(v); 
	for (int i = 1; i <= n; i++)
		for (auto v : eg[i]) {
			if (fa[v] == i) continue;
			if (dfn[i] >= dfn[v] && dfn[i] < dfn[v] + sz[v]) continue;
			return 0;
		}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) return 0;
	return 1;
}
int tp[maxn], to[maxn]; // tp :  to :  1
int bk[maxn];
void ins(int id, int t) {
	if (t <= fe[id][0]) fe[id][1] = fe[id][0], fe[id][0] = t;
	else if (t <= fe[id][1]) fe[id][1] = t;
}
void dfs2(int a) {
	//  fe 
	fe[a][0] = fe[a][1] = dfn[a];
	low[a] = dfn[a];
	for (auto v : eg[a]) 
		if (dfn[v] < dfn[a]) {
			low[a] = min(low[a], dfn[v]);
			ins(a, dfn[v]);
		}
		else {
			dfs2(v);
			low[a] = min(low[a], low[v]);
			for (int j = 0; j < 2; j++)
				ins(a, fe[v][j]);
		}
}
void work(int pl) {
	for (int i = 1; i <= n; i++)
		bk[dfn[i]] = i;
	dfs2(pl);
	for (int i = 1; i <= n; i++) {
		int id = bk[i];
		tp[id] = 1;
		if (fe[id][1] < dfn[id]) tp[id] = 0;
		if (fe[id][0] < dfn[id] && !tp[bk[fe[id][0]]]) tp[id] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int id = bk[i];
		if (i == 1) to[id] = 1;
		else {
			to[id] = 0;
			int e = bk[fe[id][0]];
			if (to[e]) to[id] = 1;
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) eg[i].clear();
		for (int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			eg[u].pb(v);
		}
		int pl = 0, fl = 0;
		for (int t = 0; t < 80; t++) {
			pl = (rand() % 32768) * 32768 + rand() % 32768;
			pl = pl % n + 1;
		//	pl = 2;
			if (check(pl)) {
				fl = 1;
				break;
			}
		}
		if (!fl) cout << -1 << endl;
		else {
		//	cout << "!!!" << pl << endl;
			work(pl);
			int ans = 0;
			for (int i = 1; i <= n; i++)
				if (tp[i] && to[i]) ans++;
			if (ans * 5 < n) cout << -1 << endl;
			else {
				for (int i = 1; i <= n; i++)
					if (tp[i] && to[i]) {
						printf("%d ", i);
					}
				printf("\n");
			}
		}
	}
	return 0;
}