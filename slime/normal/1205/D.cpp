#include <bits/stdc++.h>
#define ll long long
#define maxn 2005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
vi eg[maxn];
int sz[maxn];
void dfs(int a, int f) {
	sz[a] = 1;
	for (int i = 0; i < eg[a].size(); i++) {
		if (eg[a][i] == f) continue;
		dfs(eg[a][i], a);
		sz[a] += sz[eg[a][i]];
	}
}
int nd[2][maxn], ncnt[2];
struct th {
	int id, sz;
	bool operator < (const th &u)const 
	{
		return sz > u.sz;
	}
}p[maxn];
int tp[maxn]; 
void dfs(int a, int f, int tp, int num) {
	for (int i = 0; i < eg[a].size(); i++) {
		int v = eg[a][i];
		if (v == f) continue;
		int nx = nd[tp][ncnt[tp]++];
		cout << a << " " << v << " " << nx - num << endl;
		dfs(v, a, tp, nx);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		eg[u].pb(v), eg[v].pb(u);
	}
	int mn = maxn, mpl = 0;
	for (int i = 1; i <= n; i++) {
		dfs(i, 0);
		int nr = 0;
		for (int j = 0; j < eg[i].size(); j++) {
			nr = max(nr, sz[eg[i][j]]);
		}
		if (nr < mn) mn = nr, mpl = i;
	}
	dfs(mpl, 0);
	int s[2] = {0, 0};
	int ss = eg[mpl].size();
	for (int i = 0; i < ss; i++) {
		int v = eg[mpl][i];
		p[i].id = v, p[i].sz = sz[v];
	}
	sort(p, p + ss);

	for (int i = 0; i < ss; i++) {
		if (s[0] < s[1]) tp[i] = 0, s[0] += p[i].sz;
		else tp[i] = 1, s[1] += p[i].sz;
	}	
//	cout << s[0] << " " << s[1] << endl;
	for (int i = 0; i < s[0]; i++)
		nd[0][i] = i + 1;
	for (int i = 0; i < s[1]; i++)
		nd[1][i] = (i + 1) * (s[0] + 1);
	for (int i = 0; i < ss; i++) {
		int nr = nd[tp[i]][ncnt[tp[i]]++];
		cout << mpl << " " << p[i].id << " " << nr << endl;
		dfs(p[i].id, mpl, tp[i], nr);
	}
	return 0;
}