#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

void openFile() { freopen("clique.in", "r", stdin); freopen("clique.out", "w", stdout); }
void closeFile() { fclose(stdin); fclose(stdout); }

inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const int maxN = 200005;

int n, unin, table[maxN << 1];

struct Point { int x, w; } p[maxN];
bool cmp(Point x, Point y) { return x.x < y.x; }

struct TreeArray {
	int c[maxN << 1];
	
	inline int lowbit(int u) { return u & -u; }
	inline void modify(int u, int x) { for (; u <= unin; u += lowbit(u)) { c[u] = std::max(c[u], x); } }
	inline int query(int u) { int max = 0; for (; u; u ^= lowbit(u)) { max = std::max(max, c[u]); } return max; }
} tr;

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		p[i].x = read(), p[i].w = read();
		table[++unin] = p[i].x - p[i].w, table[++unin] = p[i].x + p[i].w;
	}
	std::sort(p + 1, p + n + 1, cmp), std::sort(table + 1, table + unin + 1);
	unin = std::unique(table + 1, table + unin + 1) - table - 1;
	for (int i = 1; i <= n; i++) { 
		int a = std::lower_bound(table + 1, table + unin + 1, p[i].x - p[i].w) - table;
		int b = std::lower_bound(table + 1, table + unin + 1, p[i].x + p[i].w) - table;
		tr.modify(b, tr.query(a) + 1);
	}
	printf("%d\n", tr.query(unin));
	return 0;
}