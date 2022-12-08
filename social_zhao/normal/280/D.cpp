#include<bits/stdc++.h>
#define lc (x << 1)
#define rc (x << 1 | 1)
#define int long long
using namespace std;

inline int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n;
struct node {
	int l, r, v;
};
struct Segment {
	node lmin, rmin, lmax, rmax, smin, smax, sum;
	int rev;
} t[N << 2];

inline node operator + (node a, node b) {
	return (node){a.l, b.r, a.v + b.v};
}

inline bool operator < (node a, node b) {
	return a.v < b.v;
}

inline node max(node a, node b) {
	return (a<b?b:a);
}

inline node min(node a, node b) {
	return (a<b?a:b);
}

inline void pushup(int x) {
	t[x].lmax = max(t[lc].lmax, t[lc].sum + t[rc].lmax);
	t[x].lmin = min(t[lc].lmin, t[lc].sum + t[rc].lmin);
	t[x].rmax = max(t[rc].rmax, t[lc].rmax + t[rc].sum);
	t[x].rmin = min(t[rc].rmin, t[lc].rmin + t[rc].sum);
	t[x].sum = t[lc].sum + t[rc].sum;
	t[x].smax = max(max(t[lc].smax, t[rc].smax), t[lc].rmax + t[rc].lmax);
	t[x].smin = min(min(t[lc].smin, t[rc].smin), t[lc].rmin + t[rc].lmin);
	t[x].rev = 0;
}

inline void pushr(int x) {
	swap(t[x].lmax, t[x].lmin);
	swap(t[x].rmax, t[x].rmin);
	swap(t[x].smax, t[x].smin);
	t[x].lmax.v *= -1;
	t[x].lmin.v *= -1;
	t[x].rmax.v *= -1;
	t[x].rmin.v *= -1;
	t[x].smax.v *= -1;
	t[x].smin.v *= -1;
	t[x].sum.v *= -1;
	t[x].rev ^= 1;
}

inline void pushdown(int x) {
	if(t[x].rev) {
		pushr(lc);
		pushr(rc);
		t[x].rev = 0;
	}
}

inline void update (int x, int l, int r, int u, int v) {
	if(l == r && l == u) {
		t[x].lmax = t[x].lmin = t[x].rmax = t[x].rmin = t[x].smax = t[x].smin = t[x].sum = (node){l, l, v};
		t[x].rev = 0;
		return;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if(u <= mid) update(lc, l, mid, u, v);
	else update(rc, mid + 1, r, u, v);
	pushup(x);
}

inline void rev(int x, int l, int r, int a, int b) {
	if(l == a && r == b) {
		pushr(x);
		return;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if(b <= mid) rev(lc, l, mid, a, b);
	else if(a > mid) rev(rc, mid + 1, r, a, b);
	else rev(lc, l, mid, a, mid), rev(rc, mid + 1, r, mid + 1, b);
	pushup(x);
}

inline Segment query(int x, int l, int r, int a, int b) {
	if(l == a && r == b) return t[x];
	pushdown(x);
	int mid = (l + r) >> 1;
	if(b <= mid) return query(lc, l, mid, a, b);
	else if(a > mid) return query(rc, mid + 1, r, a, b);
	else {
		Segment ans1 = query(lc, l, mid, a, mid), ans2 = query(rc, mid + 1, r, mid + 1, b), res;
		res.lmax = max(ans1.lmax, ans1.sum + ans2.lmax);
		res.lmin = min(ans1.lmin, ans1.sum + ans2.lmin);
		res.rmax = max(ans2.rmax, ans1.rmax + ans2.sum);
		res.rmin = min(ans2.rmin, ans1.rmin + ans2.sum);
		res.sum = ans1.sum + ans2.sum;
		res.smax = max(max(ans1.smax, ans2.smax), ans1.rmax + ans2.lmax);
		res.smin = min(min(ans1.smin, ans2.smin), ans1.rmin + ans2.lmin);
		res.rev = 0;
		return res;
	}
}

Segment que[N];
int top = 0;

signed main() {
	n = get();
	for(register int i = 1; i <= n; i++) {
		int x = get();
		update(1, 1, n, i, x);
	}
	int q = get();
	while(q--) {
		int opt = get();
		if(opt == 0) {
			int x = get(), v = get();
			update(1, 1, n, x, v);
		}
		else {
			int l = get(), r = get(), k = get(), ans = 0, top = 0;
			while(k--) {
				Segment x = query(1, 1, n, l, r);
				if(x.smax.v < 0) break;
				que[++top] = x;
				ans += x.smax.v;
				rev(1, 1, n, x.smax.l, x.smax.r);
			}
			printf("%lld\n", ans);
			while(top) {
				Segment x = que[top];
				top--;
				rev(1, 1, n, x.smax.l, x.smax.r);
			}
		}
	}
	return 0;
}