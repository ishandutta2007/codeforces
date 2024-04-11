// LUOGU_RID: 96194970
// Problem: CF630H Benches
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF630H
// Memory Limit: 62 MB
// Time Limit: 500 ms
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
const ll N = 105;

ll n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll C(ll x, ll y) {
	if(x < 0 || y < 0 || x < y) return 0;
	ll ans = 1;
	rep(i, x-y+1, x) ans *= i;
	rep(i, 1, y) ans /= i;
	return ans;
}
ll A(ll x, ll y) {
	if(x < 0 || y < 0 || x < y) return 0;
	ll ans = 1;
	rep(i, x-y+1, x) ans *= i;
	return ans;
}

int main() {
	scanf("%lld", &n);
	printf("%lld\n", C(n, 5) * A(n, 5));
	return 0;
}