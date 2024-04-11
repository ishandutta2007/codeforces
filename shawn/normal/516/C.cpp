#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll read() {
	ll x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

void write(ll x) {
	if (x < 0) putchar('-'), write(-x);
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int maxn = 6e5 + 50;

ll h[maxn], d[maxn];

int n, m, N;

struct tree{
	ll a, b, c;
	tree() {
		a = b = c = 0;
	}
}t[maxn << 2];

tree merge(tree &ls, tree &rs) {
	tree ret;
	ret.a = max(ls.a, rs.a);
	ret.b = max(ls.b, rs.b);
	ret.c = max(ls.c, rs.c);
//	ret.c = max(ret.c, t[ls].a + t[rs].b);
	ret.c = max(ret.c, ls.b + rs.a);
	return ret;
}

void build(int k, int l, int r) {
	if (l == r) {
		t[k].c = 0;
		t[k].a = 2 * h[l] + d[l - 1];
		t[k].b = 2 * h[l] - d[l - 1];
		return;
	}
	int mid = l + r >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
	t[k] = merge(t[k << 1], t[k << 1 | 1]);
}

tree query(int k, int l, int r, int x, int y) {
	if (x == l && r == y) return t[k];
	int mid = l + r >> 1;
	if (y <= mid) return query(k << 1, l, mid, x, y);
	else if (x > mid) return query(k << 1 | 1, mid + 1, r, x, y);
	else {
		tree L = query(k << 1, l, mid, x, mid), R = query(k << 1 | 1, mid + 1, r, mid + 1, y);
		tree ret = merge(L, R);
		return ret;
	}
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i ++) d[i] = d[i + n] = read();
	for (int i = 1; i <= n; i ++) h[i] = h[i + n] = read();
	N = n << 1;
	for (int i = 2; i <= N; i ++) d[i] = d[i - 1] + d[i];
	build(1, 1, N);
	while (m --) {
		int u = read(), v = read();
		swap(u, v);
		if (u < v) u ++, v --;
		else u ++, v = v + n - 1;
		write(query(1, 1, N, u, v).c), putchar(10);
	}
	return 0;
}

/*
input:
5 3
2 2 2 2 2
3 5 2 1 4
1 3
2 2
4 5
output:
12
16
18
*/