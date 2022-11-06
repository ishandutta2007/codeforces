//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m, a[N], b[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int L, R, tag;
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void build(int u, int l, int r) {
		t[u].L = l; t[u].R = r;
		if(l == r) return;
		int mid = (l + r) >> 1;
		build(lc(u), l, mid);
		build(rc(u), mid+1, r);
	}
	void pushdown(int u) {
		if(!t[u].tag) return;
		t[lc(u)].tag = t[u].tag;
		t[rc(u)].tag = t[u].tag + (t[lc(u)].R - t[lc(u)].L + 1);
		t[u].tag = 0;
	}
	void modify(int u, int l, int r, int ql, int qr, int k) {
		if(ql <= l && r <= qr) {
			t[u].tag = k + (l - ql);
			return;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		if(ql <= mid) modify(lc(u), l, mid, ql, qr, k);
		if(qr > mid) modify(rc(u), mid+1, r, ql, qr, k);
		return;
	}
	int query(int u, int l, int r, int pos) {
		if(l == r) return t[u].tag;
		pushdown(u);
		int mid = (l + r) >> 1;
		if(pos <= mid) return query(lc(u), l, mid, pos);
		else return query(rc(u), mid+1, r, pos);
	}
	#undef lc
	#undef rc
}sgt;

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) scanf("%d", &b[i]);
	sgt.build(1, 1, n);
	while(m --> 0) {
		int op, x, y, k;
		scanf("%d%d", &op, &x);
		if(op == 1) {
			scanf("%d%d", &y, &k);
			sgt.modify(1, 1, n, y, y+k-1, x);
		}
		else {
			int qwq = sgt.query(1, 1, n, x);
			printf("%d\n", qwq?a[qwq]:b[x]);
		}
	}
	return 0;
}