#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, inf = 0x3f3f3f3f3f3f3f3f;
int n, m, f[N][2], a[N];
struct Segment { int l, r; } s[N];
struct Node {
	int mxl, mnr;
	Node operator +(Node b) {
		Node res;
		res.mxl = max(mxl, b.mxl), res.mnr = min(mnr, b.mnr);
		return res;
	}
} t[N << 2];

#define mid ((l + r) >> 1)
#define lc (u << 1)
#define rc (u << 1 | 1)
void pushup(int u) { t[u] = t[lc] + t[rc]; }

void build(int u, int l, int r) {
	if(l == r) return t[u] = (Node){ s[l].l, s[l].r }, void();
	build(lc, l, mid), build(rc, mid + 1, r);
	pushup(u);
}

Node query(int u, int l, int r, int a, int b) {
	if(a > b) return (Node){ -inf, inf };
	if(a == l && r == b) return t[u];
	if(b <= mid) return query(lc, l, mid, a, b);
	else if(a > mid) return query(rc, mid + 1, r, a, b);
	else return query(lc, l, mid, a, mid) + query(rc, mid + 1, r, mid + 1, b);
}

void solve() {
	n = get(), m = get();
//	clear(max(n, m));
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= m; i++) s[i].l = get(), s[i].r = get();
	sort(a + 1, a + 1 + n);
	sort(s + 1, s + 1 + m, [](Segment a, Segment b){ return a.l < b.l; });
	build(1, 1, m);
	int now = 1, mx;
	while(now <= m && s[now].l <= a[1]) ++now;
	Node res = query(1, 1, m, 1, now - 1);
	mx = max(a[1] - query(1, 1, m, 1, now - 1).mnr, 0ll);
	f[1][0] = mx * 2, f[1][1] = mx;
	// 0: <> 1: ><
	for(int i = 2; i <= n; i++) {
		f[i][0] = f[i][1] = inf;
		int r = now;
		while(s[r].l <= a[i] && r <= m) ++r;
		for(int j = now; j <= r; j++) {
			Node lft = query(1, 1, m, now, j - 1), rht = query(1, 1, m, j, r - 1);
			int lenl = max(0ll, lft.mxl - a[i - 1]), lenr = max(0ll, a[i] - rht.mnr);
			f[i][0] = min(f[i][0], min(f[i - 1][0] + lenl + 2 * lenr, f[i - 1][1] + 2 * lenl + 2 * lenr));
			f[i][1] = min(f[i][1], min(f[i - 1][0] + lenl + lenr, f[i - 1][1] + 2 * lenl + lenr));
		}
		now = r;
	}
	mx = max(0ll, query(1, 1, m, now, m).mxl - a[n]);
	int ans = min(f[n][0] + mx, f[n][1] + mx * 2);
	printf("%lld\n", ans);
}

signed main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19
*/