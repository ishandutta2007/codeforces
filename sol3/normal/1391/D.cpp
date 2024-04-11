#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1 << 21], *p1 = buf, *p2 = buf;

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

int n, m, dp[1000005][8], popcnt[8] = {0, 1, 1, 2, 1, 2, 2, 3};
char s[4][1000005];

inline void Solve() {
	for (register int i = 1;i <= n;i++) {
		for (register int j = 1;j <= m;j++) scanf(" %c", &s[i][j]);
	}
	if (n == 1) {
		puts("0");
		return;
	}
	memset(dp, 0x3f, sizeof(dp));
	for (register int i = 0;i < (1 << n);i++) dp[1][i] = popcnt[i];
	for (register int i = 2;i <= m;i++) {
		for (register int j = 0;j < (1 << n);j++) {
			for (register int k = 0;k < (1 << n);k++) {
				register int cnt1 = 0, cnt2 = 0;
				for (register int l = 1;l <= n;l++) {
					if (l <= 2) cnt1 += ((s[l][i - 1] - '0') ^ ((k >> (l - 1)) & 1)) + ((s[l][i] - '0') ^ ((j >> (l - 1)) & 1));
					if (l >= 2) cnt2 += ((s[l][i - 1] - '0') ^ ((k >> (l - 1)) & 1)) + ((s[l][i] - '0') ^ ((j >> (l - 1)) & 1));
				}
				if (n == 2 && (cnt1 & 1)) dp[i][j] = Min(dp[i - 1][k] + popcnt[j], dp[i][j]);
				if (n == 3 && (cnt1 & 1) && (cnt2 & 1)) dp[i][j] = Min(dp[i - 1][k] + popcnt[j], dp[i][j]);
			}
		}
	}
	register int ans = 0x3f3f3f3f;
	for (register int i = 0;i < (1 << n);i++) ans = Min(ans, dp[m][i]);
	printf("%d", ans);
}

int main() {
	scanf("%d%d", &n, &m);
	if (n >= 4) puts("-1");
	else Solve();
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}