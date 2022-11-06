//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5; 

int n, m;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Require {
	int l, r, q;
}req[N];
struct Node {
	int tag, w;
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void pushup(int u) {
		t[u].w = t[lc(u)].w & t[rc(u)].w;
	}
	void pushdown(int u) {
		if(!t[u].tag) return;
		t[lc(u)].tag |= t[u].tag;
		t[rc(u)].tag |= t[u].tag;
		t[lc(u)].w |= t[u].tag;
		t[rc(u)].w |= t[u].tag;
		t[u].tag = 0;
	}
	void modify(int u, int l, int r, int ql, int qr, int k) {
		if(ql <= l && r <= qr) {
			t[u].tag |= k;
			t[u].w |= k;
			return;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		if(ql <= mid) modify(lc(u), l, mid, ql, qr, k);
		if(qr > mid) modify(rc(u), mid+1, r, ql, qr, k);
		pushup(u);
	}
	int query(int u, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) return t[u].w;
		pushdown(u);
		int mid = (l + r) >> 1, ans = (1LL << 31) - 1;
		if(ql <= mid) ans &= query(lc(u), l, mid, ql, qr);
		if(qr > mid) ans &= query(rc(u), mid+1, r, ql, qr);
		pushup(u);
		return ans;
	}
	void print(int u, int l, int r) {
		if(l == r) {
			printf("%d ", t[u].w);
			return;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		print(lc(u), l, mid);
		print(rc(u), mid+1, r);
	}
	#undef lc
	#undef rc
}sgt;

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		scanf("%d%d%d", &req[i].l, &req[i].r, &req[i].q);
		per(j, 30, 0) if((req[i].q >> j) & 1) sgt.modify(1, 1, n, req[i].l, req[i].r, 1<<j);
	}
	rep(i, 1, m) {
		int qwq = sgt.query(1, 1, n, req[i].l, req[i].r);
		if(qwq != req[i].q) return puts("NO")&0;
	}
	puts("YES");
	sgt.print(1, 1, n);
    return 0;
}