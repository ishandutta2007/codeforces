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
struct uni {
	vi fa, col;
	bool flag;
	void init(int n) {
		fa.resize(n + 1), col.resize(n + 1);
		for (int i = 0; i <= n; i++)
			fa[i] = i, col[i] = 0;
		flag = 1;
	}
	int gfa(int a) {
		if (fa[a] == a) return a;
		int nf = gfa(fa[a]);
		col[a] ^= col[fa[a]];
		return fa[a] = nf;
	}
	void lk(int u, int v, int c) {
		int uf = gfa(u), vf = gfa(v);
		int nc = col[u] ^ col[v] ^ c;
		if (uf != vf) 
			fa[uf] = vf, 
			col[uf] = nc;
		else 
			if (nc) flag = 0;
	}
}tr[maxn], leg;
int id[maxn];
int nid[maxn];
vi eg[maxn];
int c[maxn];
vi bl[maxn];
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> c[i], 
		bl[c[i]].pb(i);
	vector<pair<pi, pi> > cur;
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (c[u] < c[v]) swap(u, v);
		eg[u].pb(v), eg[v].pb(u);
		cur.pb(mp(mp(c[u], c[v]), mp(u, v)));
	}
	int cnt = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < bl[i].size(); j++)
			id[bl[i][j]] = j;
		tr[i].init(bl[i].size());
		for (auto v : bl[i])
			for (auto s : eg[v]) {
				if (c[s] != i) continue;
				tr[i].lk(id[v], id[s], 1);
			}
		if (tr[i].flag) cnt++;
	}
	ll ans = 1ll * cnt * (cnt - 1) / 2;
	sort(cur.begin(), cur.end());
	for (int i = 0; i < cur.size(); ) {
		int j = i;
		while (j < cur.size() && cur[j].fi == cur[i].fi) j++;
		int c1 = cur[i].fi.fi, c2 = cur[i].fi.se;
		if (tr[c1].flag && tr[c2].flag && c1 != c2) {
			int idcnt = 0;
			vector<pair<pi, int> >s;
			for (int k = i; k < j; k++) {
				int u = cur[k].se.fi, v = cur[k].se.se;
				int uf = 
				tr[c1].gfa(id[u]), 
				vf = tr[c2].gfa(id[v]), 
				cu = tr[c1].col[id[u]] ^ tr[c2].col[id[v]] ^ 1;
				s.pb(mp(mp(uf, vf + bl[c1].size()), cu));
			}
			for (auto h : s)
				nid[h.fi.fi] = ++idcnt, nid[h.fi.se] = ++idcnt;
			leg.init(idcnt);
			for (auto h : s)
				leg.lk(nid[h.fi.fi], nid[h.fi.se], h.se);
			if (!leg.flag) ans--;
		}
		i = j;
	}
	cout << ans << endl;
	return 0;
}