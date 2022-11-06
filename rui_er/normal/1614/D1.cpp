//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e5+5, K = 5e6+5, W = 5e6;

ll n, a[N], buc[K], s[K], dp[K];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		++buc[a[i]];
	}
	rep(i, 1, W) for(ll j=i;j<=W;j+=i) s[i] += buc[j];
	per(i, W, 1) {
		for(ll j=2*i;j<=W;j+=i) chkmax(dp[i], dp[j]-s[j]*i);
		dp[i] += s[i] * i;
	}
	printf("%lld\n", dp[1]);
    return 0;
}