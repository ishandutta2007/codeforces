#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define p2 p << 1
#define p3 p << 1 | 1
using namespace std;
inline int read() {
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}
const int N = 5e5 + 5, M = N << 2;
int n, q, a[N], T[M], tot, L[N], R[N], G[N];
void build(int l, int r, int p) {
	if (l == r) return (void) (T[p] = a[l]);
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	T[p] = __gcd(T[p2], T[p3]);
}
void change(int l, int r, int pos, int v, int p) {
	if (l == r) return (void) (T[p] = v);
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, v, p2);
	else change(mid + 1, r, pos, v, p3);
	T[p] = __gcd(T[p2], T[p3]);
}
void query(int l, int r, int s, int e, int p) {
	if (l == s && r == e) return (void)
		(L[++tot] = l, R[tot] = r, G[tot] = p);
	int mid = l + r >> 1;
	if (e <= mid) query(l, mid, s, e, p2);
	else if (s >= mid + 1) query(mid + 1, r, s, e, p3);
	else query(l, mid, s, mid, p2),
		query(mid + 1, r, mid + 1, e, p3);
}
bool trygcd(int l, int r, int p, int x) {
	if (l == r || T[p] % x == 0) return 1;
	int mid = l + r >> 1;
	if (T[p2] % x && T[p3] % x) return 0;
	else if (T[p2] % x) return trygcd(l, mid, p2, x);
	else return trygcd(mid + 1, r, p3, x);
}
bool ask(int l, int r, int x) {
	int i, pos = 0; tot = 0; query(1, n, l, r, 1);
	For (i, 1, tot) if (T[G[i]] % x) {
		if (pos) return 0;
		else pos = i;
	}
	return !pos || trygcd(L[pos], R[pos], G[pos], x);
}
int main() {
	int i, op, x, y, z; n = read();
	For (i, 1, n) a[i] = read(); build(1, n, 1);
	q = read(); while (q--) {
		op = read(); x = read(); y = read();
		if (op == 2) change(1, n, x, y, 1);
		else z = read(), puts(ask(x, y, z) ? "YES" : "NO");
	}
	return 0;
}