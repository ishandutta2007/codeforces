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

int t, n, a[105];

int main() {
	t = qread();
	while (t--) {
		n = qread();
		int minv = 10005;
		for (int i = 1;i <= n;i++) minv = Min(minv, a[i] = qread());
		int ans = 0;
		for (int i = 1;i <= n;i++) {
			if (a[i] != minv) ans++;
		}
		printf("%d\n", ans);
	}
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}