/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

struct Edge {
	int u, v, w;
} e[3 << 17], ei[3 << 17];

struct UnionFind {
	int fa[1 << 17];
	vector<pair<int, int> > op;
	int cnt = 0;
	void inline init() {
		memset(fa, -1, sizeof(fa));
	}
	int inline root(int a) {
		return fa[a] < 0 ? a : root(fa[a]);
	}
	void inline conn(int a, int b) {
		a = root(a); b = root(b);
		if(a == b) return;
		if(fa[a] > fa[b]) swap(a, b);
		cnt += !(fa[a] & 1) * fa[a] + !(fa[b] & 1) * fa[b];
		op.pub(mak(b, fa[b]));
		fa[a] += fa[b]; fa[b] = a;
		cnt -= !(fa[a] & 1) * fa[a];
	}
	void inline undo() {
		pair<int, int> pr = op.back(); op.pob();
		int v = pr.first, u = fa[v], w = pr.second;
		cnt += !(fa[u] & 1) * fa[u];
		fa[u] -= w; fa[v] = w;
		cnt -= !(fa[u] & 1) * fa[u] + !(fa[v] & 1) * fa[v];
	}
} uf;

int n, m;
int id[3 << 17], rk[3 << 17];
int ans[3 << 17];

void inline fendge(int l, int r, int L, int R) {
	if(l > r) return;
	int m = (l + r) >> 1, tag = SZ(uf.op);
	circ(i, l, m) if(rk[i] < L) uf.conn(e[i].u, e[i].v);
	int pos = -1;
	circ(i, L, R) {
		if(id[i] <= m) uf.conn(ei[i].u, ei[i].v);
		if(uf.cnt == n) {
			pos = i;
			break;
		}
	}
	if(!~pos) {
		circ(i, l, m) ans[i] = -1;
		while(SZ(uf.op) > tag) uf.undo();
		circ(i, l, m) if(rk[i] < L) uf.conn(e[i].u, e[i].v);
		fendge(m + 1, r, L, R);
		while(SZ(uf.op) > tag) uf.undo();
		return;
	}
	ans[m] = ei[pos].w;
	while(SZ(uf.op) > tag) uf.undo();
	circ(i, L, pos) if(id[i] < l) uf.conn(ei[i].u, ei[i].v);
	fendge(l, m - 1, pos, R);
	while(SZ(uf.op) > tag) uf.undo();
	circ(i, l, m) if(rk[i] < L) uf.conn(e[i].u, e[i].v);
	fendge(m + 1, r, L, pos);
	while(SZ(uf.op) > tag) uf.undo();
}

int main() {
	scanf("%d%d", &n, &m);
	cont(i, m) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		id[i] = i;
	}
	sort(id + 1, id + m + 1, [&](int a, int b) {return e[a].w < e[b].w;});
	cont(i, m) {
		ei[i] = e[id[i]];
		rk[id[i]] = i;
	}
	uf.init();
	fendge(1, m, 1, m);
	cont(i, m) printf("%d\n", ans[i]);
	return 0;
}