#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long lol;
typedef long double lod;

inline char readLetter() {
	char c = getchar();
	while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) { c = getchar(); }
	return c;
}
inline lol read() {
	char c = getchar(); lol n = 0; bool f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

inline lol power(lol a, lol b, lol p) { lol res = 1; for (; b; b >>= 1, a = a * a % p) { if (b & 1) { res = res * a % p; } } return res; }
lol gcd(lol a, lol b) { return b ? gcd(b, a % b) : a; }

const int maxInt = 2147483647;
const lol maxLongLong = 9223372036854775807ll;
const int maxN = 300005;

int n, max, a[maxN], sum[maxN], js[maxN], os[maxN];
lol ans;

int main() {
	n = read();
	for (int i = 1; i <= n; i++) { lol t = read(); while (t) { a[i] += t & 1, t >>= 1; } }
	for (int i = 1; i <= n; i++) { sum[i] = sum[i - 1] + a[i]; }
	for (int i = 1; i <= n; i++) { js[i] = js[i - 1] + sum[i] % 2; }
	os[0] = 1;
	for (int i = 1; i <= n; i++) { os[i] = os[i - 1] + (sum[i] % 2 == 0); }
	for (int i = 1, mid; i <= n; i++) {
		max = 0, mid = std::max(1, i - 64);
		for (int j = i; j >= mid; j--) {
			max = std::max(max, a[j]);
			if (max * 2 <= sum[i] - sum[j - 1] && sum[i] % 2 == sum[j - 1] % 2) { ans++; }
		}
		if (mid == 1) { continue; }
		if (sum[i] % 2) { ans += js[mid - 2]; }
		else { ans += os[mid - 2]; }
	}
	printf("%I64d\n", ans);
	return 0;
}

// By Sooke.