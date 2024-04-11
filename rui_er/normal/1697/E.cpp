// Problem: E. Coloring
// Contest: Codeforces - Educational Codeforces Round 130 (Rated for Div. 2)
// URL: https://codeforc.es/contest/1697/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 205, mod = 998244353;

ll n, x[N], y[N], fac[N], inv[N], bel[N], ok[N], sz[N], dp[N][N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void init() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	rep(i, 2, N-1) {
		fac[i] = fac[i-1] * i % mod;
		inv[i] = (mod - mod / i) * inv[mod%i] % mod;
	}
	rep(i, 2, N-1) inv[i] = inv[i-1] * inv[i] % mod;
}
ll C(ll n, ll m) {
	if(n < 0 || m < 0 || n < m) return 0;
	return fac[n] * inv[m] % mod * inv[n-m] % mod;
}
ll A(ll n, ll m) {
	if(n < 0 || m < 0 || n < m) return 0;
	return fac[n] * inv[n-m] % mod;
}
ll dis(ll i, ll j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main() {
	init();
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld%lld", &x[i], &y[i]);
	ll rem = n, blk = 0;
	rep(i, 1, n) {
		rep(j, i+1, n) {
			if(!bel[i] && !bel[j]) {
				ll d = dis(i, j), cnt = 2;
				rep(k, 1, n) ok[k] = (k == i || k == j);
				rep(k, 1, n) {
					if(!bel[k]) {
						if(dis(i, k) == d && dis(j, k) == d) {
							ok[k] = 1;
							++cnt;
						}
					}
				}
				rep(k, 1, n) {
					if(ok[k]) {
						rep(l, 1, n) {
							if(k == l) continue;
							if(!ok[l] && dis(k, l) <= d || ok[l] && dis(k, l) != d) {
								goto skip; // can't same
							}
						}
					}
				}
				rep(k, 1, n) bel[k] |= ok[k];
				sz[++blk] = cnt;
				rem -= cnt;
				skip:;
			}
		}
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	rep(i, 1, blk) {
		rep(j, 1, n) {
			dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
			if(j >= sz[i]) dp[i][j] = (dp[i][j] + dp[i-1][j-sz[i]]) % mod;
		}
	}
	rep(i, 0, n-rem) ans = (ans + A(n, i+rem) * dp[blk][i] % mod) % mod;
	printf("%lld\n", ans);
	return 0;
}