#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
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

vector <long long> c;

inline void Prefix() {
	for (long long k = 1;k <= 100000;k++) c.push_back((2 * k + 1) * (2 * k + 1) + 1 >> 1);
}

int main() {
	Prefix();
	int t = qread();
	while (t--) {
		int n = qread();
		int ans = upper_bound(c.begin(), c.end(), n) - c.begin();
		printf("%d\n", ans);
	}
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}