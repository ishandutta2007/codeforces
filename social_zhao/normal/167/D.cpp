#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5, P = 1e9 + 9, inf = 0x3f3f3f3f;
int n, k, q, a, b, c, d;
struct Node { int x, y; } p[N];
struct Info {
	int f[2];
	Info(int x = -inf, int y = -inf) { f[0] = max(x, -inf), f[1] = max(y, -inf); }
	Info operator +(Info b) {
		return Info(max(f[0], f[1]) + max(b.f[0], b.f[1]), 
					max(f[0] + max(b.f[0], b.f[1]), max(f[0], f[1]) + b.f[0]) + 1);
	} 
} t[N];
int rt, lc[N], rc[N], L[N], R[N];

int build(int l, int r) {
	if(l > r) return 0;
	int mid = 0;
	for(int i = l; i <= r; i++) if(p[i].y >= p[mid].y) mid = i;
	L[mid] = R[mid] = p[mid].x;
	lc[mid] = build(l, mid - 1), rc[mid] = build(mid + 1, r);
	if(lc[mid]) L[mid] = min(L[mid], L[lc[mid]]);
	if(rc[mid]) R[mid] = max(R[mid], R[rc[mid]]);
	if(!lc[mid] && !rc[mid]) t[mid] = Info(0, -inf);
	else if(!rc[mid]) t[mid] = Info(max(t[lc[mid]].f[0], t[lc[mid]].f[1]), t[lc[mid]].f[0] + 1);
	else if(!lc[mid]) t[mid] = Info(max(t[rc[mid]].f[0], t[rc[mid]].f[1]), t[rc[mid]].f[0] + 1);
	else t[mid] = t[lc[mid]] + t[rc[mid]];
	return mid;
}

Info query(int u, int l, int r) {
	if(R[u] < l || L[u] > r) return Info();
	if(l <= L[u] && R[u] <= r) return t[u];
	Info lft = query(lc[u], l, r), rht = query(rc[u], l, r);
	if(lft.f[0] == -inf && rht.f[0] == -inf) {
		if(l <= p[u].x && p[u].x <= r) return Info(0, -inf);
		else return Info(-inf, -inf);
	}
	else if(rht.f[0] == -inf) {
		if(l <= p[u].x && p[u].x <= r) return Info(max(lft.f[0], lft.f[1]), lft.f[0] + 1);
		else return lft;
	}
	else if(lft.f[0] == -inf) {
		if(l <= p[u].x && p[u].x <= r) return Info(max(rht.f[0], rht.f[1]), rht.f[0] + 1);
		else return rht;
	}
	else return lft + rht;
}

main() {
	n = get(), k = get();
	for(int i = 1; i <= k; i++) p[i].x = get(), p[i].y = get();
	a = get(), b = get(), c = get(), d = get();
	for(int i = k + 1; i <= n; i++) {
		p[i].x = (p[i - 1].x * a + b) % P;
		p[i].y = (p[i - 1].y * c + d) % P;
	}
	sort(p + 1, p + 1 + n, [](Node a, Node b) { return a.x < b.x; });
	rt = build(1, n);
	q = get();
//	Info der = Info() + Info();
	for(int i = 1; i <= q; i++) {
		int l = get(), r = get();
		Info res = query(rt, l, r);
		printf("%lld\n", max(0ll, max(res.f[0], res.f[1])));
	}
	return 0;
}

/*
2 2
1 3
3 4
1 1 1 1
1
2 2
*/