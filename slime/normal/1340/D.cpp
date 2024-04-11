//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
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
vector<pi> fn;
int fa[maxn];
int cnt[maxn];
int son[maxn];
int c[maxn];
int dg[maxn];
int mx, mcnt;
int ed = 0;
int sz[maxn];
vi eg[maxn];
void dfs(int a) {
	if (dg[a] == mx) sz[a]++;
	for (auto v : eg[a]) {
		if (v == fa[a]) continue;
		sz[v] = sz[a];
		fa[v] = a;
		dfs(v);
	}
}
void work(int a, int x) {
//	cout << "WORK" << a << ' ' << x << endl; 
	fn.pb(mp(a, x));
	vi ns;
	for (auto v : eg[a]) {
		if (v == fa[a] || v == son[a]) continue;
		ns.pb(v);
	}
	if (a == 1) {
		for (auto v : ns) {
			work(v, x + 1);
			x++;
		}
		return ;
	}
	int rb = ns.size() + 1;
	if (a == 1) rb--;
	int px = x;
	int pl = 0;
	while (x < rb) {
	//	cout << a << ' ' << ns[pl] << ' ' << x + 1 << endl;
		work(ns[pl], x + 1);
		pl++;
		x++;
	}
	int qr = px - 1 - (ns.size() - pl);
	fn.pb(mp(a, qr));
	while (pl < ns.size()) {
		work(ns[pl], qr + 1);
		qr++;
		pl++;
	}
	if (c[a]) {
		if (son[a]) work(son[a], qr + 1);
	}
	else fn.pb(mp(fa[a], qr + 1)); 
}
int main() {
	int n; 
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		cout << 1 << ' ' << 0 << endl;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v), eg[v].pb(u);
	}
	for (int i = 1; i <= n; i++)
		dg[i] = eg[i].size();
	
	for (int i = 1; i <= n; i++) {
		if (mx == dg[i]) mcnt++;
		else if (dg[i] > mx) {
			mx = dg[i];
			mcnt = 1;
		}
	}
	dfs(1);
	/*
	for (int i = 1; i <= n; i++) {
		if (i == 1) continue;
		if (eg[i].size() >= 2) continue;
		ed = i;
		if (sz[i] == mcnt) break;
	}
//	cout << ed << endl;
	while (ed != 1) {
		son[fa[ed]] = ed;
		c[ed] = 1;
		ed = fa[ed];
	}
	c[1] = 1;
	*/
	work(1, 0);
	cout << fn.size() << endl;
	for (auto v : fn)
		printf("%d %d\n", v.fi, v.se);
	return 0;
}
/*
5
1 6
2 9
5 12
5 24
6 36
9 48
*/