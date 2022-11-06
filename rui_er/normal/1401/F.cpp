//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e6+5;

ll n, m, a[N], rev[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	ll w, dis;
};
struct SegTree {
	Node t[N];
	#define rv(u) (rev[t[u].dis])
	#define lc(u) (u<<1|rv(u))
	#define rc(u) (u<<1|rv(u)^1)
	void pushup(ll u) {
		t[u].w = t[lc(u)].w + t[rc(u)].w; 
	}
	void build(ll u, ll l, ll r) {
		if(l == r) {
			t[u].w = a[l];
			return;
		}
		ll mid = (l + r) >> 1;
		build(lc(u), l, mid);
		build(rc(u), mid+1, r);
		t[u].dis = t[lc(u)].dis + 1;
		pushup(u);
	}
	void modify(ll u, ll l, ll r, ll pos, ll k) {
		if(l == r) {
			t[u].w = k;
			return;
		}
		ll mid = (l + r) >> 1;
		if(pos <= mid) modify(lc(u), l, mid, pos, k);
		else modify(rc(u), mid+1, r, pos, k);
		pushup(u);
	}
	ll query(ll u, ll l, ll r, ll ql, ll qr) {
		if(ql <= l && r <= qr) return t[u].w;
		ll mid = (l + r) >> 1, ans = 0;
		if(ql <= mid) ans += query(lc(u), l, mid, ql, qr);
		if(qr > mid) ans += query(rc(u), mid+1, r, ql, qr);
		return ans;
	}
	#undef rv
	#undef lc
	#undef rc
}sgt;

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, 1<<n) scanf("%lld", &a[i]);
	sgt.build(1, 1, 1<<n);
	while(m --> 0) {
		ll op, x, y;
		scanf("%lld%lld", &op, &x);
		if(op == 1) {
			scanf("%lld", &y);
			sgt.modify(1, 1, 1<<n, x, y);
		}
		else if(op == 2) {
			rep(i, 0, x) rev[i] ^= 1;
		}
		else if(op == 3) {
			rev[x+1] ^= 1;
		}
		else {
			scanf("%lld", &y);
			printf("%lld\n", sgt.query(1, 1, 1<<n, x, y));
		}
	}
	return 0;
}