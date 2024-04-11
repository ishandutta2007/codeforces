//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n, m, a[N], b[N], pos[N], lst;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int lc, rc, w;
};
struct PersSegTree {
	Node t[N<<5];
	int sz, rt[N];
	int copy(int u) {
		t[++sz] = t[u];
		return sz;
	}
	void pushup(int u) {
		t[u].w = t[t[u].lc].w + t[t[u].rc].w;
	}
	int insert(int u, int l, int r, int k) {
		int v = copy(u);
		if(l == r) {
			++t[v].w;
			return v;
		}
		int mid = (l + r) >> 1;
		if(k <= mid) t[v].lc = insert(t[v].lc, l, mid, k);
		else t[v].rc = insert(t[v].rc, mid+1, r, k);
		pushup(v);
		return v;
	}
	int query(int u, int v, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) return t[v].w - t[u].w;
		int mid = (l + r) >> 1, ans = 0;
		if(ql <= mid) ans += query(t[u].lc, t[v].lc, l, mid, ql, qr);
		if(qr > mid) ans += query(t[u].rc, t[v].rc, mid+1, r, ql, qr);
		return ans;
	}
}sgt;
int decode(int x) {
	return (x + lst - 1) % n + 1;
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	rep(i, 1, n) {
		scanf("%d", &b[i]);
		b[i] = pos[b[i]];
		sgt.rt[i] = sgt.insert(sgt.rt[i-1], 1, n, b[i]);
	}
	for(scanf("%d", &m);m;m--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a = decode(a);
		b = decode(b);
		c = decode(c);
		d = decode(d);
		if(a > b) swap(a, b);
		if(c > d) swap(c, d);
		lst = sgt.query(sgt.rt[c-1], sgt.rt[d], 1, n, a, b);
		printf("%d\n", lst++);
	}
    return 0;
}