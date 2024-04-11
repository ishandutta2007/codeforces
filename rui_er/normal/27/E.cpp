//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
const ll pm[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

ll n, ans = inf;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(ll u, ll now, ll lst, ll div) {
	if(div > n || u >= 16) return;
	if(div == n) {
		chkmin(ans, now);
		return;
	}
	rep(i, 1, lst) {
		now *= pm[u];
		if(now > ans) break;
		dfs(u+1, now, i, div*(i+1));
	}
}

int main() {
	scanf("%lld", &n);
	dfs(0, 1, 63, 1);
	printf("%lld\n", ans);
    return 0;
}