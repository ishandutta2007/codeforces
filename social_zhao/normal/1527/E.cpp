#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")
#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 35005, inf = 0x3f3f3f3f;
int n, k, a[N], pre[N], lst[N], f[N], g[N];
namespace SGT {
	#define lc (u << 1)
	#define rc (u << 1 | 1)
	#define mid ((l + r) >> 1)
	int mn[N << 2], tag[N << 2];
	
	void pusha(int u, int v) { tag[u] += v, mn[u] += v; }
	void pushdown(int u) { pusha(lc, tag[u]), pusha(rc, tag[u]), tag[u] = 0; }
	void pushup(int u) { mn[u] = min(mn[lc], mn[rc]); }
	
	void mov(int u, int l, int r, int x, int v) {
		if(l == r) return mn[u] = v, void();
		pushdown(u);
		if(x <= mid) mov(lc, l, mid, x, v);
		else mov(rc, mid + 1, r, x, v);
		pushup(u);
	}
	
	void add(int u, int l, int r, int a, int b, int v) {
		if(a == l && r == b) return pusha(u, v);
		pushdown(u);
		if(b <= mid) add(lc, l, mid, a, b, v);
		else if(a > mid) add(rc, mid + 1, r, mid + 1, b, v);
		else add(lc, l, mid, a, mid, v), add(rc, mid + 1, r, mid + 1, b, v);
		pushup(u);
	}
	
	int ask(int u, int l, int r, int a, int b, int &now) {
		if(a > b || mn[u] >= now) return inf;
		if(a == l && r == b) return mn[u];
		pushdown(u);
		if(b <= mid) return now = min(now, ask(lc, l, mid, a, b, now));
		else if(a > mid) return now = min(now, ask(rc, mid + 1, r, mid + 1, b, now));
		else return now = min(now, min(ask(lc, l, mid, a, mid, now), ask(rc, mid + 1, r, mid + 1, b, now)));
	}
}

signed main() {
	n = get(), k = get();
	for(int i = 1; i <= n; i++) a[i] = get(), pre[i] = lst[a[i]], lst[a[i]] = i;
	for(int i = 1; i <= n; i++) f[i] = f[i - 1] + (pre[i]? i - pre[i] : 0);
	f[0] = 0x3f3f3f3f;
	for(int t = 2; t <= k; t++) {
		for(int i = 0; i <= n; i++) g[i] = f[i];
		for(int i = 1; i <= n; i++) {
			SGT::mov(1, 1, n, i, g[i - 1]);
			if(pre[i]) 
				SGT::add(1, 1, n, 1, pre[i], i - pre[i]);
			int mn = inf;
			f[i] = SGT::ask(1, 1, n, 1, i, mn);
		}
	}
	printf("%lld\n", f[n]);
	return 0;
}