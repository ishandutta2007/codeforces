//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5, M = 2e7+5, inf = 0x3f3f3f3f; 

int n, k, q, b[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
class ST_Table {
private:
	int lg2[N], id[N][19], pre[N], suf[N], glb;
public:
	void init(int* b, int n) {
		lg2[0] = -1;
		rep(i, 1, N-1) lg2[i] = lg2[i>>1] + 1;
//		memset(id, 0x3f, sizeof(id));
		rep(i, 1, n) id[i][0] = b[i];
		rep(j, 1, 18) {
			rep(i, 1, n-(1<<j)+1) {
				id[i][j] = min(id[i][j-1], id[i+(1<<(j-1))][j-1]);
			}
		}
		pre[1] = b[1];
		rep(i, 2, n) pre[i] = min(pre[i-1], b[i]);
		suf[n] = b[n];
		per(i, n-1, 1) suf[i] = min(suf[i+1], b[i]);
		glb = suf[1];
	}
	int query(int L, int R) {
//		if(R - L + 1 >= N || R - L + 1 < 0) exit(printf("OUT OF BOUNDS [%d, %d] -> %d\n", L, R, R-L+1)&0);
		int k = lg2[R-L+1];
		return min(id[L][k], id[R-(1<<k)+1][k]);
	}
	int queryRange(int L, int R) {
		if(R - L + 1 >= n) return glb;
		if((L - 1) / n + 1 == (R - 1) / n + 1) return query((L-1)%n+1, (R-1)%n+1);
		return min(suf[(L-1)%n+1], pre[(R-1)%n+1]);
	}
}st;
class Node {
public:
	int mn, tag, lc, rc;
};
struct SegTree {
private:
	Node t[M];
	int sz, rt;
public:
	int size() {return sz;}
	int& root() {return rt;}
	void newNode(int& u, int l, int r) {
		if(u) return;
		u = ++sz;
		t[u].mn = st.queryRange(l, r);
	}
	void pushup(int u) {
		t[u].mn = min(t[t[u].lc].mn, t[t[u].rc].mn);
	}
	void pushdown(int u) {
		if(!t[u].tag) return;
		if(!t[u].lc) t[u].lc = ++sz;
		if(!t[u].rc) t[u].rc = ++sz;
		t[t[u].lc].mn = t[t[u].lc].tag = t[u].tag;
		t[t[u].rc].mn = t[t[u].rc].tag = t[u].tag;
		t[u].tag = 0;
	}
	void build() {
		t[0].mn = inf;
	}
	void assign(int& u, int l, int r, int ql, int qr, int val) {
		newNode(u, l, r);
		if(r < ql || qr < l) return;
//		printf("ASSIGN %d(%p) [%d, %d] Q[%d, %d] -> %d\n", u, &u, l, r, ql, qr, val);
		if(ql <= l && r <= qr) {
			t[u].mn = t[u].tag = val;
			return;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		assign(t[u].lc, l, mid, ql, qr, val);
		assign(t[u].rc, mid+1, r, ql, qr, val);
		pushup(u);
//		printf("%d [%d, %d] -> %d\n", u, l, r, t[u].mn);
	}
	int query(int& u, int l, int r, int ql, int qr) {
		newNode(u, l, r);
//		printf("QUERY %d(%p) [%d, %d] Q[%d, %d]\n", u, &u, l, r, ql, qr);
		if(ql <= l && r <= qr) return t[u].mn;
		pushdown(u);
		int mid = (l + r) >> 1, ans = inf;
		if(ql <= mid) chkmin(ans, query(t[u].lc, l, mid, ql, qr));
		if(qr > mid) chkmin(ans, query(t[u].rc, mid+1, r, ql, qr));
		return ans;
	}
}sgt;

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", &b[i]);
	st.init(b, n);
	sgt.build();
	scanf("%d", &q);
	while(q --> 0) {
		int op, l, r, x;
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1) {
			scanf("%d", &x);
			sgt.assign(sgt.root(), 1, n*k, l, r, x);
		}
		else printf("%d\n", sgt.query(sgt.root(), 1, n*k, l, r));
	}
    return 0;
}