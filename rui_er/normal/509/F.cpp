//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 505, mod = 1e9+7;

ll n, a[N], dp[N][N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) dp[i][i] = 1;
	rep(delta, 1, n-1) {
		rep(l, 1, n) {
			int r = l + delta;
			if(r > n) break;
			rep(k, l+1, r) {
				if(k == r || a[k+1] >= a[l+1]) {
					dp[l][r] = (dp[l][r] + dp[l+1][k] * dp[k][r] % mod) % mod;
				}
			}
		}
	}
	printf("%lld\n", dp[1][n]);
	return 0;
}