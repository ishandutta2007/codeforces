// LUOGU_RID: 91302181
// Problem: D. The Beach
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforc.es/contest/1753/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 3e5+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, m, s, p, q, dis[N], vis[N];
string mp[N];
vector<tuple<ll, ll> > e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll id(ll x, ll y) {return x * m + y + 1;}
void dijkstra(ll s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<tuple<ll, ll> > q;
	dis[s] = 0;
	q.emplace(0, s);
	while(!q.empty()) {
		ll u = get<1>(q.top()); q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto i : e[u]) {
			ll v = get<0>(i), w = get<1>(i);
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.emplace(-dis[v], v);
			}
		}
	}
}

int main() {
	scanf("%lld%lld%lld%lld", &n, &m, &p, &q);
	s = n * m + 1;
	rep(i, 0, n-1) cin >> mp[i];
	rep(i, 0, n-1) {
		rep(j, 0, m-1) {
			ll u = id(i, j);
			if(mp[i][j] == '.') e[s].emplace_back(u, 0);
			else if(mp[i][j] == 'L') {
				if(i > 0 && j < m - 1) e[id(i-1, j+1)].emplace_back(u, p);
				if(j < m - 2) e[id(i, j+2)].emplace_back(u, q);
				if(i < n - 1 && j < m - 1) e[id(i+1, j+1)].emplace_back(u, p);
			}
			else if(mp[i][j] == 'R') {
				if(i > 0 && j > 0) e[id(i-1, j-1)].emplace_back(u, p);
				if(j > 1) e[id(i, j-2)].emplace_back(u, q);
				if(i < n - 1 && j > 0) e[id(i+1, j-1)].emplace_back(u, p);
			}
			else if(mp[i][j] == 'U') {
				if(i < n - 1 && j > 0) e[id(i+1, j-1)].emplace_back(u, p);
				if(i < n - 2) e[id(i+2, j)].emplace_back(u, q);
				if(i < n - 1 && j < m - 1) e[id(i+1, j+1)].emplace_back(u, p);
			}
			else if(mp[i][j] == 'D') {
				if(i > 0 && j > 0) e[id(i-1, j-1)].emplace_back(u, p);
				if(i > 1) e[id(i-2, j)].emplace_back(u, q);
				if(i > 0 && j < m - 1) e[id(i-1, j+1)].emplace_back(u, p);
			}
		}
	}
	dijkstra(s);
	ll ans = inf;
	rep(i, 0, n-1) {
		rep(j, 0, m-1) {
			if(i < n - 1) chkmin(ans, dis[id(i, j)] + dis[id(i+1, j)]);
			if(j < m - 1) chkmin(ans, dis[id(i, j)] + dis[id(i, j+1)]);
		}
	}
	printf("%lld\n", ans == inf ? -1LL : ans);
	return 0;
}