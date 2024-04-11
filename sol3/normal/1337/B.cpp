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

int dp[35][35];

int main() {
	int t = qread();
	while (t--) {
		int x = qread(), n = qread(), m = qread();
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0] = x;
		for (register int i = 0;i <= n;i++) {
			for (register int j = (i == 0);j <= m;j++) {
				if (i) dp[i][j] = Min(dp[i][j], dp[i - 1][j] / 2 + 10);
				if (j) dp[i][j] = Min(dp[i][j], dp[i][j - 1] - 10);
			}
		}
		register int ans = 0x3f3f3f3f;
		for (register int i = 0;i <= n;i++) {
			for (register int j = 0;j <= m;j++) {
				ans = Min(ans, dp[i][j]);
			}
		}
		if (ans <= 0) puts("YES");
		else puts("NO");
	}
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}