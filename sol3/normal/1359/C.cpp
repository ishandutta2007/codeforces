#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

#define int long long

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

int c, h, t;

signed main() {
	register int tc = qread();
	while (tc--) {
		h = qread(); c = qread(); t = qread();
		if ((c + h) / 2.0 >= 1.0 * t) {
			puts("2");
			continue;
		}
		register int l = 1, r = 1e12;
		while (l < r - 1) {
			register int mid = l + r >> 1;
			if ((double)((mid - 1) * c + mid * h) / (double)(2 * mid - 1) < 1.0 * t) r = mid;
			else l = mid;
		}
		double v1 = (double)((r - 1) * c + r * h) / (double)(2 * r - 1);
		double v2 = (double)((r - 2) * c + (r - 1) * h) / (double)(2 * r - 3);
		if (v2 - t <= t - v1) printf("%lld\n", 2 * r - 3);
		else printf("%lld\n", 2 * r - 1);
	}
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}