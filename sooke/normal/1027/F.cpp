#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
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
const lol maxLongLong = 9223372036854775807LL;
const int maxN = 2000005;

int n, m, un, ans, x, y, max1, max2, a[maxN], b[maxN], table[maxN];
bool vis[maxN];

struct List {
	int len, fst[maxN], nxt[maxN << 1], v[maxN << 1];
	List() { memset(fst, -1, sizeof(fst)), len = 0; }
	inline void insert(int uu, int vv) { v[len] = vv, nxt[len] = fst[uu], fst[uu] = len++; }
	inline void connect(int uu, int vv) { insert(uu, vv), insert(vv, uu); }
} ls;

void dfs(int u) {
	if (vis[u]) { return; }
	vis[u] = true, x++;
	if (max1 < u) { max2 = max1, max1 = u; }
	else { max2 = std::max(max2, u); }
	for (int i = ls.fst[u]; i != -1; i = ls.nxt[i]) { dfs(ls.v[i]), y++; }
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) { table[++m] = a[i] = read(), table[++m] = b[i] = read(); }
	std::sort(table + 1, table + m + 1);
	un = std::unique(table + 1, table + m + 1) - table - 1;
	for (int i = 1; i <= n; i++) {
		a[i] = std::lower_bound(table + 1, table + un + 1, a[i]) - table;
		b[i] = std::lower_bound(table + 1, table + un + 1, b[i]) - table;
		ls.connect(a[i], b[i]);
	}
	for (int i = 1; i <= un; i++) {
		if (!vis[i]) {
			x = y = max1 = max2 = 0;
			dfs(i);
			y >>= 1;
			if (x == y) { ans = std::max(ans, table[max1]); }
			else if (x - 1 == y) { ans = std::max(ans, table[max2]); }
			else { printf("-1\n"); return 0; }
		}
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.
// CF1027F Session in BSU.