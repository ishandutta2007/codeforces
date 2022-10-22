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

#define left jdifodzxnflnasld

int n, m, up[2005][2005], down[2005][2005], left[2005][2005], mlr[2005][2005], mlrup[2005][2005], mlrdown[2005][2005];
char c[2005][2005];

inline void Read() {
	n = qread(); m = qread();
	for (register int i = 1;i <= n;i++) {
		for (register int j = 1;j <= m;j++) {
			c[i][j] = getchar();
			while (c[i][j] < 'a' || c[i][j] > 'z') c[i][j] = getchar();
		}
	}
}

inline void Prefix() {
	for (register int i = 1;i <= n;i++) {
		for (register int j = 1;j <= m;j++) {
			if (c[i][j] == c[i][j - 1]) left[i][j] = left[i][j - 1] + 1;
			else left[i][j] = 1;
			if (c[i][j] == c[i - 1][j]) up[i][j] = up[i - 1][j] + 1;
			else up[i][j] = 1;
		}
	}
	for (register int i = n;i >= 1;i--) {
		for (register int j = m;j >= 1;j--) {
			if (c[i][j] == c[i][j + 1]) mlr[i][j] = mlr[i][j + 1] + 1;
			else mlr[i][j] = 1;
			mlr[i][j] = Min(mlr[i][j], left[i][j]);
			if (c[i][j] == c[i + 1][j]) down[i][j] = down[i + 1][j] + 1;
			else down[i][j] = 1;
		}
	}
	for (register int i = 1;i <= n;i++) {
		for (register int j = 1;j <= m;j++) {
			if (c[i][j] != c[i - 1][j]) mlrup[i][j] = 1;
			else mlrup[i][j] = Min(mlrup[i - 1][j] + 1, mlr[i][j]);
		}
	}
	for (register int i = n;i >= 1;i--) {
		for (register int j = 1;j <= m;j++) {
			if (c[i][j] != c[i + 1][j]) mlrdown[i][j] = 1;
			else mlrdown[i][j] = Min(mlrdown[i + 1][j] + 1, mlr[i][j]);
		}
	}
}

inline void Solve() {
	register long long ans = 0;
	for (register int i = 1;i <= n;i++) {
		for (register int j = 1;j <= m;j++) {
			ans += 1ll * Min(mlrup[i][j], mlrdown[i][j]);
		}
	}
	printf("%lld\n", ans);
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