// LUOGU_RID: 96705702
// Problem: CF340E Iahub and Permutations
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF340E
// Memory Limit: 250 MB
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
const ll N = 2e3+5, mod = 1e9+7;

ll n, a[N], dp[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	ll x = 0, y = 0;
	rep(i, 1, n) {
		if(a[i] == -1) ++x;
		else if(a[a[i]] == -1) ++y;
	}
	x -= y;
	ll fac = 1;
	rep(i, 2, y) fac = fac * i % mod;
	dp[0] = fac;
	dp[1] = fac * y % mod;
	rep(i, 2, x) dp[i] = ((i - 1) * (dp[i-1] + dp[i-2]) + y * dp[i-1]) % mod;
	printf("%lld\n", dp[x]);
	return 0;
}