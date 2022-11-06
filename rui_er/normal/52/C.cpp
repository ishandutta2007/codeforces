//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, K = N<<2, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, m, a[N];
struct Node {
	ll mx, tag;
	Node(ll a=0, ll b=0) : mx(a), tag(b) {}
	~Node() {}
}t[K];
#define lc(u) (u<<1)
#define rc(u) (u<<1|1)
void pushup(ll u) {t[u].mx = min(t[lc(u)].mx, t[rc(u)].mx);}
void pushdown(ll u) {
	if(!t[u].tag) return;
	t[lc(u)].tag += t[u].tag;
	t[rc(u)].tag += t[u].tag;
	t[lc(u)].mx += t[u].tag;
	t[rc(u)].mx += t[u].tag;
	t[u].tag = 0;
}
void build(ll u, ll l, ll r) {
	if(l == r) {t[u].mx = a[l]; return;}
	ll mid = (l + r) >> 1;
	build(lc(u), l, mid);
	build(rc(u), mid+1, r);
	pushup(u);
}
void modify(ll u, ll l, ll r, ll ql, ll qr, ll delta) {
	if(ql <= l && r <= qr) {t[u].mx += delta; t[u].tag += delta; return;}
	pushdown(u);
	ll mid = (l + r) >> 1;
	if(ql <= mid) modify(lc(u), l, mid, ql, qr, delta);
	if(qr > mid) modify(rc(u), mid+1, r, ql, qr, delta);
	pushup(u);
}
ll query(ll u, ll l, ll r, ll ql, ll qr) {
	if(ql <= l && r <= qr) return t[u].mx;
	pushdown(u);
	ll mid = (l + r) >> 1, ans = inf;
	if(ql <= mid) ans = min(ans, query(lc(u), l, mid, ql, qr));
	if(qr > mid) ans = min(ans, query(rc(u), mid+1, r, ql, qr));
	return ans;
}
#undef lc
#undef rc

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	build(1, 1, n);
	scanf("%lld", &m);
	rep(i, 1, m) {
		ll x, y, z, ans = inf;
		scanf("%lld%lld", &x, &y);
		++x; ++y;
		char c = getchar();
		if(c == ' ') {
			scanf("%lld", &z);
			if(x <= y) modify(1, 1, n, x, y, z);
			else modify(1, 1, n, 1, y, z), modify(1, 1, n, x, n, z);
		}
		else {
			if(x <= y) ans = query(1, 1, n, x, y);
			else ans = min(query(1, 1, n, 1, y), query(1, 1, n, x, n));
			printf("%lld\n", ans);
		}
	}
    return 0;
}