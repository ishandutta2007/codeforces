//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 25;

ll n, m, k, a[N][N], ans;
map<ll, ll> mp[N][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs1(ll x, ll y, ll now) {
	if(x + y == (n + m) / 2 + 1) {
		++mp[x][y][now];
		return;
	}
	if(x < n) dfs1(x+1, y, now^a[x][y]);
	if(y < m) dfs1(x, y+1, now^a[x][y]);
}
void dfs2(ll x, ll y, ll now) {
	if(x + y == (n + m) / 2 + 1) {
		ans += mp[x][y][now^k^a[x][y]];
		return;
	}
	if(x > 1) dfs2(x-1, y, now^a[x][y]);
	if(y > 1) dfs2(x, y-1, now^a[x][y]);
}

int main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	rep(i, 1, n) rep(j, 1, m) scanf("%lld", &a[i][j]);
	dfs1(1, 1, 0); dfs2(n, m, 0);
	printf("%lld\n", ans);
	return 0;
}