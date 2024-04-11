#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
int n, m, u[N], v[N], w[N], ch[N][2], fa[N], size[N], si[N], mx[N];
bool rev[N];

struct cmp {
	bool operator()(int x, int y) {
		return w[x] < w[y] || (w[x] == w[y] && x < y);
	}
};
set<int, cmp> s;

bool isroot(int x) {
	return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
}
void pushup(int x) {
	size[x] = si[x] + size[ch[x][0]] + size[ch[x][1]] + (x <= n);
	mx[x] = max({mx[ch[x][0]], mx[ch[x][1]], x > n ? x - n : 0}, cmp());
}
void reverse(int x) {
	rev[x] ^= 1, swap(ch[x][0], ch[x][1]);
}
void pushdown(int x) {
	if (rev[x]) {
		if (ch[x][0]) reverse(ch[x][0]);
		if (ch[x][1]) reverse(ch[x][1]);
		rev[x] = false;
	}
}
void pushdown_all(int x) {
	if (!isroot(x)) pushdown_all(fa[x]);
	pushdown(x);
}
void rotate(int x) {
	int y = fa[x], z = fa[y], d = ch[y][1] == x;
	if (!isroot(y)) ch[z][ch[z][1] == y] = x;
	fa[ch[y][d] = ch[x][d ^ 1]] = y;
	fa[ch[x][d ^ 1] = y] = x; fa[x] = z;
	pushup(y);
}
void splay(int x) {
	pushdown_all(x);
	for (int y; y = fa[x], !isroot(x); rotate(x))
		if (!isroot(y)) rotate((ch[y][1] == x) != (ch[fa[y]][1] == y) ? x : y);
	pushup(x);
}
int access(int x) {
	int y = 0;
	for (; x; y = x, x = fa[x]) {
		splay(x);
		if (ch[x][1]) si[x] += size[ch[x][1]];
		ch[x][1] = y;
		if (y) si[x] -= size[y];
		pushup(x);
	}
	return y;
}
int find_root(int x) {
	access(x), splay(x);
	while (ch[x][0]) x = ch[x][0];
	splay(x); return x;
}
void evert(int x) {
	access(x), splay(x), reverse(x);
}
int query_max(int x, int y) {
	evert(x), access(y), splay(y); return mx[y];
}
void link(int x, int y) {
	evert(x), access(y), splay(y), fa[x] = y;
	si[y] += size[x], size[y] += size[x];
}
void cut(int x, int y) {
	evert(x), access(y), splay(y), fa[x] = ch[y][0] = 0, pushup(y);
}
int query_size(int x) {
	access(x), splay(x); return size[x];
}

void reduce() {
	for (;;) {
		int e = *s.rbegin();
		cut(u[e], n + e), cut(n + e, v[e]);
		if (query_size(u[e]) % 2) {
			link(u[e], n + e), link(n + e, v[e]);
			break;
		}
		s.erase(e);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		size[i] = 1;
	int cnt = n;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", u + i, v + i, w + i);
		mx[n + i] = i;
		if (find_root(u[i]) != find_root(v[i])) {
			cnt -= query_size(u[i]) % 2;
			cnt -= query_size(v[i]) % 2;
			link(u[i], n + i), link(n + i, v[i]);
			cnt += query_size(n + i) % 2;
			s.insert(i);
			if (!cnt) reduce();
		} else {
			int e = query_max(u[i], v[i]);
			if (w[i] < w[e]) {
				cut(u[e], n + e), cut(n + e, v[e]);
				s.erase(e);
				link(u[i], n + i), link(n + i, v[i]);
				s.insert(i);
				if (!cnt) reduce();
			}
		}
		if (cnt) puts("-1");
		else printf("%d\n", w[*s.crbegin()]);
	}
	return 0;
}