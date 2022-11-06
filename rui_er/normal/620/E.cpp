//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 4e5+5;

ll n, m, a[N], w[N], fa[N], sz[N], dfn[N], tms;
vector<ll> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(ll u, ll f) {
	fa[u] = f;
	sz[u] = 1;
	dfn[u] = ++tms;
	w[tms] = a[u];
	for(ll v : e[u]) {
		if(v == f) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
struct Node {
	ll sta, cov;
	Node(ll a=0, ll b=-1) : sta(a), cov(b) {}
	friend Node operator + (const Node& a, const Node& b) {
		return Node(a.sta | b.sta);
	}
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void pushup(ll u) {
		t[u] = t[lc(u)] + t[rc(u)];
	}
	void pushdown(ll u) {
		if(t[u].cov == -1) return;
		t[lc(u)].cov = t[lc(u)].sta = t[u].cov;
		t[rc(u)].cov = t[rc(u)].sta = t[u].cov;
		t[u].cov = -1;
	}
	void build(ll* a, ll u, ll l, ll r) {
		if(l == r) {
			t[u].sta = 1LL << a[l];
			return;
		}
		ll mid = (l + r) >> 1;
		build(a, lc(u), l, mid);
		build(a, rc(u), mid+1, r);
		pushup(u);
	}
	void assign(ll u, ll l, ll r, ll ql, ll qr, ll k) {
		if(ql <= l && r <= qr) {
			t[u].cov = t[u].sta = 1LL << k;
			return;
		}
		pushdown(u);
		ll mid = (l + r) >> 1;
		if(ql <= mid) assign(lc(u), l, mid, ql, qr, k);
		if(qr > mid) assign(rc(u), mid+1, r, ql, qr, k);
		pushup(u);
	}
	Node query(ll u, ll l, ll r, ll ql, ll qr) {
		if(ql <= l && r <= qr) return t[u];
		pushdown(u);
		ll mid = (l + r) >> 1;
		Node ans;
		if(ql <= mid) ans = ans + query(lc(u), l, mid, ql, qr);
		if(qr > mid) ans = ans + query(rc(u), mid+1, r, ql, qr);
		pushup(u);
		return ans;
	}
	#undef lc
	#undef rc
}sgt;

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n-1) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	sgt.build(w, 1, 1, n);
	while(m--) {
		ll op, x, y;
		scanf("%lld%lld", &op, &x);
		if(op == 1) {
			scanf("%lld", &y);
			sgt.assign(1, 1, n, dfn[x], dfn[x]+sz[x]-1, y);
		}
		else printf("%lld\n", (ll)__builtin_popcountll(sgt.query(1, 1, n, dfn[x], dfn[x]+sz[x]-1).sta));
	}
	return 0;
}