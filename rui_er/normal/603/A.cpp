//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, dp[N][3];
char s[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	/*
	 * 0 for x...[...]
	 * 1 for [...]...x
	 * 2 for [...x...]
	**/
	scanf("%d%s", &n, s+1);
	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	rep(i, 2, n) {
		if(s[i] == s[i-1]) {
			dp[i][0] = dp[i-1][0];
			dp[i][1] = max(dp[i-1][1], dp[i-1][2]+1);
			dp[i][2] = max(dp[i-1][0]+1, dp[i-1][2]);
		}
		else {
			dp[i][0] = dp[i-1][0] + 1;
			dp[i][1] = max(dp[i-1][1]+1, dp[i-1][2]);
			dp[i][2] = max(dp[i-1][0], dp[i-1][2]+1);
		}
	}
	int ans = max(max(dp[n][0], dp[n][1]), dp[n][2]);
	printf("%d\n", ans);
	return 0;
}