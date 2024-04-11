// Problem: CF739C Alyona and towers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF739C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 3e5+5;

ll n, m, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
template<typename T> T sgn(T& n) {return ((T)0 < n) - (n < (T)0);}
struct Node {
	ll l, r, len, ans, lans, rans;
	Node() : l(0), r(0), len(0), ans(0), lans(0), rans(0) {}
	friend Node operator + (const Node& a, const Node& b) {
		if(!a.len) return b;
		if(!b.len) return a;
		Node c;
		c.l = a.l;
		c.r = b.r;
		c.len = a.len + b.len;
		c.ans = max(a.ans, b.ans);
		c.lans = a.lans;
		c.rans = b.rans;
		if(a.r && b.l && sgn(a.r) >= sgn(b.l)) {
			chkmax(c.ans, a.rans + b.lans);
			if(a.lans == a.len) chkmax(c.lans, a.len + b.lans);
			if(b.rans == b.len) chkmax(c.rans, a.rans + b.len);
		}
		return c;
	}
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void build(ll* a, ll u, ll l, ll r) {
		if(l == r) {
			t[u].l = t[u].r = a[l];
			t[u].len = t[u].ans = t[u].lans = t[u].rans = 1;
			return;
		}
		ll mid = (l + r) >> 1;
		build(a, lc(u), l, mid);
		build(a, rc(u), mid+1, r);
		t[u] = t[lc(u)] + t[rc(u)];
	}
	void modify(ll u, ll l, ll r, ll pos, ll k) {
		if(pos < l || pos > r) return;
		if(l == r) {
			t[u].l = t[u].r += k;
			return;
		}
		ll mid = (l + r) >> 1;
		if(pos <= mid) modify(lc(u), l, mid, pos, k);
		else modify(rc(u), mid+1, r, pos, k);
		t[u] = t[lc(u)] + t[rc(u)];
	}
	#undef lc
	#undef rc
}sgt;

int main() {
	scanf("%lld", &n);
	if(n == 1) {
		scanf("%*lld%lld", &m);
		rep(i, 1, m) puts("1");
		return 0;
	}
	rep(i, 0, n-1) scanf("%lld", &a[i]);
	per(i, n-1, 1) a[i] -= a[i-1];
	sgt.build(a, 1, 1, n-1);
	for(scanf("%lld", &m);m;m--) {
		ll l, r, d;
		scanf("%lld%lld%lld", &l, &r, &d);
		sgt.modify(1, 1, n-1, l-1, d);
		sgt.modify(1, 1, n-1, r, -d);
		printf("%lld\n", sgt.t[1].ans+1);
	}
	return 0;
}