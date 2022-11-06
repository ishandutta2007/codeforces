// Problem: CF938D Buy a Ticket
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF938D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll n, m, a[N], dis[N], vis[N];
vector<tuple<ll, ll> > e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dijkstra(ll s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
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
		e[u].emplace_back(v, w<<1);
		e[v].emplace_back(u, w<<1);
	}
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		e[n+1].emplace_back(i, a[i]);
		e[i].emplace_back(n+1, a[i]);
	}
	dijkstra(n+1);
	rep(i, 1, n) printf("%lld%c", dis[i], " \n"[i==n]);
	return 0;
}