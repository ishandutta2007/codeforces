//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 1e6+5, M = 5e5+5, X = 1e5+5, S = 1000, K = 1005;

int n, m, a[N], tot, ans[M], zero[N];
struct Query {
	int op, l, r, x;
	Query(int a=0, int b=0, int c=0, int d=0) : op(a), l(b), r(c), x(d) {}
	~Query() {}
}q[M];

namespace DSU {
	int fa[N], rt[N], sz[N], val[N];
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	void merge(int x, int y) {
		if(rt[y]) fa[rt[x]] = rt[y];
		else val[rt[y]=rt[x]] = y;
		sz[y] += sz[x];
		rt[x] = sz[x] = 0;
	}
}
namespace Blocks {
	int L[K], R[K], bel[N];
	#define whichBlock(x) ((x-1)/S+1)
	void init() {
		tot = whichBlock(n);
		rep(i, 1, n) bel[i] = whichBlock(i);
		rep(i, 1, tot) {
			L[i] = R[i-1] + 1;
			R[i] = i * S;
		}
		R[tot] = n;
	}
	#undef whichBlock
	struct Block {
		int l, r, tag, ma;
		Block(int a=0, int b=0, int c=0, int d=0) : l(a), r(b), tag(c), ma(d) {}
		~Block() {}
		void clear() {
			rep(i, l, r) {
				a[i] = DSU::val[DSU::find(i)];
				DSU::rt[a[i]] = DSU::sz[a[i]] = 0;
				a[i] -= tag;
			}
			rep(i, l, r) DSU::fa[i] = 0;
			tag = 0;
		}
		void build() {
			ma = 0;
			rep(i, l, r) {
				if(!DSU::rt[a[i]]) {
					DSU::rt[a[i]] = i;
					DSU::fa[i] = i;
					DSU::val[i] = a[i];
				}
				else DSU::fa[i] = DSU::rt[a[i]];
				++DSU::sz[a[i]];
				ma = max(ma, a[i]);
			}
		}
		void modifyAll(int x) {
			if(ma - tag >= (x << 1)) {
				rep(i, tag+1, tag+x) if(DSU::rt[i]) DSU::merge(i, i+x);
				tag += x;
			}
			else {
				per(i, ma, tag+x+1) if(DSU::rt[i]) DSU::merge(i, i-x);
				ma = min(ma, tag+x);
			}
		}
		void rebuild(int x, int ql, int qr) {
			if(ql > qr) return;
			clear();
			rep(i, ql, qr) if(a[i] > x) a[i] -= x;
			build();
		}
		void modify(int x, int ql, int qr) {
			if(ql <= l && r <= qr) modifyAll(x);
			else rebuild(x, max(ql, l), min(qr, r));
		}
		int queryAll(int x) {return (x + tag > M - 5) ? 0 : DSU::sz[x+tag];}
		int queryPart(int x, int ql, int qr) {
			int res = 0;
			rep(i, ql, qr) res += DSU::val[DSU::find(i)] - tag == x;
			return res;
		}
		int query(int x, int ql, int qr) {
			if(ql <= l && r <= qr) return queryAll(x);
			return queryPart(x, max(ql, l), min(qr, r));
		}
	}block;
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]), zero[i] = zero[i-1] + !a[i];
	rep(i, 1, m) scanf("%d%d%d%d", &q[i].op, &q[i].l, &q[i].r, &q[i].x);
	Blocks::init();
	rep(i, 1, tot) {
		Blocks::block = Blocks::Block(Blocks::L[i], Blocks::R[i]);
		Blocks::block.build();
		rep(j, 1, m) {
			if(!q[j].x) {
				if(q[j].op == 1) continue;
				else ans[j] += zero[q[j].r] - zero[q[j].l-1];
			}
			else if(q[j].op == 1) Blocks::block.modify(q[j].x, q[j].l, q[j].r);
			else ans[j] += Blocks::block.query(q[j].x, q[j].l, q[j].r);
		}
		Blocks::block.clear();
	}
	rep(i, 1, m) if(q[i].op == 2) printf("%d\n", ans[i]);
	return 0;
}