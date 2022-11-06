// LUOGU_RID: 91302159
// Problem: C. Wish I Knew How to Sort
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforc.es/contest/1753/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const ll N = 2e5+5, mod = 998244353;

ll T, n, a[N], b[N], inv[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	inv[0] = inv[1] = 1;
	rep(i, 2, N-1) inv[i] = (mod - mod / i) * inv[mod%i] % mod;
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		ll cnt0 = 0, diff = 0, ans = 0;
		rep(i, 1, n) cnt0 += !a[i];
		rep(i, 1, cnt0) b[i] = 0;
		rep(i, cnt0+1, n) b[i] = 1;
		rep(i, 1, n) if(a[i] != b[i]) ++diff;
		rep(i, 1, diff/2) {
			ans += n * (n - 1) / 2 % mod * inv[i] % mod * inv[i] % mod;
			ans %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}