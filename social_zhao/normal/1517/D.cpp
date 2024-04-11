#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
const ll MAXN = 511;

ll n, m, k;
ll vis[MAXN][MAXN][25];
ll mpx[MAXN][MAXN], mpy[MAXN][MAXN];

ll read() {
	ll X = 0, F = 1; char C = getchar();
	while(C < '0' || C > '9') {if(C == '-')F=-1; C = getchar();}
	while(C >= '0' && C <= '9') {X = X*10+C-'0'; C = getchar();}
	return X * F;
}

ll solve(ll x, ll y, ll k) {
	if(!k) return 0;
	if(vis[x][y][k]) return vis[x][y][k];
	ll ans = 114514191;
	if(x < n) ans = min(ans, solve(x + 1, y, k - 2) + mpx[x][y] * 2);
	if(y < m) ans = min(ans, solve(x, y + 1, k - 2) + mpy[x][y] * 2);
	if(x > 1) ans = min(ans, solve(x - 1, y, k - 2) + mpx[x-1][y] * 2);
	if(y > 1) ans = min(ans, solve(x, y - 1, k - 2) + mpy[x][y-1] * 2);
	return vis[x][y][k] = ans;
}

int main() {
	n = read(); m = read(); k = read();
	for(ll i = 1; i <= n; ++i)
		for(ll j = 1; j < m; ++j)
			mpy[i][j] = read();
	for(ll i = 1; i < n; ++i)
		for(ll j = 1; j <= m; ++j)
			mpx[i][j] = read();
	for(ll i = 1; i <= n; ++i) {
		for(ll j = 1; j <= m; ++j) {
			if(k&1) printf("-1 ");
			else printf("%lld ", solve(i, j, k));
		}
		puts("");
	}
	return 0;
}