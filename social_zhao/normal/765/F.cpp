#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5, M = 5e5 + 5, inf = 0x3f3f3f3f, V = 1000000000;
int n, m, a[N], b[N], c[N], len, ans[M];
struct Ask {
	int l, r, id;
	bool operator <(Ask y) { return r < y.r; }
} q[M];
int mx[N * 30], lc[N * 30], rc[N * 30], tot, rt;

void pushup(int u) { mx[u] = max(mx[lc[u]], mx[rc[u]]); }
int update(int u, int l, int r, int x, int v) {
	if(!u) u = ++tot;
	if(l == r) { mx[u] = v; return u; }
	int mid = l + r >> 1;
	if(x <= mid) lc[u] = update(lc[u], l, mid, x, v);
	else rc[u] = update(rc[u], mid + 1, r, x, v);
	pushup(u); return u;
}
int query(int u, int l, int r, int a, int b) {
	if(!u) return 0;
	if(a == l && r == b) return mx[u];
	int mid = l + r >> 1;
	if(b <= mid) return query(lc[u], l, mid, a, b);
	else if(a > mid) return query(rc[u], mid + 1, r, a, b);
	else return max(query(lc[u], l, mid, a, mid), query(rc[u], mid + 1, r, mid + 1, b));
}

int mn[N];
int lowbit(int x) { return x & -x; }
void add(int x, int v) { while(x) mn[x] = min(mn[x], v), x -= lowbit(x); }
int ask(int x) { int r = inf; while(x <= n) r = min(r, mn[x]), x += lowbit(x); return r; }

void solve() {
	memset(mx, 0, sizeof(mx)), memset(mn, 0x3f, sizeof(mn));
	int maxr = 0;
	for(int i = 1; i <= m; i++) {
		while(maxr < q[i].r) {
			maxr++;
			int now = query(rt, 1, V, 1, a[maxr]);
			while(now) {
				add(now, a[maxr] - a[now]);
				now = query(rt, 1, V, (a[now] + a[maxr]) / 2 + 1, a[maxr]);
			}
			rt = update(rt, 1, V, a[maxr], maxr);
		}
		ans[q[i].id] = min(ans[q[i].id], ask(q[i].l));
	}
}

int main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	m = get();
	for(int i = 1; i <= m; i++) q[i].l = get(), q[i].r = get(), q[i].id = i;
	sort(q + 1, q + 1 + m);
	memset(ans, 0x3f, sizeof(ans));
	solve();
	for(int i = 1; i <= n; i++) a[i] = 1000000000 - a[i];
	solve();
	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}