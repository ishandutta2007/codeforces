#include <bits/stdc++.h>
using namespace std;

#define N 100100

int fa[N], ls[N], rs[N], root, n, d[N];
int son[N], mx[N], a[N], c[N];

void zig(int x) {
	int y = fa[x], z = fa[y];
	if (!y) return;
	int A = ls[x], B = rs[x], C = rs[y];
	fa[x] = z;
	if (z) {
		if (y == ls[z]) ls[z] = x;
		else rs[z] = x;
	}

//	ls[x] = A, fa[A] = x;
	rs[x] = y, fa[y] = x;
	ls[y] = B, fa[B] = y;
//	rs[y] = C, fa[C] = y;

	son[y] = son[B] + son[C] + 1;
	son[x] = son[A] + son[y] + 1;
	mx[y] = max(a[y], max(mx[B], mx[C]));
	mx[x] = max(a[x], max(mx[A], mx[y]));
}

void zag(int x) {
	int y = fa[x], z = fa[y];
	if (!y) return;
	int A = ls[y], B = ls[x], C = rs[x];
	fa[x] = z;
	if (z) {
		if (y == ls[z]) ls[z] = x;
		else rs[z] = x;
	}

	ls[x] = y, fa[y] = x;
//	rs[x] = C, fa[C] = x;
//	ls[y] = A, fa[A] = y;
	rs[y] = B, fa[B] = y;

	son[y] = son[A] + son[B] + 1;
	son[x] = son[y] + son[C] + 1;
	mx[y] = max(a[y], max(mx[A], mx[B]));
	mx[x] = max(a[x], max(mx[y], mx[C]));
}

void splay(int x) {
	if (x == root) return;
	int y = fa[x];
	if (y == root) {
		if (x == ls[y]) zig(x);
		else zag(x);
		root = x; fa[x] = 0; return;
	}
	int z = fa[y];
	if (x == ls[y] && y == ls[z]) {
		zig(x), zig(x);
		if (z == root) root = x;
		splay(x);
	}
	else if (x == rs[y] && y == rs[z]) {
		zag(x), zag(x);
		if (z == root) root = x;
		splay(x);
	}
	else if (x == ls[y] && y == rs[z]) {
		zig(x), zag(x);
		if (z == root) root = x;
		splay(x);
	}
	else {
		zag(x), zig(x);
		if (z == root) root = x;
		splay(x);
	}
}

void insert(int x, int i) {
	if (a[i] > a[x] && a[i] > mx[rs[x]] && c[i] >= son[rs[x]] + 1) {
		if (ls[x]) c[i] -= son[rs[x]] + 1, insert(ls[x], i);
		else {
			son[i] = 1, mx[i] = a[i];
			fa[i] = x, ls[x] = i;
			while (x) {
				son[x] ++, mx[x] = max(mx[x], a[i]);
				x = fa[x];
			}
			splay(i);
		}
		return;
	}
	if (rs[x]) insert(rs[x], i);
	else {
		son[i] = 1, mx[i] = a[i];
		fa[i] = x, rs[x] = i;
		while (x) {
			son[x] ++, mx[x] = max(mx[x], a[i]);
			x = fa[x];
		}
		splay(i);
		return;
	}
}

void dfs(int x) {
	if (!x) return;
	dfs(ls[x]);
	printf("%d ", x);
	dfs(rs[x]);
}

int main() {
//	freopen("g.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d", &a[i], &c[i]);
		if (!root) {
			root = i; son[i] = 1; continue;
		}
		int x = root;
		while (rs[x]) x = rs[x];
		splay(x);
		insert(root, i);
	}
	dfs(root); puts("");
	return 0;
}