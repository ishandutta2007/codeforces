#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
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
int u[maxn], v[maxn], w[maxn];
vi eg[maxn];
ll dp[2][maxn]; // 0 :  1 : 
ll mx[2][maxn]; // 
int n;
int fa[maxn], fw[maxn]; // 
ll res[maxn];
void dfs1(int a) {
	for (auto i: eg[a]) {
		int vv = u[i] ^ v[i] ^ a;
		if (vv == fa[a]) continue;
		fw[vv] = w[i];	
		fa[vv] = a, 
		dfs1(vv);
		ll ns = dp[0][vv] + w[i];
		if (ns > mx[0][a]) mx[1][a] = mx[0][a], mx[0][a] = ns;
		else if (ns > mx[1][a]) mx[1][a] = ns; 
	}
	dp[0][a] = mx[0][a];
}
void dfs2(int a) {
	dp[1][a] = 0;
	if (fa[a]) {
		int nf = fw[a];
		dp[1][a] = nf + dp[1][fa[a]];
		if (nf + dp[0][a] == mx[0][fa[a]]) 
			dp[1][a] = max(dp[1][a], nf + mx[1][fa[a]]);
		else 
			dp[1][a] = max(dp[1][a], nf + mx[0][fa[a]]);
	}
	res[a] = max(dp[1][a], dp[0][a]);
	for (auto i: eg[a]) {
		int vv = u[i] + v[i] - a;
		if (vv == fa[a]) continue;
		dfs2(vv);
	}
}
int ans = 0;
pair<ll, int> g[maxn];
int d[maxn];
int pre[maxn][20];
void dfs3(int a) {
	for (auto i: eg[a]) {
		int vv = u[i] ^ v[i] ^ a;
		if (vv == pre[a][0]) continue;
		pre[vv][0] = a;
		for (int i = 1; i < 20; i++)
			pre[vv][i] = pre[pre[vv][i - 1]][i - 1];
		dfs3(vv);
	}
}
void dfs4(int a) {
	for (auto i: eg[a]) {
		int vv = u[i] ^ v[i] ^ a;
		if (vv == pre[a][0]) continue;
		dfs4(vv);
		d[a] += d[vv];
	}
}
int work(ll t) {
	ans = 1;
	memset(d, 0, sizeof(d));
//	for (int i = 1; i <= n; i++)
//		cout << pre[i][0] << ' ' << res[i] << endl;
	for (int i = 1; i <= n; i++) {
		int ns = i;
		for (int j = 19; j >= 0; j--)
			if (res[pre[ns][j]] >= res[i] - t) 
				ns = pre[ns][j];
		d[i]++, d[pre[ns][0]]--;
	}
	dfs4(g[1].se);
	for (int i = 1; i <= n; i++)
		ans = max(ans, d[i]);
	return ans;
}
int main() {
//	freopen("code.in","r",stdin);
//	freopen("1.out", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		eg[u[i]].pb(i), eg[v[i]].pb(i);
	}
	dfs1(1);
	dfs2(1);
	int q;
	cin >> q;
	for (int i = 1; i <= n; i++)
		g[i] = mp(res[i], i);
	sort(g + 1, g + n + 1);
	dfs3(g[1].se);
	for (int i = 0; i < q; i++) {
		ll l;
		cin >> l;
		cout << work(l) << endl;
	}
	return 0;
}
/*
5
1 2 3
2 3 4
4 5 3
3 4 2
1
2
*/