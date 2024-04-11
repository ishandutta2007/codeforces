//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
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
struct ST {
	int l, r;
	ST *ch[2];
	int lz;
	pi q;
}p[maxn * 3], *root;
int stcnt = 0;
pi u(pi x, pi y) {
	if (x.fi > y.fi) swap(x, y);
	if (y.fi == x.fi) x.se += y.se;
	return x;
}
void upd(ST *a) {
	a->q = u(a->ch[0]->q, a->ch[1]->q);
}
void bdtree(ST *a, int l, int r) {
	a->q = mp(0, r - l + 1);
	a->l = l, a->r = r, a->lz = 0;
	if (l == r) return ;
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r); 
}
void actlz(ST *a, int lz) {
	a->lz += lz;
	a->q.fi += lz;
}
void pushdown(ST *a) {
	if (a->lz) {
		actlz(a->ch[0], a->lz);
		actlz(a->ch[1], a->lz);
		a->lz = 0;
	}
}
void push(ST *a, int l, int r, int lz) {
	if (l > r) return ;
	if (a->l == l && a->r == r) {
		actlz(a, lz);
		return ;
	}
	int mid = (a->l + a->r) >> 1;
	pushdown(a);
	if (r <= mid)
		push(a->ch[0], l, r, lz);
	else if (l > mid)
		push(a->ch[1], l, r, lz);
	else push(a->ch[0], l, mid, lz), 
		push(a->ch[1], mid + 1, r, lz);
	upd(a);
}
vector<pair<int, pi> > acts;
void work() {
	// 
	root = &p[stcnt++];
	bdtree(root, 1, maxn);
	sort(acts.begin(), acts.end());
	ll ans = 0;
	for (int i = 0; i < acts.size(); i++) {
		if (i) {
			int nt = acts[i].fi - acts[i - 1].fi;
			int tot = maxn - root->q.se;
			ans += 1ll * nt * tot;
		}
		pi um = acts[i].se;
		int tp = 1;
		if (um.fi < 0) {
			tp *= -1;
			um.fi *= -1, um.se *= -1;
		}
		push(root, um.fi, um.se, tp);
	}
	cout << ans << endl;
}
int n, m;
char inp[maxn];
int tp[maxn]; 
int bl[maxn];
int nx[maxn];

vi eg[maxn];
int fa[maxn];
int dfn[maxn], sz[maxn], tf[maxn];
int id(int x, int y) {
	return (x - 1) * m + y;
}
pi tran(int x) {
	int u = (x - 1) / m + 1, v = x % m;
	if (v == 0) v = m;
	return mp(u, v);
}
int dfcnt = 0;
void dfs(int a) {
	dfn[a] = ++dfcnt;
	sz[a] = 1;
	for (auto v : eg[a]) {
		if (v == fa[a]) continue;
		fa[v] = a;
		tf[v] = tf[a];
		dfs(v);
		sz[a] += sz[v];
	}
}
vector<pi> gt(int u, int v) {
	// v
	vector<pi> res;
	if (v == fa[u]) res.pb(mp(dfn[u], dfn[u] + sz[u] - 1));
	else {
		int pre = tf[u];
		int st = dfn[pre], ed = dfn[pre] + sz[pre] - 1;
		if (v == 0) res.pb(mp(st, ed));
		else {
			res.pb(mp(st, dfn[v] - 1));
			res.pb(mp(dfn[v] + sz[v], ed));
		}
	}
	return res;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%s", inp + 1);
		for (int j = 1; j <= m; j++) {
			int nid = id(i, j), eid;
			if (inp[j] == 'U') eid = id(i + 1, j);
			else if (inp[j] == 'L') eid = id(i, j + 1);
			else if (inp[j] == 'D') eid = id(i - 1, j);
			else if (inp[j] == 'R') eid = id(i, j - 1);
			bl[nid] = eid;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int nid = id(i, j);
			pi v = tran(bl[nid]);
			pi ed = mp(2 * v.fi - i, 2 * v.se - j);
			if (ed.fi <= 0 || ed.se <= 0 || ed.fi > n || ed.se > m)
				continue;
			else {
				nx[nid] = id(ed.fi, ed.se);
				eg[nid].pb(nx[nid]), 
				eg[nx[nid]].pb(nid);
			}
		//	cout << nid << ' ' << bl[nid] << ' ' << nx[nid] << endl;
		}
	for (int i = 1; i <= n * m; i++)
		if (!dfn[i]) tf[i] = i, dfs(i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if ((i + j) % 2 == 0) continue;
			int u = id(i, j), v = bl[u];
			vector<pi> xu = gt(u, nx[u]), xv = gt(v, nx[v]);
			for (auto h : xu)
				for (auto m : xv)
					acts.pb(mp(h.fi, m)), 
					acts.pb(mp(h.se + 1, mp(-m.fi, -m.se)));
		}
	work();
	return 0;
}