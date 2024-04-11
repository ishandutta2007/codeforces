#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
	register char c = getchar();
	register int x = 0, f = 1;
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	return x * f;
}

inline int Abs(const int& x) {return (x > 0 ? x : -x);}
inline int Max(const int& x, const int& y) {return (x > y ? x : y);}
inline int Min(const int& x, const int& y) {return (x < y ? x : y);}

const long long mod = 998244353;
int n, c[30];
long long dp[2][405][405][3][3], ans[405][405];

inline void Read() {
	n = qread();
	for (int i = 1;i <= 26;i++) c[i] = qread();
}

inline void Trans(long long &x, long long y) {x = (x + y >= mod ? x + y - mod : x + y);}

inline void Prefix() {
	dp[1][0][0][0][2] = 24;
	dp[1][0][1][0][1] = 1;
	dp[1][1][0][0][0] = 1;
	for (int i = 2;i <= 2;i++) {
		memset(dp[i & 1], 0, sizeof(dp[i & 1]));
		for (int j = 0;j <= n;j++) {
			for (int k = 0;k <= n;k++) {
				if (j) {
					for (int l = 0;l < 3;l++) {
						Trans(dp[i & 1][j][k][l][0], dp[i - 1 & 1][j - 1][k][0][l]);
						Trans(dp[i & 1][j][k][l][0], dp[i - 1 & 1][j - 1][k][1][l]);
						Trans(dp[i & 1][j][k][l][0], dp[i - 1 & 1][j - 1][k][2][l]);
					}
				}
				if (k) {
					for (int l = 0;l < 3;l++) {
						Trans(dp[i & 1][j][k][l][1], dp[i - 1 & 1][j][k - 1][0][l]);
						Trans(dp[i & 1][j][k][l][1], dp[i - 1 & 1][j][k - 1][1][l]);
						Trans(dp[i & 1][j][k][l][1], dp[i - 1 & 1][j][k - 1][2][l]);
					}
				}
				for (int l = 0;l < 3;l++) {
					Trans(dp[i & 1][j][k][l][2], dp[i - 1 & 1][j][k][0][l] * 24 % mod);
					Trans(dp[i & 1][j][k][l][2], dp[i - 1 & 1][j][k][1][l] * 24 % mod);
					Trans(dp[i & 1][j][k][l][2], dp[i - 1 & 1][j][k][2][l] * 24 % mod);
				}
			}
		}
	}
	for (int i = 3;i <= n;i++) {
		memset(dp[i & 1], 0, sizeof(dp[i & 1]));
		for (int j = 0;j <= n;j++) {
			for (int k = 0;k <= n;k++) {
				if (j) {
					for (int l = 0;l < 3;l++) {
						Trans(dp[i & 1][j][k][l][0], dp[i - 1 & 1][j - 1][k][1][l]);
						Trans(dp[i & 1][j][k][l][0], dp[i - 1 & 1][j - 1][k][2][l]);
					}
				}
				if (k) {
					for (int l = 0;l < 3;l++) {
						Trans(dp[i & 1][j][k][l][1], dp[i - 1 & 1][j][k - 1][0][l]);
						Trans(dp[i & 1][j][k][l][1], dp[i - 1 & 1][j][k - 1][2][l]);
					}
				}
				for (int l = 0;l < 3;l++) {
					Trans(dp[i & 1][j][k][l][2], dp[i - 1 & 1][j][k][0][l] * 24 % mod);
					Trans(dp[i & 1][j][k][l][2], dp[i - 1 & 1][j][k][1][l] * 24 % mod);
					Trans(dp[i & 1][j][k][l][2], dp[i - 1 & 1][j][k][2][l] * 23 % mod);
				}
			}
		}
	}
	for (int j = 0;j <= n;j++) {
		for (int k = 0;k <= n;k++) {
			for (int l = 0;l < 3;l++) {
				for (int m = 0;m < 3;m++) Trans(ans[j][k], dp[n & 1][j][k][l][m]);
			}
			//printf("%lld ", ans[j][k]);
		}
		//puts("");
	}
	for (int j = n;j >= 0;j--) {
		for (int k = n;k >= 0;k--) Trans(ans[j][k], (ans[j][k + 1] + ans[j + 1][k] - ans[j + 1][k + 1] + mod) % mod);
	}
}

inline void Solve() {
	long long res = ans[0][0];
	//printf("%lld\n", res);
	for (int i = 1;i <= 26;i++) {
		//printf("%lld ", ans[c[i] + 1][0]);
		res = (res - ans[c[i] + 1][0] + mod) % mod;
	}
	//puts("");
	for (int i = 1;i <= 26;i++) {
		for (int j = i + 1;j <= 26;j++) Trans(res, ans[c[i] + 1][c[j] + 1]);
	}
	printf("%lld", res);
}

int main() {
	Read();
	Prefix();
	Solve();
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}