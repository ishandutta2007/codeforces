// LUOGU_RID: 91994389
// Problem: CF1637D Yet Another Minimization Problem
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1637D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 105, K = 2e4+5, inf = 0x3f3f3f3f;

int T, n, a[N], b[N], s[N], dp[N][K];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) scanf("%d", &b[i]);
		int ans = 0;
		rep(i, 1, n) ans += (n - 1) * a[i] * a[i];
		rep(i, 1, n) ans += (n - 1) * b[i] * b[i];
		rep(i, 1, n) s[i] = s[i-1] + a[i] + b[i];
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0] = 0;
		rep(i, 1, n) {
			rep(j, 0, s[i-1]) {
				chkmin(dp[i][j+a[i]], dp[i-1][j] + a[i] * j + b[i] * (s[i-1] - j));
				chkmin(dp[i][j+b[i]], dp[i-1][j] + a[i] * (s[i-1] - j) + b[i] * j);
			}
		}
		int now = inf;
		rep(j, 1, K-1) chkmin(now, dp[n][j]);
		printf("%d\n", ans + 2 * now);
	}
	return 0;
}