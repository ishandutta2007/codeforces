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

const long long mod = 1000000007;
long long n;

inline long long fac(long long n) {
	register long long ans = 1;
	for (register long long i = 2;i <= n;i++) ans = ans * i % mod;
	return ans;
}

inline long long Pow(long long x, long long y) {
	long long ans = 1;
	while (y) {
		if (y & 1) ans = ans * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ans;
}

int main() {
	n = qread();
	printf("%lld", ((fac(n) - Pow(2ll, n - 1)) % mod + mod) % mod);
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}