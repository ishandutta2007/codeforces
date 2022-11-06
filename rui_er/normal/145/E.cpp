//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n, m, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int c4, c7, LnDS, LnIS, rev;
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void pushup(int u) {
		t[u].c4 = t[lc(u)].c4 + t[rc(u)].c4;
		t[u].c7 = t[lc(u)].c7 + t[rc(u)].c7;
		t[u].LnDS = max(t[lc(u)].c4 + t[rc(u)].LnDS, t[lc(u)].LnDS + t[rc(u)].c7);
		t[u].LnIS = max(t[lc(u)].c7 + t[rc(u)].LnIS, t[lc(u)].LnIS + t[rc(u)].c4);
	}
	void pushdown(int u) {
		if(!t[u].rev) return;
		t[lc(u)].rev ^= 1;
		swap(t[lc(u)].c4, t[lc(u)].c7);
		swap(t[lc(u)].LnDS, t[lc(u)].LnIS);
		t[rc(u)].rev ^= 1;
		swap(t[rc(u)].c4, t[rc(u)].c7);
		swap(t[rc(u)].LnDS, t[rc(u)].LnIS);
		t[u].rev = 0;
	}
	void build(int u, int l, int r) {
		t[u].rev = 0;
		if(l == r) {
			t[u].c4 = a[l] == 4;
			t[u].c7 = a[l] == 7;
			t[u].LnDS = t[u].LnIS = 1;
			return;
		}
		int mid = (l + r) >> 1;
		build(lc(u), l, mid);
		build(rc(u), mid+1, r);
		pushup(u);
	}
	void modify(int u, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) {
			t[u].rev ^= 1;
			swap(t[u].c4, t[u].c7);
			swap(t[u].LnDS, t[u].LnIS);
			return;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		if(ql <= mid) modify(lc(u), l, mid, ql, qr);
		if(qr > mid) modify(rc(u), mid+1, r, ql, qr);
		pushup(u);
	}
	#undef lc
	#undef rc
}sgt;

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%1d", &a[i]);
	sgt.build(1, 1, n);
	while(m --> 0) {
		char op[10];
		int x, y;
		scanf("%s", op);
		if(op[0] == 's') {
			scanf("%d%d", &x, &y);
			sgt.modify(1, 1, n, x, y);
		}
		else printf("%d\n", sgt.t[1].LnDS);
	}
	return 0;
}