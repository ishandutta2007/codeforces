//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll T, n, a[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Node {
	ll g;
	Node(ll a=0) : g(a) {}
	~Node() {}
}t[N<<2];
#define lc(u) (u<<1)
#define rc(u) (u<<1|1)
void pushup(ll u) {t[u].g = __gcd(t[lc(u)].g, t[rc(u)].g);}
void build(ll u, ll l, ll r) {
	if(l == r) {t[u].g = a[l]; return;}
	ll mid = (l + r) >> 1;
	build(lc(u), l, mid);
	build(rc(u), mid+1, r);
	pushup(u);
}
ll query(ll u, ll l, ll r, ll ql, ll qr) {
	if(ql > qr) return 0;
	if(ql <= l && r <= qr) return t[u].g;
	ll mid = (l + r) >> 1, ans = 0;
	if(ql <= mid) ans = __gcd(ans, query(lc(u), l, mid, ql, qr));
	if(ans == 1) return 1;
	if(qr > mid) ans = __gcd(ans, query(rc(u), mid+1, r, ql, qr));
	return ans;
}
void init(ll u, ll l, ll r) {
	t[u].g = 0;
	if(l == r) return;
	ll mid = (l + r) >> 1;
	init(lc(u), l, mid);
	init(rc(u), mid+1, r);
}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		if(n == 1) {puts("1"); continue;}
		per(i, n, 2) a[i] -= a[i-1];
		rep(i, 1, n-1) a[i] = abs(a[i+1]);
		build(1, 1, n-1);
		ll L = 1, R = 1, mx = 0;
		while(L < n) {
			ll now = query(1, 1, n-1, L, R);
//			printf("L = %lld, R = %lld, now = %lld\n", L, R, now);
			while(R < n) {
				if(R == n - 1) {
//					if(now != 1) ++R;
					break;
				}
				if(__gcd(now, a[R+1]) != 1) {
					now = __gcd(now, a[++R]);
				}
				else {
					break;
				}
//				printf("L = %lld, R = %lld, now = %lld\n", L, R, now);
			}
//			printf("mx = %lld, len = %lld\n", mx, R-L+1);
			if(now > 1) chkmax(mx, R-L+1); chkmax(R, L);
			++L;
		}
		printf("%lld\n", mx+1);
		init(1, 1, n-1);
	}
	return 0;
}