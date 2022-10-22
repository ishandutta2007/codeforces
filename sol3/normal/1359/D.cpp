#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
	register char c = getchar();
	register int x = 0, f = 1;
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	return x * f;
}

inline int Abs(const int& x) {return (x > 0 ? x : -x);}
inline int Max(const int& x, const int& y) {return (x > y ? x : y);}
inline int Min(const int& x, const int& y) {return (x < y ? x : y);}

int a[100005], n, l[100005], r[100005], idx[65];
struct Node {
	int lmax, rmax, midmax, sum;
};
struct Segtree {
	Node nd[400005];
	inline Node Pushup(Node lans, Node rans) {
		Node res;
		res.lmax = Max(lans.lmax, lans.sum + rans.lmax);
		res.rmax = Max(rans.rmax, rans.sum + lans.rmax);
		res.midmax = Max(Max(lans.midmax, rans.midmax), lans.rmax + rans.lmax);
		res.sum = lans.sum + rans.sum;
		return res;
	}
	inline void Build(int p, int pl, int pr) {
		if (pl == pr) {
			nd[p].lmax = nd[p].rmax = nd[p].midmax = nd[p].sum = a[pl];
			return;
		}
		register int mid = pl + pr >> 1;
		Build(p << 1, pl, mid); Build(p << 1 | 1, mid + 1, pr);
		nd[p] = Pushup(nd[p << 1], nd[p << 1 | 1]);
	}
	inline Node Query(int p, int pl, int pr, int l, int r) {
		if (pl == l && pr == r) return nd[p];
		register int mid = pl + pr >> 1;
		if (mid >= r) return Query(p << 1, pl, mid, l, r);
		else if (mid + 1 <= l) return Query(p << 1 | 1, mid + 1, pr, l, r);
		else return Pushup(Query(p << 1, pl, mid, l, mid), Query(p << 1 | 1, mid + 1, pr, mid + 1, r));
	}
};
Segtree sgt;

inline void Read() {
	n = qread();
	for (register int i = 1;i <= n;i++) a[i] = qread();
}

inline void Prefix() {
	for (register int i = 1;i <= n;i++) {
		for (register int j = a[i] + 32;j <= 61;j++) l[i] = Max(l[i], idx[j]);
		l[i]++;
		idx[a[i] + 31] = i;
	}
	for (register int i = 1;i <= 61;i++) idx[i] = n + 1;
	for (register int i = n;i >= 1;i--) {
		r[i] = n + 1;
		for (register int j = a[i] + 32;j <= 61;j++) r[i] = Min(r[i], idx[j]);
		r[i]--;
		idx[a[i] + 31] = i;
	}
	//for (register int i = 1;i <= n;i++) printf("%d %d\n", l[i], r[i]);
}

inline void Solve() {
	sgt.Build(1, 1, n);
	register int ans = 0;
	for (register int i = 1;i <= n;i++) ans = Max(ans, sgt.Query(1, 1, n, l[i], r[i]).midmax - a[i]);
	printf("%d", ans);
}

int main() {
	Read();
	Prefix();
	Solve();
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}