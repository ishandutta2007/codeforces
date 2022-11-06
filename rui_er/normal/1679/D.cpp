// Problem: D. Toss a Coin to Your Graph...
// Contest: Codeforces - Codeforces Round #791 (Div. 2)
// URL: https://codeforces.com/contest/1679/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll n, m, k, a[N], b[N], dis[N], in[N];
vector<ll> e[N], et[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
bool check(ll M) {
	memset(dis, 0, sizeof(dis));
	memset(in, 0, sizeof(in));
	rep(i, 0, n) et[i].clear();
	queue<ll> q;
	rep(i, 1, n) {
		if(a[i] <= M) {
			et[0].push_back(i);
			++in[i];
		}
	}
	rep(u, 1, n) {
		if(a[u] <= M) {
			for(auto v : e[u]) {
				if(a[v] <= M) {
					et[u].push_back(v);
					++in[v];
				}
			}
		}
	}
	q.push(0);
	while(!q.empty()) {
		ll u = q.front(); q.pop();
		for(auto v : et[u]) {
			if(!--in[v]) {
				dis[v] = dis[u] + 1;
				q.push(v);
				if(dis[v] >= k) return 1;
			}
		}
	}
	rep(i, 1, n) if(in[i]) return 1;
	return 0;
}

int main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	rep(i, 1, n) scanf("%lld", &a[i]), b[i] = a[i];
	rep(i, 1, m) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		e[u].push_back(v);
	}
	sort(b+1, b+1+n);
	ll tot = unique(b+1, b+1+n) - b - 1;
	rep(i, 1, n) a[i] = lower_bound(b+1, b+1+tot, a[i]) - b;
	ll L = 1, R = tot + 1;
	while(L < R) {
		ll M = (L + R) >> 1;
		if(check(M)) R = M;
		else L = M + 1;
	}
	printf("%lld\n", L>tot?-1:b[L]);
	return 0;
}