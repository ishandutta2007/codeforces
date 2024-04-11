//By: Luogu@rui_er(122461)
//2021C++T3
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n, m, q, dis[N][2], vis[N][2], from[N][2], on_diameter[N], diameter[N], rt[N], tot;
vector<ll> d[N], s[N];
map<pair<ll, ll>, double> Ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Edge {
	ll v, nxt;
	Edge(ll a=0, ll b=0) : v(a), nxt(b) {}
	~Edge() {}
}e[N<<1];
ll ne = 1, h[N];
void add(ll u, ll v) {
	e[++ne] = Edge(v, h[u]); h[u] = ne;
	e[++ne] = Edge(u, h[v]); h[v] = ne;
}

ll fa[N], sz[N];
void init(ll x) {
	rep(i, 1, x) {
		fa[i] = i;
		sz[i] = 1;
	}
}
ll find(ll x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool merge(ll x, ll y) {
	ll u = find(x), v = find(y);
	if(u == v) return 0;
	if(sz[u] > sz[v]) swap(u, v);
	fa[u] = v; sz[v] += sz[u];
	return 1;
}
bool check(ll x, ll y) {
	return find(x) != find(y);
}

queue<ll> Q;
ll bfs(ll s, ll c) {
	dis[s][c] = 0;
	vis[s][c] = 1;
	Q.push(s);
	ll res = s;
	while(!Q.empty()) {
		ll u = Q.front(); Q.pop();
		for(ll i=h[u];i;i=e[i].nxt) {
			ll v = e[i].v;
			if(!vis[v][c]) {
				res = v;
				dis[v][c] = dis[u][c] + 1;
				vis[v][c] = 1;
				from[v][c] = u;
				Q.push(v);
			}
		}
	}
	return res;
}
void dfs(ll u, ll f, ll rt, ll ds) {
	for(ll i=h[u];i;i=e[i].nxt) {
		ll v = e[i].v;
		if(v != f && !on_diameter[v]) {
			d[rt].push_back(ds+1);
			dfs(v, u, rt, ds+1);
		}
	}
}
void back1(ll u) {
	while(u) {
		on_diameter[u] = 1;
		u = from[u][1];
	}
}
void back2(ll u, ll s) {
	ll now = 0;
	while(u) {
		ll ds = max(now, diameter[s]-now);
//		printf("=%lld,%lld\n", ds, diameter[s]);
		d[s].push_back(ds);
		dfs(u, 0, s, ds);
		++now;
		u = from[u][1];
	}
}
void calc(ll u, ll s) {
	ll v = 0;
	u = bfs(u, 0);
	v = bfs(u, 1);
	diameter[s] = dis[v][1];
//	printf("==%lld\n", dis[v][1]);
	back1(v); back2(v, s);
}

int main() {
	memset(dis, 0x3f, sizeof(dis));
	scanf("%lld%lld%lld", &n, &m, &q);
	init(n);
	rep(i, 1, m) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		add(u, v); merge(u, v);
	}
	rep(i, 1, n) {
		if(i == fa[i]) {
			rt[++tot] = i;
			calc(i, i);
		}
	}
	rep(i, 1, tot) {
		sort(d[rt[i]].begin(), d[rt[i]].end());
		s[rt[i]].push_back(0);
		rep(j, 1, sz[rt[i]]) {
			s[rt[i]].push_back(s[rt[i]][j-1]+d[rt[i]][j-1]);
//			printf("=%lld%c", s[rt[i]][j], " \n"[j==sz[rt[i]]]);
		}
	}
	while(q--) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		if(!check(u, v)) puts("-1");
		else {
			ll rtu = find(u), rtv = find(v);
			if(sz[rtu] > sz[rtv]) {
				swap(u, v);
				swap(rtu, rtv);
			}
			if(Ans[make_pair(rtu, rtv)]) {
				printf("%.8lf\n", Ans[make_pair(rtu, rtv)]);
				continue;
			}
			ll maxdm = max(diameter[rtu], diameter[rtv]) - 1;
			ll now = sz[rtu], ans = 0;
			rep(i, 0, now-1) {
				ll lim = maxdm - d[rtu][i];
				ll pos = lower_bound(d[rtv].begin(), d[rtv].end(), lim) - d[rtv].begin();
				ans += maxdm * pos + d[rtu][i] * (sz[rtv] - pos) + s[rtv][sz[rtv]] - s[rtv][pos];
//        		printf("%lld %lld %lld\n", pos, s[rtv][sz[rtv]]-s[rtv][pos], d[rtu][i]*(sz[rtv]-pos));
			}
//			Ans[make_pair(rtu, rtv)] = ans + sz[rtu] * sz[rtv];
			Ans[make_pair(rtu, rtv)] = 1.0 * ans / (1.0 * sz[rtu] * sz[rtv]) + 1.0;
			printf("%.7lf\n", Ans[make_pair(rtu, rtv)]);
		}
	}
	return 0;
}