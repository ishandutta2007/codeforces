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

int t, n, u, v, a[105];

inline void Read() {
	n = qread(); u = qread(); v = qread();
	for (int i = 1;i <= n;i++) a[i] = qread();
}

inline void Solve() {
	for (int i = 1;i < n;i++) {
		if (Abs(a[i] - a[i + 1]) >= 2) {
			puts("0");
			return;
		}
	}
	for (int i = 1;i < n;i++) {
		if (Abs(a[i] - a[i + 1]) == 1) {
			printf("%d\n", Min(u, v));
			return;
		}
	}
	printf("%d\n", v + Min(u, v));
}

int main() {
	int t = qread();
	while (t--) {
		Read();
		Solve();
	}
	#ifdef CFA_44
	while (1);
	#endif
	return 0;
}