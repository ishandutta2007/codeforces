//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n; 
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	ll lc, rc, w, s[5];
};
struct SegTree {
	Node t[N<<4];
	ll sz, rt;
	void pushup(ll u) {
		t[u].w = t[t[u].lc].w + t[t[u].rc].w;
		rep(i, 0, 4) t[u].s[i] = t[t[u].lc].s[i];
		rep(i, 0, 4) t[u].s[i] += t[t[u].rc].s[((i-t[t[u].lc].w)%5+5)%5];
	}
	void modify(ll& u, ll l, ll r, ll pos, ll k) {
		if(!u) u = ++sz;
		if(l == r) {
			t[u].w += k;
			t[u].s[1] += l * k;
			return;
		}
		ll mid = (l + r) >> 1;
		if(pos <= mid) modify(t[u].lc, l, mid, pos, k);
		else modify(t[u].rc, mid+1, r, pos, k);
		pushup(u);
	}
	ll query() {
		return t[rt].s[3];
	}
}sgt;

int main() {
	for(scanf("%lld", &n);n;n--) {
		char op[4];
		ll x;
		scanf("%s", op);
		if(op[0] == 'a') {
			scanf("%lld", &x);
			sgt.modify(sgt.rt, 1, 1000000000, x, 1);
		}
		else if(op[0] == 'd') {
			scanf("%lld", &x);
			sgt.modify(sgt.rt, 1, 1000000000, x, -1);
		}
		else printf("%lld\n", sgt.query());
	}
	return 0;
}