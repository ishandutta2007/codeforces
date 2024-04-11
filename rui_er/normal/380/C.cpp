//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n, m;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int L, R;
	Node(int a=0, int b=0) : L(a), R(b) {}
	~Node() {}
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void pushup(Node& u, const Node& l, const Node& r) {
		int match = min(l.L, r.R);
		u.L = l.L + r.L - match;
		u.R = l.R + r.R - match;
	}
	void build(int u, int l, int r) {
		if(l == r) {
			t[u].L = s[l] == '(';
			t[u].R = s[l] == ')';
			return;
		}
		int mid = (l + r) >> 1;
		build(lc(u), l, mid);
		build(rc(u), mid+1, r);
		pushup(t[u], t[lc(u)], t[rc(u)]);
	}
	Node query(int u, int l, int r, int ql, int qr) {
		if(r < ql || qr < l) return Node();
		if(ql <= l && r <= qr) return t[u];
		int mid = (l + r) >> 1;
		Node ans(0, 0);
		pushup(ans, query(lc(u), l, mid, ql, qr), query(rc(u), mid+1, r, ql, qr));
		return ans;
	}
	#undef lc
	#undef rc
}sgt;

int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	sgt.build(1, 1, n);
	for(scanf("%d", &m);m;m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		Node ans = sgt.query(1, 1, n, l, r);
		printf("%d\n", (r-l+1)-ans.L-ans.R);
	}
    return 0;
}