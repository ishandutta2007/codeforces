//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5, K = 20; 

int n, m, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int len, w, tag;
	Node(int a=0, int b=0, int c=0) : len(a), w(b), tag(c) {}
	~Node() {}
};
struct Sgt {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void pushup(int u) {
		t[u].w = t[lc(u)].w + t[rc(u)].w;
	}
	void pushdown(int u) {
		if(!t[u].tag) return;
		t[lc(u)].tag ^= 1;
		t[rc(u)].tag ^= 1;
		t[lc(u)].w = t[lc(u)].len - t[lc(u)].w;
		t[rc(u)].w = t[rc(u)].len - t[rc(u)].w;
		t[u].tag = 0;
	}
	void build(int u, int l, int r, int id) {
		t[u].len = r - l + 1;
		if(l == r) {
			t[u].w = (a[l] >> id) & 1;
			return;
		}
		int mid = (l + r) >> 1;
		build(lc(u), l, mid, id);
		build(rc(u), mid+1, r, id);
		pushup(u);
	}
	void modify(int u, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) {
			t[u].tag ^= 1;
			t[u].w = t[u].len - t[u].w;
			return;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		if(ql <= mid) modify(lc(u), l, mid, ql, qr);
		if(qr > mid) modify(rc(u), mid+1, r, ql, qr);
		pushup(u);
	}
	int query(int u, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) return t[u].w;
		pushdown(u);
		int mid = (l + r) >> 1, ans = 0;
		if(ql <= mid) ans += query(lc(u), l, mid, ql, qr);
		if(qr > mid) ans += query(rc(u), mid+1, r, ql, qr);
		pushup(u);
		return ans;
	}
}sgt[K];

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 0, K-1) sgt[i].build(1, 1, n, i);
	for(scanf("%d", &m);m;m--) {
		int op, l, r, x;
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1) {
			ll ans = 0;
			rep(i, 0, K-1) ans += (1LL << i) * sgt[i].query(1, 1, n, l, r);
			printf("%lld\n", ans);
		}
		else {
			scanf("%d", &x);
			rep(i, 0, K-1) if((x >> i) & 1) sgt[i].modify(1, 1, n, l, r);
		}
	}
    return 0;
}