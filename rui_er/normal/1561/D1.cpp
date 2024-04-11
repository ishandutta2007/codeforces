//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 5e6+5;

ll n, mod, dp[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &n, &mod);
	rep(i, 1, n) {
		dp[i] = (dp[i] + dp[i-1]) % mod;
		ll diff = (i == 1) ? 1 : dp[i];
		dp[i+1] = (dp[i+1] + diff) % mod;
		for(ll j=2,k=2*i;k<=n;j++,k+=i) {
			dp[k] = (dp[k] + diff) % mod;
			if(k + j <= n) dp[k+j] = (dp[k+j] + mod - diff) % mod; 
		}
	}
	printf("%lld\n", dp[n]%mod);
	return 0;
}