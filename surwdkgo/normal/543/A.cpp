#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif
int inp[510];
int dp[2][510][510];
int n, m, b, mod;
void lemon() {  
	scanf("%d%d%d%d", &n, &m, &b, &mod);
	rep(i,0,n-1) scanf("%d", &inp[i]);
	dp[0][0][0] = 1;
	rep(i,0,n-1) {
		int ci = i%2;
		int ri = 1-ci;
		memset(dp[ri], 0, sizeof(dp[ri]));
		rep(j,0,m) {
			rep(k,0,b) {
				dp[ri][j][k] += dp[ci][j][k];
				dp[ri][j][k] %= mod;
				if (k+inp[i] <= b) {
					dp[ci][j+1][k+inp[i]] += dp[ci][j][k];
					dp[ci][j+1][k+inp[i]] %= mod;
				}
			}
		}
	}
	int ans = 0;
	int ci = n%2;
		rep(k,0,b) ans = (ans + dp[ci][m][k]) % mod;
	printf("%d\n", ans % mod);

}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
  //  freopen("","r",stdin);
  #endif
  lemon();
  return 0;
}