//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 5e5+5;

ll n, m, a[N], w[N], fa[N], dis[N], sz[N], son[N], top[N], dfn[N], tms;
vector<ll> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs1(ll u, ll f) {
	fa[u] = f;
	dis[u] = dis[f] + 1;
	sz[u] = 1;
	for(ll v : e[u]) {
		if(v == f) continue;
		dfs1(v, u);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]]) son[u] = v;
	}
}
void dfs2(ll u, ll tp) {
	top[u] = tp;
	dfn[u] = ++tms;
	w[tms] = a[u];
	if(!son[u]) return;
	dfs2(son[u], tp);
	for(ll v : e[u]) {
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
struct Node {
	ll w, tag;
	Node(ll a=0, ll b=-1) : w(a), tag(b) {}
	~Node() {}
	friend Node operator + (const Node& a, const Node& b) {
		return Node(a.w + b.w);
	}
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void pushup(ll u) {
		t[u] = t[lc(u)] + t[rc(u)];
	}
	void pushdown(ll u, ll l, ll r) {
		if(t[u].tag == -1) return;
		ll mid = (l + r) >> 1;
		t[lc(u)].tag = t[u].tag;
		t[rc(u)].tag = t[u].tag;
		t[lc(u)].w = (mid - l + 1) * t[u].tag;
		t[rc(u)].w = (r - mid) * t[u].tag;
		t[u].tag = -1;
	}
	void modify(ll u, ll l, ll r, ll ql, ll qr, ll k) {
		if(ql <= l && r <= qr) {
			t[u].tag = k;
			t[u].w = (r - l + 1) * k;
			return;
		}
		pushdown(u, l, r);
		ll mid = (l + r) >> 1;
		if(ql <= mid) modify(lc(u), l, mid, ql, qr, k);
		if(qr > mid) modify(rc(u), mid+1, r, ql, qr, k);
		pushup(u);
	}
	Node query(ll u, ll l, ll r, ll pos) {
		if(l == r) return t[u];
		pushdown(u, l, r);
		ll mid = (l + r) >> 1;
		Node ans;
		if(pos <= mid) ans = query(lc(u), l, mid, pos);
		else ans = query(rc(u), mid+1, r, pos);
		pushup(u);
		return ans;
	}
	#undef lc
	#undef rc
}sgt;
void modifyTree(ll u, ll k) {
	sgt.modify(1, 1, n, dfn[u], dfn[u]+sz[u]-1, k);
}
void modifyChain(ll u, ll v, ll k) {
	while(top[u] != top[v]) {
		if(dis[top[u]] < dis[top[v]]) swap(u, v);
		sgt.modify(1, 1, n, dfn[top[u]], dfn[u], k);
		u = fa[top[u]];
	}
	if(dis[u] < dis[v]) swap(u, v);
	sgt.modify(1, 1, n, dfn[v], dfn[u], k);
}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n-1) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	for(scanf("%lld", &m);m;m--) {
		ll op, x;
		scanf("%lld%lld", &op, &x);
		if(op == 1) modifyTree(x, 1);
		else if(op == 2) modifyChain(1, x, 0);
		else printf("%lld\n", sgt.query(1, 1, n, dfn[x]).w);
	}
	return 0;
}