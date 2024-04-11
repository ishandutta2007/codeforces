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

const int mod = 998244353;
int n, k, inv[500005], fac[500005];

inline void Prefix() {
	inv[1] = 1;
	for (register int i = 2;i <= n;i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	inv[0] = 1;
	for (register int i = 1;i <= n;i++) inv[i] = inv[i] * inv[i - 1] % mod;
	fac[0] = 1;
	for (register int i = 1;i <= n;i++) fac[i] = fac[i - 1] * i % mod;
}

inline int C(int n, int r) {
	if (n < r) return 0;
	return fac[n] * inv[r] % mod * inv[n - r] % mod;
}

inline void Solve() {
	register int ans = 0;
	for (register int i = 1;i <= n;i++) ans = (ans + C(n / i - 1, k - 1)) % mod;
	printf("%lld", ans);
}

signed main() {
	n = qread(); k = qread();
	Prefix();
	Solve();
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}