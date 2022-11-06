//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e6+5, mod = 1e9+7;

int T, n, m, k, fac[N], fiv[N], inv2; // fac inv
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int qpow(int x, int y) {
	int ans = 1;
	for(;y;y>>=1,x=1LL*x*x%mod) if(y & 1) ans = 1LL * ans * x % mod;
	return ans;
}
int inv(int x) {return qpow(x, mod-2);}
void init(int lim) {
	fac[0] = fac[1] = fiv[0] = fiv[1] = 1;
	rep(i, 2, lim) {
		fac[i] = 1LL * fac[i-1] * i % mod;
		fiv[i] = 1LL * (mod - mod / i) * fiv[mod%i] % mod;
	}
	rep(i, 2, lim) fiv[i] = 1LL * fiv[i-1] * fiv[i] % mod;
}
int C(int x, int y) {return 1LL * fac[x] * fiv[y] % mod * fiv[x-y] % mod;}
int calc(int id) {
	int delta = 1LL * C(n, id-1) * k % mod; // comb && choose k
	delta = 1LL * delta * (m - id + 1) % mod; // so many ways
	delta = 1LL * delta * qpow(inv2, n-1) % mod; // so many layers
	return delta;
}

int main() {
	inv2 = inv(2);
	init(2000000);
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%d", &n, &m, &k);
		int ans = 0;
		rep(i, 1, m) ans = (ans + calc(i)) % mod;
		printf("%d\n", ans);
	}
	return 0;
}