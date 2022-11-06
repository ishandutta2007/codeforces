//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 7e6+5, mod = 1e9+7;

ll n, q, fac[N], inv[N], facinv[N], ans[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
void initC(ll lim) {
	fac[0] = inv[0] = facinv[0] = 1;
	fac[1] = inv[1] = facinv[1] = 1;
	rep(i, 2, lim) {
		fac[i] = fac[i-1] * i % mod;
		inv[i] = (mod - mod / i) * inv[mod%i] % mod;
		facinv[i] = (mod - mod / i) * facinv[mod%i] % mod;
	}
	rep(i, 2, lim) facinv[i] = facinv[i-1] * facinv[i] % mod;
}

int main() {
	scanf("%lld", &n);
	initC(3*n+1);
	ll qwq = 0, qaq = 0;
	qwq = (3 * n - 1) % mod * n % mod * inv[2] % mod;
	qaq = (3 * n + 1) % mod * n % mod * inv[2] % mod;
	ans[1] = (3 * n + 3) % mod * n % mod * inv[2] % mod;
	rep(i, 2, 3*n) {
		ll diff1 = qwq * i % mod;
		ll diff2 = qaq * i % mod;
		ll total = fac[3*n+1] * facinv[3*n-i] % mod * inv[i+1] % mod;
		ll tmp = (2 * diff1 % mod + diff2) % mod;
		qwq = (total + mod - tmp) % mod * inv[3] % mod;
		qaq = (qwq + diff1) % mod;
		ans[i] = (qaq + diff2) % mod * facinv[i] % mod;
	}
	for(scanf("%lld", &q);q;q--) {
		ll x;
		scanf("%lld", &x);
		printf("%lld\n", ans[x]);
	}
	return 0;
}
// sum{C(3i, x)}
// x=2:
// 3*2+6*5+8*7+...
// x=3:
// 3*2*1+6*5*4+9*8*7+...
// 4*3*2+7*6*5+10*9*8...
// 5*4*3+8*7*6+11*10*9...
// x=4:
// 3*2*1*0+6*5*4*3+9*8*7*6+...
// 4*3*2*1+7*6*5*4+10*9*8*7+...
// 5*4*3*2+8*7*6*5+11*10*9*8+...

// [(2){i}-(1){i}]/p => (1){i-1}