//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e5+5, inf = 0x3f3f3f3f3f3f3f3fll; 

ll n, m, dis[N], vis[N], from[N];
vector<tuple<ll, ll> > e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dijkstra(ll s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(from, 0, sizeof(from));
	priority_queue<tuple<ll, ll> > q;
	dis[s] = 0;
	q.push(make_tuple(0, s));
	while(!q.empty()) {
		ll u = get<1>(q.top()); q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto i : e[u]) {
			ll v = get<0>(i), w = get<1>(i);
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				from[v] = u;
				q.push(make_tuple(-dis[v], v));
			}
		}
	}
}

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, m) {
		ll u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		e[u].push_back(make_tuple(v, w));
		e[v].push_back(make_tuple(u, w));
	}
	dijkstra(1);
	if(dis[n] == inf) puts("-1");
	else {
		stack<int> ans;
		for(int u=n;u;u=from[u]) ans.push(u);
		for(;!ans.empty();ans.pop()) printf("%d ", ans.top());
		puts("");
	}
	return 0;
}