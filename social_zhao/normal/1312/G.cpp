#include<bits/stdc++.h>
#define lc (u << 1)
#define rc (u << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, m, key[N], imp[N], ch[N][26], f[N];
int mn[N << 2], tag[N << 2];

void pushup(int u) { mn[u] = min(mn[lc], mn[rc]); }
void pusht(int u, int v) { mn[u] += v, tag[u] += v; }
void pushdown(int u) { pusht(lc, tag[u]), pusht(rc, tag[u]), tag[u] = 0; }

void update(int u, int l, int r, int x, int v) {
	if(l == r) return mn[u] = v, void();
	pushdown(u);
	if(x <= mid) update(lc, l, mid, x, v);
	else update(rc, mid + 1, r, x, v);
	pushup(u);
}

void add(int u, int l, int r, int a, int b, int v) {
	if(a == l && r == b) return pusht(u, v);
	pushdown(u);
	if(b <= mid) add(lc, l, mid, a, b, v);
	else if(a > mid) add(rc, mid + 1, r, a, b, v);
	else add(lc, l, mid, a, mid, v), add(rc, mid + 1, r, mid + 1, b, v);
	pushup(u);
}

int query(int u, int l, int r, int a, int b) {
	if(a > b) return 0x3f3f3f3f;
	if(a == l && r == b) return mn[u];
	pushdown(u);
	if(b <= mid) return query(lc, l, mid, a, b);
	else if(a > mid) return query(rc, mid + 1, r, a, b);
	else return min(query(lc, l, mid, a, mid), query(rc, mid + 1, r, mid + 1, b));
}

void dfs(int u, int mn1, int dep) {
	if(u) {
		f[u] = dep + mn1;
		if(imp[u]) f[u] = min(f[u], query(1, 0, n, 0, dep - 1));
		update(1, 0, n, dep, f[u] + 1);
		add(1, 0, n, 0, dep, imp[u]);
	}
	else update(1, 0, n, 0, 1);
	for(int i = 0; i < 26; i++) {
		int v = ch[u][i];
		if(!v) continue;
		dfs(v, min(mn1, f[u] - dep), dep + 1);
	}
	update(1, 0, n, dep, 0);
}

int main() {
	n = get();
	for(int i = 1; i <= n; i++) {
		int p = get(); 
		char c[5]; 
		scanf("%s", c);
		ch[p][c[0] - 'a'] = i;
	}
	m = get();
	for(int i = 1; i <= m; i++) key[i] = get(), imp[key[i]] = 1;
	dfs(0, 0, 0);
	for(int i = 1; i <= m; i++) printf("%d ", f[key[i]]);
	return 0;
}