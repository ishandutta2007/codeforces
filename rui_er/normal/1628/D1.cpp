//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e3+5, mod = 1e9+7;

int T, n, m, k, dp[N][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int qpow(int x, int y) {
	int ans = 1;
	for(;y;y>>=1,x=1LL*x*x%mod) if(y & 1) ans = 1LL * ans * x % mod;
	return ans;
}
int inv(int x) {return qpow(x, mod-2);}

int main() {
	int inv2 = inv(2);
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%d", &n, &m, &k);
		rep(i, 1, n) {
			dp[i][i] = 1LL * i * k % mod;
			per(j, min(i-1, m), 1) {
				dp[i][j] = 1LL * (dp[i-1][j-1] + dp[i-1][j]) % mod * inv2 % mod; 
			}
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}