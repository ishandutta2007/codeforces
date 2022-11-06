//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 1005;

int n, a[N][N][2], dp[N][N][2][2], zero;

int main() {
	fil(dp, 0x3f);
	scanf("%d", &n);
	rep(i, 1, n) {
		rep(j, 1, n) {
			int _; scanf("%d", &_);
			if(!_) {
				a[i][j][0] = a[i][j][1] = 1;
				if(!zero) zero = i;
			}
			else {
				while(!(_%2)) ++a[i][j][0], _ /= 2;
				while(!(_%5)) ++a[i][j][1], _ /= 5;
			}
			if(i == 1 && j == 1) dp[i][j][0][0] = a[i][j][0], dp[i][j][1][0] = a[i][j][1];
		}
	}
	rep(k, 0, 1) rep(i, 1, n) rep(j, 1, n) if(i != 1 || j != 1) {
		dp[i][j][k][0] = min(dp[i-1][j][k][0], dp[i][j-1][k][0]) + a[i][j][k];
		dp[i][j][k][1] = (dp[i-1][j][k][0] < dp[i][j-1][k][0]);
	}
	int ans = min(dp[n][n][0][0], dp[n][n][1][0]);
	int type = dp[n][n][0][0] < dp[n][n][1][0] ? 0 : 1;
/*	rep(k, 0, 1) {
		rep(i, 1, n) {
			rep(j, 1, n) {
				printf("%d", dp[i][j][k][0]);
				putchar(dp[i][j][k][1]==1?'D':(dp[i][j][k][1]==0?'R':'Q'));
			}
			puts("");
		}
		puts("");
	}*/
//	printf("ans=%d type=%d\n", ans, type);
	if(zero && ans > 1) {
		puts("1");
		rep(i, 1, zero-1) putchar('D');
		rep(i, 1, n-1) putchar('R');
		rep(i, zero, n-1) putchar('D');
		puts("");
	}
	else {
		printf("%d\n", ans);
		stack<char> qwq;
		int i = n, j = n;
		while(i != 1 && j != 1) {
//			printf("i=%d j=%d tmp=%d\n", i, j, dp[i][j][type][1]);
			if(dp[i][j][type][1]) {qwq.push('D'); --i;}
			else {qwq.push('R'); --j;}
		}
		while(i-- != 1) qwq.push('D');
		while(j-- != 1) qwq.push('R');
		while(!qwq.empty()) {putchar(qwq.top()); qwq.pop();}
		puts("");
	}
	return 0;
}