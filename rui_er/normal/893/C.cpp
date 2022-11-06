//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(ll (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n, m, a[N], ans;
struct DSU {
	ll fa, mi;
	DSU(ll a=0, ll b=0) : fa(a), mi(b) {}
	~DSU() {}
}dsu[N];
void init(ll x) {rep(i, 1, x) dsu[i] = DSU(i, a[i]);}
ll find(ll x) {return x == dsu[x].fa ? x : dsu[x].fa = find(dsu[x].fa);}
ll merge(ll x, ll y) {
	ll u = find(x), v = find(y);
	if(u != v) {
		dsu[u].fa = v;
		dsu[v].mi = min(dsu[u].mi, dsu[v].mi);
		return 1;
	}
	return 0;
}
ll isroot(ll x) {return x == dsu[x].fa;}

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]);
	init(n);
	rep(i, 1, m) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		x = merge(x, y);
	}
	rep(i, 1, n) ans += isroot(i) ? dsu[i].mi : 0;
	printf("%lld\n", ans);
	return 0;
}