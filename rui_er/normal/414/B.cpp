//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2005, mod = 1e9+7;

ll n, k;
ll dp[N], tmp[N], ans;

int main() {
	scanf("%lld%lld", &n, &k);
	for(ll i=1;i<=n;i++) dp[i] = 1;
	for(ll cnts=2;cnts<=k;cnts++) {
		for(ll i=1;i<=n;i++) tmp[i] = 0;
		for(ll i=1;i<=n;i++) {
			for(ll j=1,_=i*j;_<=n;j++,_=i*j) tmp[_] = (tmp[_] + dp[i]) % mod;
		}
		for(ll i=1;i<=n;i++) dp[i] = tmp[i];
	}
	for(ll i=1;i<=n;i++) ans = (ans + dp[i]) % mod;
	printf("%lld\n", ans);
	return 0;
}