//By: Luogu@rui_er(122461)
//BA
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 2e5+5, inf = 0x3f3f3f3f;

int n, a[N], dp[N][2], save[N][2], col[N];
template<typename T> void chkmin(T &x, T &sv, T y, T from) {
	if(y != -1 && (x == -1 || x > y)) {
		x = y;
		sv = from;
	}
}
template<typename T> void chkmax(T &x, T &sv, T y, T from) {
	if(y != -1 && (x == -1 || x < y)) {
		x = y;
		sv = from;
	}
}

int main() {
	while(scanf("%d", &n) == 1) {
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) dp[i][0] = dp[i][1] = save[i][0] = save[i][1] = col[i] = -1;
		dp[1][0] = inf;
		dp[1][1] = -inf;
		rep(i, 1, n) {
			if(a[i+1] > a[i]) chkmax(dp[i+1][0], save[i+1][0], dp[i][0], 0);
			if(dp[i][0] != -1 && a[i+1] < dp[i][0]) chkmin(dp[i+1][1], save[i+1][1], a[i], 0);
			if(a[i+1] < a[i]) chkmin(dp[i+1][1], save[i+1][1], dp[i][1], 1);
			if(dp[i][1] != -1 && a[i+1] > dp[i][1]) chkmax(dp[i+1][0], save[i+1][0], a[i], 1);
		}
//		rep(i, 1, n) printf("%d %d\n", dp[i][0], dp[i][1]);
		if(dp[n][0] == -1 && dp[n][1] == -1) puts("NO");
		else {
			puts("YES");
			int now = dp[n][0] != -1 ? 0 : 1;
			per(i, n, 1) {
				col[i] = now;
				now = save[i][now];
			}
			rep(i, 1, n) printf("%d%c", col[i], " \n"[i==n]);
		}
	}
	return 0;
}