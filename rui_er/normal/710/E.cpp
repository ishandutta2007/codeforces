//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e7+5;

ll n, x, y, dp[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld%lld", &n, &x, &y);
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	rep(i, 1, n) {
		dp[i] = dp[i-1] + x;
		if(i & 1) chkmin(dp[i], dp[i/2+1]+x+y);
		else chkmin(dp[i], dp[i/2]+y);
	}
	printf("%lld\n", dp[n]);
	return 0;
}