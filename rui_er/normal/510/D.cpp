//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 305, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, l[N], c[N];
map<ll, ll> vis, dis;
priority_queue<tuple<ll, ll> > q;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dijkstra(ll s) {
	dis[s] = 0;
	q.push(make_tuple(0, s));
	while(!q.empty()) {
		ll u = get<1>(q.top()); q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		rep(i, 1, n) {
			ll v = __gcd(u, l[i]);
			ll k = dis.count(v) ? dis[v] : inf;
			if(dis[u] + c[i] < k) {
				dis[v] = dis[u] + c[i];
				q.push(make_tuple(-dis[v], v));
			}
		}
	}
}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &l[i]);
	rep(i, 1, n) scanf("%lld", &c[i]);
	dijkstra(0);
	printf("%lld\n", dis.count(1)?dis[1]:-1);
	return 0;
}