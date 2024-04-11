// Problem: CF809A Do you want a date?
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF809A
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 3e5+5, mod = 1e9+7;

ll n, a[N], pw[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	sort(a+1, a+1+n);
	pw[0] = 1;
	rep(i, 1, n) pw[i] = 2 * pw[i-1] % mod;
	rep(i, 1, n) ans = (ans + (pw[i-1] - pw[n-i] + mod) % mod * a[i] % mod) % mod;
	printf("%lld\n", ans);
	return 0;
}