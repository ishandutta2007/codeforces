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
const int maxN = 1005;

int n, m, cnt[maxN], ans[maxN];

int main() {
	n = read();
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		if (u > v) { std::swap(u, v); }
		if (v != n || u == n) { printf("NO\n"); return 0; }
		cnt[u]++;
	}
	ans[++m] = n;
	for (int i = n - 1; i; i--) {
		if (cnt[i] == -1) { continue; }
		if (cnt[i] == 0) { ans[++m] = i; cnt[i] = -1; continue; }
		for (int j = n - 1; j; j--) {
			if (cnt[i] == 1) { break; }
			if (cnt[j] == 0) { cnt[j] = -1, ans[++m] = j, cnt[i]--; }
		}
		if (cnt[i] != 1) { printf("NO\n"); return 0; }
		ans[++m] = i;
	}
	printf("YES\n");
	for (int i = 2; i <= n; i++) { printf("%d %d\n", ans[i - 1], ans[i]); }
	return 0;
}