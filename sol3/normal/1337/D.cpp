#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline long long qread() {
	register char c = getchar();
	register long long x = 0, f = 1;
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

inline long long Abs(const long long& x) {return (x > 0 ? x : -x);}
inline long long Max(const long long& x, const long long& y) {return (x > y ? x : y);}
inline long long Min(const long long& x, const long long& y) {return (x < y ? x : y);}

int n[3];
long long a[3][100005];

inline void Read() {
	n[0] = qread(); n[1] = qread(); n[2] = qread();
	for (register int i = 0;i < 3;i++) {
		for (register int j = 1;j <= n[i];j++) a[i][j] = qread();
		sort(a[i] + 1, a[i] + n[i] + 1);
	}
}

inline int Lower(int idx, long long x) {
	register int l = 0, r = n[idx] + 1;
	while (l < r - 1) {
		register int mid = l + r >> 1;
		if (a[idx][mid] > x) r = mid;
		else l = mid;
	}
	return l;
}

inline int Upper(int idx, long long x) {
	register int l = 0, r = n[idx] + 1;
	while (l < r - 1) {
		register int mid = l + r >> 1;
		if (a[idx][mid] < x) l = mid;
		else r = mid;
	}
	return r;
}

inline long long sqr(long long x) {return x * x;}

inline long long Solve(int l, int m, int r) {
	l--; m--; r--;
	register long long ans = 0x3f3f3f3f3f3f3f3f;
	for (register int i = 1;i <= n[m];i++) {
		register int lidx = Lower(l, a[m][i]), ridx = Upper(r, a[m][i]);
		if (lidx < 1 || ridx > n[r]) continue;
		ans = Min(ans, sqr(a[m][i] - a[l][lidx]) + sqr(a[m][i] - a[r][ridx]) + sqr(a[l][lidx] - a[r][ridx]));
	}
	return ans;
}

int main() {
	register int t = qread();
	while (t--) {
		Read();
		printf("%lld\n", Min(Solve(1, 2, 3), Min(Solve(1, 3, 2), Min(Solve(2, 1, 3), Min(Solve(2, 3, 1), Min(Solve(3, 1, 2), Solve(3, 2, 1)))))));
	}
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}