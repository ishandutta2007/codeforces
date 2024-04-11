//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n, m, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	ll s, mx;
	Node(ll a=0, ll b=0) : s(a), mx(b) {}
	~Node() {} 
}t[N<<2];
#define lc(u) (u<<1)
#define rc(u) (u<<1|1)
void pushup(ll u) {
	t[u].s = t[lc(u)].s + t[rc(u)].s;
	t[u].mx = max(t[lc(u)].mx, t[rc(u)].mx);
}
void build(ll u, ll l, ll r) {
	if(l == r) {
		t[u].s = t[u].mx = a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build(lc(u), l, mid);
	build(rc(u), mid+1, r);
	pushup(u);
}
ll query(ll u, ll l, ll r, ll ql, ll qr) {
	if(ql <= l && r <= qr) return t[u].s;
	ll mid = (l + r) >> 1, ans = 0;
	if(ql <= mid) ans += query(lc(u), l, mid, ql, qr);
	if(qr > mid) ans += query(rc(u), mid+1, r, ql, qr);
	return ans;
}
void mod(ll u, ll l, ll r, ll ql, ll qr, ll k) {
	if(t[u].mx < k) return;
	if(l == r) {
		t[u].s %= k;
		t[u].mx %= k;
		return;
	}
	ll mid = (l + r) >> 1;
	if(ql <= mid) mod(lc(u), l, mid, ql, qr, k);
	if(qr > mid) mod(rc(u), mid+1, r, ql, qr, k);
	pushup(u);
}
void modify(ll u, ll l, ll r, ll pos, ll k) {
	if(l == r) {
		t[u].s = t[u].mx = k;
		return;
	}
	ll mid = (l + r) >> 1;
	if(pos <= mid) modify(lc(u), l, mid, pos, k);
	else modify(rc(u), mid+1, r, pos, k);
	pushup(u);
}

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]);
	build(1, 1, n);
	while(m --> 0) {
		ll op, x, y, z;
		scanf("%lld%lld%lld", &op, &x, &y);
		if(op == 1) printf("%lld\n", query(1, 1, n, x, y));
		else if(op == 2) {
			scanf("%lld", &z);
			mod(1, 1, n, x, y, z);
		}
		else modify(1, 1, n, x, y);
	}
	return 0;
}