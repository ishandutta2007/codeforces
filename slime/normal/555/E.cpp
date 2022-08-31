#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int dfn[maxn], low[maxn];
vi eg[maxn];
int u[maxn], v[maxn];
int n, m, q;
int st[maxn], top = 0;
int dfcnt = 0;
int bl[maxn], idcnt = 0;
void dfs(int a, int fa) {
	dfn[a] = low[a] = ++dfcnt;
	st[top++] = a;
	int tot = 0;
	for (auto v: eg[a]) {
		if (dfn[v]) {
			if (v != fa || tot)
				low[a] = min(low[a], dfn[v]);
			else tot++;
		}
		else {
			dfs(v, a);
			low[a] = min(low[a], low[v]);
		}
	}
	if (low[a] == dfn[a]) {
		idcnt++;
		while (1) {
			int ns = st[--top];
			bl[ns] = idcnt;
			if (ns == a) break;
		}
	}
}
int fa[maxn][20], dep[maxn], t[2][maxn];
vi feg[maxn];
const int test = 0;
void dfs2(int a) {
	if (test) cout << a << ' ' << fa[a][0] << endl;
	for (auto v: feg[a]) {
		if (dep[v]) continue;
		dep[v] = dep[a] + 1;
		fa[v][0] = a;
		for (int i = 1; i < 20; i++)
			fa[v][i] = fa[fa[v][i - 1]][i - 1];
		dfs2(v);
	}
}
int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int i = 19; i >= 0; i--)
		if (dep[fa[a][i]] >= dep[b]) a = fa[a][i];
	for (int i = 19; i >= 0; i--)
		if (fa[a][i] != fa[b][i])
			a = fa[a][i], b = fa[b][i];
	if (a != b) a = fa[a][0];
	return a; 
}
bool flag = 1;
void ch(int x, int y) {
	int lc = lca(x, y);
	if (!lc) flag = 0;
	t[0][x]++, t[0][lc]--;
	t[1][y]++, t[1][lc]--;
	if (test) cout << "CH" << x << ' ' << y << endl;
}

void dfs3(int a) {
	for (auto v: feg[a]) {
		if (v == fa[a][0]) continue;
		dfs3(v);
		t[0][a] += t[0][v], t[1][a] += t[1][v];
	}
	if (t[0][a] && t[1][a]) flag = 0;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u[i], &v[i]);
		eg[u[i]].pb(v[i]), 
		eg[v[i]].pb(u[i]);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			dfs(i, 0);
	if (test)
		for (int i = 1; i <= n; i++)
			cout << bl[i] << endl;
	for (int i = 1; i <= m; i++)
		if (bl[u[i]] != bl[v[i]]) {
			feg[bl[u[i]]].pb(bl[v[i]]), 
			feg[bl[v[i]]].pb(bl[u[i]]);
			if (test) cout << "LK" << bl[u[i]] << ' ' << bl[v[i]] << endl;
		}
	for (int i = 1; i <= idcnt; i++)
		if (!dep[i])
			dep[i] = 1, 
			dfs2(i);
	for (int i = 1; i <= q; i++) {
		int s, t;
		scanf("%d%d", &s, &t);
		ch(bl[s], bl[t]);
	}
	for (int i = 1; i <= idcnt; i++)
		if (dep[i] == 1)
			dfs3(i);
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl; 
	return 0;
}