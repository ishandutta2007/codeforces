//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 5e5+5, inf = 0x3f3f3f3f;

int n, m, a[N], pre[N], ans[N];
map<int, int> pos;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int w;
	Node(int a=inf) : w(a) {}
	~Node() {}
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void pushup(int u) {
		t[u].w = min(t[lc(u)].w, t[rc(u)].w);
	}
	void insert(int u, int l, int r, int pos, int k) {
		if(l == r) {
			chkmin(t[u].w, k);
			return;
		}
		int mid = (l + r) >> 1;
		if(pos <= mid) insert(lc(u), l, mid, pos, k);
		else insert(rc(u), mid+1, r, pos, k);
		pushup(u);
	}
	int query(int u, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) return t[u].w;
		int mid = (l + r) >> 1, ans = inf;
		if(ql <= mid) chkmin(ans, query(lc(u), l, mid, ql, qr));
		if(qr > mid) chkmin(ans, query(rc(u), mid+1, r, ql, qr));
		return ans;
	}
	#undef lc
	#undef rc
}sgt;
struct Query {
	int l, r, id;
}q[N];
vector<Query> Q[N];

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		pre[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	rep(i, 1, m) {
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	sort(q+1, q+1+m, [](const Query& a, const Query& b) {
		return a.r < b.r;
	});
	rep(i, 1, m) Q[q[i].r].push_back(q[i]);
	rep(i, 1, n) {
		if(pre[i]) sgt.insert(1, 1, n, pre[i], i-pre[i]);
		for(auto j : Q[i]) ans[j.id] = sgt.query(1, 1, n, j.l, j.r);
	}
	rep(i, 1, m) printf("%d\n", ans[i]==inf?-1:ans[i]);
	return 0;
}