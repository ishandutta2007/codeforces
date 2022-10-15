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

const int maxInt = 2147483647;
const lol maxLongLong = 9223372036854775807ll, lim = 4 * 1e14 + 5;
const int maxN = 200005;

int n;
lol t, ans, a[maxN], sum[maxN];

struct SegmentTree {
	int cnt, root, c[maxN * 60], lson[maxN * 60], rson[maxN * 60];
	
	void modify(int &u, lol l, lol r, lol p) {
		if (!u) { u = ++cnt; }
		if (l == r) { c[u]++; return; }
		lol mid = l + r >> 1;
		if (p <= mid) { modify(lson[u], l, mid, p); }
		else { modify(rson[u], mid + 1, r, p); }
		c[u] = c[lson[u]] + c[rson[u]];
	}
	int query(int u, lol l, lol r, lol pl, lol pr) {
		if (!u) { return 0; }
		if (l == pl && r == pr) { return c[u]; }
		lol mid = l + r >> 1;
		if (pr <= mid) { return query(lson[u], l, mid, pl, pr); }
		else if (pl > mid) { return query(rson[u], mid + 1, r, pl, pr); }
		else { return query(lson[u], l, mid, pl, mid) + query(rson[u], mid + 1, r, mid + 1, pr); }
	}
} tr;

int main() {
	n = read(), t = read();
	tr.modify(tr.root, -lim, lim, 0);
	for (int i = 1; i <= n; i++) { a[i] = read(); sum[i] = sum[i - 1] + a[i]; }
	for (int i = 1; i <= n; i++) {
		ans += tr.query(tr.root, -lim, lim, sum[i] - t + 1, lim);
		tr.modify(tr.root, -lim, lim, sum[i]);
	}
	std::cout << ans << std::endl;
	return 0;
}