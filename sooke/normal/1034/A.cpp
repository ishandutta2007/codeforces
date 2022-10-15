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
inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const int maxInt = 2147483647;
const lol maxLongLong = 9223372036854775807ll;
const int maxN = 15000005;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int n, m, g, max, tot, ans, cnt[maxN], a[maxN / 10];
bool vis[maxN];

int main() {
	n = read(), g = a[1] = read();
	for (int i = 2; i <= n; i++) { a[i] = read(), g = gcd(g, a[i]); }
	for (int i = 1; i <= n; i++) { cnt[a[i] / g]++, max = std::max(max, a[i] / g); }
	for (int i = 2; i <= max; i++) {
		if (!vis[i]) {
			tot = 0;
			for (int j = i; j <= max; j += i) { vis[j] = true, tot += cnt[j]; }
			ans = std::max(ans, tot);
		}
	}
	if (ans) { printf("%d\n", n - ans); } else { printf("-1\n"); }
	return 0;
}

// By Sooke.
// CF1034A Enlarge GCD.