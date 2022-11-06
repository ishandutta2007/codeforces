//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 505;

int n, a[N], dp[N][N]; 

int main() {
	fil(dp, 0x3f);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) dp[i][i] = 1;
	rep(i, 1, n-1) {
		if(a[i] == a[i+1]) dp[i][i+1] = 1;
		else dp[i][i+1] = 2;
	}
	rep(delta, 2, n-1) {
		rep(L, 1, n) {
			int R = L + delta;
			if(R > n) break;
			if(a[L] == a[R]) dp[L][R] = dp[L+1][R-1];
			rep(M, L, R-1) dp[L][R] = min(dp[L][R], dp[L][M]+dp[M+1][R]);
		}
	}
	printf("%d\n", dp[1][n]);
    return 0;
}