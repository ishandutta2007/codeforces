#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const int maxN = 1205;

int n, m, q, a, b, ar, br, ta, tb, ax, ay, bx, by, xlen, ylen;
int f[maxN * maxN], l[maxN * maxN], r[maxN * maxN], u[maxN * maxN], d[maxN * maxN];

inline int getID(int x, int y) { return x * (m + 2) + y; }

int main() {
	n = read(), m = read(), q = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) { f[getID(i, j)] = read(); }
	}
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			if (j >= 1) l[getID(i, j)] = getID(i, j - 1);
			if (j <= m) r[getID(i, j)] = getID(i, j + 1);
			if (i >= 1) u[getID(i, j)] = getID(i - 1, j);
			if (i <= n) d[getID(i, j)] = getID(i + 1, j);
		}
	}
	for (; q; q--) {
		ax = read(), ay = read(), bx = read(), by = read(), xlen = read(), ylen = read();
		a = getID(ax, 0), b = getID(bx, 0);
		for (int i = 1; i <= ay; i++) { a = r[a]; }
		for (int i = 1; i <= by; i++) { b = r[b]; }
		ta = ar = a, tb = br = b;
		for (int i = 0; i < ylen; i++) { ar = r[ar], br = r[br]; }
		for (int i = 0; i < xlen; i++) {
			std::swap(r[l[a]], r[l[b]]);
			std::swap(l[a], l[b]);
			std::swap(r[l[ar]], r[l[br]]);
			std::swap(l[ar], l[br]);
			a = d[a], b = d[b], ar = d[ar], br = d[br];
		}
		ar = ta, br = tb;
		for (int i = 0; i < ylen; i++) {
			std::swap(d[u[a]], d[u[b]]);
			std::swap(u[a], u[b]);
			std::swap(d[u[ar]], d[u[br]]);
			std::swap(u[ar], u[br]);
			a = r[a], b = r[b], ar = r[ar], br = r[br];
		}
	}
	for (int i = 1; i <= n; i++) {
		int id = getID(i, 0);
		for (int j = 1; j < m; j++) { id = r[id], printf("%d ", f[id]); }
		id = r[id], printf("%d\n", f[id]);
	}
	return 0;
}

// By Sooke.
// CF706E Working routine.