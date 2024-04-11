//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n, l[N], r[N], dp[N][2];
struct Edge {
	int v, nxt;
	Edge(int a=0, int b=0) : v(a), nxt(b) {}
	~Edge() {}
}e[N<<1];
int h[N], ne = 1;
void add(ll u, ll v) {
	e[++ne] = Edge(v, h[u]); h[u] = ne;
	e[++ne] = Edge(u, h[v]); h[v] = ne;
}
void dfs(ll u, ll f) {
	for(ll i=h[u];i;i=e[i].nxt) {
		ll v = e[i].v;
		if(v != f) {
			dfs(v, u);
			dp[u][0] += max(dp[v][0]+abs(l[u]-l[v]), dp[v][1]+abs(l[u]-r[v]));
			dp[u][1] += max(dp[v][0]+abs(r[u]-l[v]), dp[v][1]+abs(r[u]-r[v]));
		}
	}
}
void do_init() {
	rep(i, 1, ne) e[i] = Edge();
	rep(i, 1, n) h[i] = dp[i][0] = dp[i][1] = 0;
	ne = 0;
}

int main() {
	mulT0 {
		do_init();
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld%lld", &l[i], &r[i]);
		rep(i, 1, n-1) {
			ll u, v;
			scanf("%lld%lld", &u, &v);
			add(u, v);
		}
		dfs(1, 0);
		ll ans = max(dp[1][0], dp[1][1]);
		printf("%lld\n", ans);
	}
	return 0;
}