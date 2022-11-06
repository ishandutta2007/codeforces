//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 3e5+5, K = 1e6+5;

ll n, m, a[N], d[K];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct BIT {
	ll c[N];
	ll lowbit(ll x) {
		return x & (-x);
	}
	void add(ll x, ll k) {
		for(;x<=n;x+=lowbit(x)) {
			c[x] += k;
		}
	}
	ll ask(ll x) {
		ll k = 0;
		for(;x;x-=lowbit(x)) {
			k += c[x];
		}
		return k;
	}
}bit;
struct Dsu {
	ll fa[N];
	void init(ll x) {
		rep(i, 1, x) fa[i] = i;
	}
	ll find(ll x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
}dsu;

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		bit.add(i, a[i]);
	}
	rep(i, 1, K-5) {
		for(ll j=i;j<=K-5;j+=i) {
			++d[j];
		}
	}
	dsu.init(n);
	rep(i, 1, m) {
		ll op, l, r;
		scanf("%lld%lld%lld", &op, &l, &r);
		if(op == 1) {
			for(ll u=r;u>=l;u=min(dsu.find(u), u-1)) {
				ll v = dsu.find(u);
				if(u == v) {
					ll diff = d[a[u]] - a[u];
					bit.add(u, diff);
					a[u] = d[a[u]];
					if(a[u] <= 2) {
						dsu.fa[u] = u - 1;
					}
				}
			}
		}
		else {
			printf("%lld\n", bit.ask(r)-bit.ask(l-1));
		}
	}
	return 0;
}