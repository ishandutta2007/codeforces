#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, q, pw[N], top, a[N];
int mn[N << 2], add[N << 2], mov[N << 2], val[N << 2];

#define mid ((l + r) >> 1)
#define lc (u << 1)
#define rc (u << 1 | 1)

int GetDelt(int x) { return pw[lower_bound(pw + 1, pw + 1 + top, x) - pw] - x; }
void pushup(int u) { mn[u] = min(mn[lc], mn[rc]); } 
void pushm(int u, int v) { mov[u] = val[u] = v, mn[u] = GetDelt(v); }
void pusha(int u, int v) { 
	if(mov[u] != -1) pushm(u, mov[u] + v);
	else add[u] += v, mn[u] -= v, val[u] += v; 
} 
void pushdown(int u) {
	if(add[u]) pusha(lc, add[u]), pusha(rc, add[u]), add[u] = 0;
	if(~mov[u]) pushm(lc, mov[u]), pushm(rc, mov[u]), mov[u] = -1;
}

void build(int u, int l, int r) {
	mov[u] = -1;
	if(l == r) return mn[u] = GetDelt(a[l]), val[u] = a[l], void();
	build(lc, l, mid), build(rc, mid + 1, r), pushup(u);
}

int query(int u, int l, int r, int x) {
	if(l == r) return val[u];
	pushdown(u);
	if(x <= mid) return query(lc, l, mid, x);
	else return query(rc, mid + 1, r, x);
}

void assign(int u, int l, int r, int a, int b, int v) {
	if(a == l && r == b) return pushm(u, v);
	pushdown(u);
	if(b <= mid) assign(lc, l, mid, a, b, v);
	else if(a > mid) assign(rc, mid + 1, r, a, b, v);
	else assign(lc, l, mid, a, mid, v), assign(rc, mid + 1, r, mid + 1, b, v);
	pushup(u);
}

void update(int u, int l, int r, int a, int b, int v) {
	if(l == r) return pusha(u, v), mn[u] = GetDelt(val[u]), void();
	if(a == l && r == b) {
		pusha(u, v), pushdown(u);
		if(mn[lc] < 0) update(lc, l, mid, a, mid, 0);
		if(mn[rc] < 0) update(rc, mid + 1, r, mid + 1, b, 0);
		pushup(u);
		return;
	}
	pushdown(u);
	if(b <= mid) update(lc, l, mid, a, b, v);
	else if(a > mid) update(rc, mid + 1, r, a, b, v);
	else update(lc, l, mid, a, mid, v), update(rc, mid + 1, r, mid + 1, b, v);
	pushup(u);
}

signed main() {
	n = get(), q = get();
	int nw = 1; pw[0] = 1;
	while(nw * 42 <= 5e16) nw *= 42, pw[++top] = nw;
	for(int i = 1; i <= n; i++) a[i] = get();
	build(1, 1, n);
	for(int i = 1; i <= q; i++) {
		int op = get(), x = get(), y, v;
		if(op == 1) printf("%lld\n", query(1, 1, n, x));
		else if(op == 2) {
			y = get(), v = get();
			assign(1, 1, n, x, y, v);
		}
		else {
			y = get(), v = get();
			update(1, 1, n, x, y, v);
			while(mn[1] == 0) 
				update(1, 1, n, x, y, v);
		}
	}
	return 0;
}