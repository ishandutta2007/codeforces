//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
using namespace std;
typedef long long ll;
const ll N = 3e6+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, q, s, tot, dis[N], vis[N], rt[2];
struct Edge {
	ll v, w, nxt;
	Edge(ll a=0, ll b=0, ll c=0) : v(a), w(b), nxt(c) {}
	~Edge() {}
}e[N];
ll ne = 1, h[N];
void add(ll u, ll v, ll w) {e[++ne] = Edge(v, w, h[u]); h[u] = ne;}
struct Node {
	ll l, r, lc, rc;
}t[N];
void build(ll &u, ll l, ll r, ll k) { // k=0,1 <=> In/Out Tree
	t[u].l = l; t[u].r = r;
	if(l == r) {u = l; return;}
	u = ++tot;
	ll mid = (l + r) >> 1;
	build(t[u].lc, l, mid, k);
	build(t[u].rc, mid+1, r, k);
	if(k) add(u, t[u].lc, 0), add(u, t[u].rc, 0);
	else add(t[u].lc, u, 0), add(t[u].rc, u, 0);
}
void modify(ll u, ll l, ll r, ll st, ll ql, ll qr, ll w, ll k) { // k=0,1 <=> []->#/#->[] 
	if(ql <= l && r <= qr) {
		if(k) add(st, u, w);
		else add(u, st, w);
		return;
	}
	ll mid = (l + r) >> 1;
	if(ql <= mid) modify(t[u].lc, l, mid, st, ql, qr, w, k);
	if(qr > mid) modify(t[u].rc, mid+1, r, st, ql, qr, w, k);
}
priority_queue<pair<ll, ll> > hp;
void dijkstra(ll s) {
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0; hp.push(make_pair(0, s));
	while(!hp.empty()) {
		ll u = hp.top().second; hp.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(ll i=h[u];i;i=e[i].nxt) {
			ll v = e[i].v, w = e[i].w;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				hp.push(make_pair(-dis[v], v));
			}
		}
	}
}

int main() {
	scanf("%lld%lld%lld", &n, &q, &s);
	tot = n;
	build(rt[0], 1, n, 0);
	build(rt[1], 1, n, 1);
	rep(i, 1, q) {
		ll op, a, b, c, d;
		scanf("%lld%lld%lld%lld", &op, &a, &b, &c);
		if(op != 1) scanf("%lld", &d);
		if(op == 1) add(a, b, c);
		else if(op == 2) modify(rt[1], 1, n, a, b, c, d, 1);
		else modify(rt[0], 1, n, a, b, c, d, 0);
	}
	dijkstra(s);
	rep(i, 1, n) printf("%lld%c", dis[i]<inf?dis[i]:-1, " \n"[i==n]);
	return 0;
}