#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5, S = N * 100;
int n, m, ans[N]; 
struct Segment { int l, r, tim; } q[N];

void qmin(int &u, int v) { 
	if(q[u].tim > q[v].tim) u = v; 
}
namespace SGT {
	int T[N], lc[S], rc[S], mn[S], tot;
	
	void pushup(int u) { mn[u] = mn[lc[u]], qmin(mn[u], mn[rc[u]]); }
	void update(int &u, int l, int r, int x, int v) {
		if(!u) u = ++tot;
		if(l == r) { qmin(mn[u], v); return; }
		int mid = (l + r) >> 1;
		if(x <= mid) update(lc[u], l, mid, x, v);
		else if(x > mid) update(rc[u], mid + 1, r, x, v);
		pushup(u);
	}
	int query(int u, int l, int r, int a, int b) {
		if(!u) return 0;
		if(a == l && r == b) return mn[u];
		int mid = (l + r) >> 1;
		if(b <= mid) return query(lc[u], l, mid, a, b);
		else if(a > mid) return query(rc[u], mid + 1, r, a, b);
		else {
			int res = query(lc[u], l, mid, a, mid);
			qmin(res, query(rc[u], mid + 1, r, mid + 1, b));
			return res;
		} 
	}
}

namespace BIT {
	int lowbit(int x) { return x & (-x); }
	void add(int x, int y, int z) { 
		while(x <= n) 
			SGT::update(SGT::T[x], 1, n, y, z), x += lowbit(x); 
	}
	int ask(int x, int y) { int r(0); while(x) qmin(r, SGT::query(SGT::T[x], 1, n, y, n)), x -= lowbit(x); return r; }
}

void insert(int v) { BIT::add(q[v].r, q[v].l, v); }
int ask(int l, int r) { return BIT::ask(r, l); }

int calc(int l, int r) {
	if(l > r) return 0;
	int pos = ask(l, r);
	if(pos == 0) return 0;
	int x = q[pos].l, y = q[pos].r;
	return y - x + 1 + calc(l, x - 1) + calc(y + 1, r);
}

int main() {
	n = get(), m = get();
	for(int i = 1; i <= m; i++) q[i].l = get(), q[i].r = get(), q[i].tim = i;
	sort(q + 1, q + 1 + m, [](Segment x, Segment y) { return x.r - x.l > y.r - y.l; });
	q[0].tim = 1919810;
	for(int i = n, nowr = 1; i >= 1; i--) {
		while(nowr <= m && q[nowr].r - q[nowr].l + 1 == i) insert(nowr), ++nowr;
		ans[i] = calc(1, n);
	}
	for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}