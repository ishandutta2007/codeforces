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

int n, m, x, y;
char mp[105][1005];

inline void Read() {
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (register int i = 1;i <= n;i++) {
		for (register int j = 1;j <= m;j++) scanf(" %c", &mp[i][j]);
	}
}

inline void Solve() {
	if (x * 2 <= y) {
		register int ans = 0;
		for (register int i = 1;i <= n;i++) {
			for (register int j = 1;j <= m;j++) {
				if (mp[i][j] == '.') ans += x;
			}
		}
		printf("%d\n", ans);
		return;
	}
	register int ans = 0;
	for (register int i = 1;i <= n;i++) {
		register int j = 1;
		while (j <= m) {
			while (j <= m && mp[i][j] == '*') j++;
			if (j > m) break;
			register int l = j;
			while (j <= m && mp[i][j] == '.') j++;
			ans += y * (j - l >> 1) + x * (j - l & 1);
		}
	}
	printf("%d\n", ans);
}

int main() {
	register int t;
	scanf("%d", &t);
	while (t--) {
		Read();
		Solve();
	}
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}