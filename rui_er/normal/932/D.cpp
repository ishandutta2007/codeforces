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
const ll N = 4e5+5, inf = 0x3f3f3f3f3f3f3f3f;

ll w[N], fa[N][22], s[N][22], pw2[22], tot = 1, lst;

void initPow() {rep(i, 0, 20) pw2[i] = (1 << i);}
void link(ll u, ll v) { // u <=> newNode ; v <=> linkTo
	if(w[u] <= w[v]) fa[u][0] = v;
	else {per(i, 20, 0) if(w[u] > w[fa[v][i]]) v = fa[v][i]; fa[u][0] = fa[v][0];}
	s[u][0] = w[fa[u][0]];
	rep(i, 1, 20) {
		fa[u][i] = fa[fa[u][i-1]][i-1];
		s[u][i] = min(s[u][i-1]+s[fa[u][i-1]][i-1], inf);
	}
}
ll query(ll u, ll x) {
	if(w[u] > x) return 0;
	ll res = 1;
	x -= w[u];
	per(i, 20, 0) {
		if(x >= s[u][i]) {
			x -= s[u][i];
			res += pw2[i];
			u = fa[u][i];
		}
	}
	return res;
}

int main() {
	fil(s, 0x3f); w[0] = inf;
	initPow();
	mulT0 {
		ll op, a, b;
		scanf("%lld%lld%lld", &op, &a, &b);
		a ^= lst; b ^= lst;
		if(op == 1) {
			w[++tot] = b;
			link(tot, a);
		}
		else printf("%lld\n", lst=query(a, b));
	}
	return 0;
}