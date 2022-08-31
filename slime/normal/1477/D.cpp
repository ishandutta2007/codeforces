//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
unordered_map<int, int> eg[maxn];
set<int> nd;
#define iter set<int>::iterator
int idcnt = 0;
vi neg[maxn]; 
int fa[maxn];
void dfs(int a) {
	nd.erase(a);
	int ff = 0;
	while (1) {
		iter h = nd.lower_bound(ff);
		if (h == nd.end()) break;
		int nid = *(h);
		if (!eg[a][nid]) 
			neg[a].pb(nid), 
			neg[nid].pb(a), 
			dfs(nid);
		ff = nid + 1;
	}
}

vi cen[maxn];
int fl[maxn];
void dfs2(int a) {
	for (auto v : neg[a]) {
		if (v == fa[a]) continue;
		fa[v] = a;
		dfs2(v);
	}
	fl[a] = 0;
	if (!cen[a].size()) {
		if (fa[a]) cen[fa[a]].pb(a);
		else if (neg[a].size()) 
			cen[neg[a][0]].pb(a);
		else fl[a] = 1;
	}
	else fl[a] = 1;
}
int dfn[maxn], cur[maxn];
void work(int a) {
	idcnt++;
	dfn[a] = idcnt;
	for (int j = 0; j < cen[a].size(); j++)
		dfn[cen[a][j]] = dfn[a] + j + 1;
	cur[a] = idcnt + cen[a].size();
	for (int j = 0; j < cen[a].size(); j++)
		cur[cen[a][j]] = idcnt + j;
	idcnt += cen[a].size();
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			eg[i].clear(), 
			neg[i].clear(), 
			fa[i] = 0, 
			cen[i].clear();
		for (int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			eg[u][v] = eg[v][u] = 1;
		}
		nd.clear();
		for (int i = 1; i <= n; i++)
			nd.insert(i);
		idcnt = 0;
		while (!nd.empty()) 
			dfs(*nd.begin());
		for (int i = 1; i <= n; i++) 
			if (!fa[i]) dfs2(i);
		
		for (int i = 1; i <= n; i++)
			if (fl[i]) work(i);
			
		for (int i = 1; i <= n; i++)
			printf("%d ", dfn[i]);
		printf("\n");
		for (int i = 1; i <= n; i++)
			printf("%d ", cur[i]);
		printf("\n");
	}
	return 0;
}