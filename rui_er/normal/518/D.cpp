//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>//
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 2e3+5;

int n, t;
double p, dp[N][N];
double calc(double a, double b) {return p * a + (1 - p) * b;}

int main() {
	scanf("%d%lf%d", &n, &p, &t);
	rep(i, 1, n) rep(j, 1, t) dp[i][j] = calc(dp[i-1][j-1]+1, dp[i][j-1]);
	printf("%.7lf\n", dp[n][t]);
	return 0;
}