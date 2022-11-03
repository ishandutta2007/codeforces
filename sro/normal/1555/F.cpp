#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

const int maxn = 1000005;
int N, Q;

struct LinkCutTree {
	int ch[maxn][2], fa[maxn];
	int val[maxn], xval[maxn], ban[maxn];
	int tag[maxn];
	#define LS ch[now][0]
	#define RS ch[now][1]

	void inline Ban(int id) {
		ban[id] = 1;
		if (id > N) val[id] = -1;
		xval[id] = -1;
	}
	void inline pu(int now) {
		if (!~xval[LS] || !~xval[RS] || !~val[now]) xval[now] = -1;
		else xval[now] = xval[LS] ^ xval[RS] ^ val[now];
	}
	void inline pd(int now) {
		if (tag[now]) {
			swap(LS, RS);
			if (LS) tag[LS] ^= 1;
			if (RS) tag[RS] ^= 1;
			tag[now] = 0;
		}
		if (ban[now]) {
			if (LS) Ban(LS);
			if (RS) Ban(RS);
			ban[now] = 0;
		}
	}
	bool inline get(int now) { return ch[fa[now]][1] == now; }
	bool inline isroot(int now) { return ch[fa[now]][get(now)] != now; }
	void inline rotate(int x) {
		int y = fa[x], z = fa[y], g = get(x);
		if (!isroot(y)) ch[z][get(y)] = x;
		ch[y][g] = ch[x][!g]; fa[ch[x][!g]] = y;
		ch[x][!g] = y; fa[y] = x; fa[x] = z;
		pu(y); pu(x);
	}
	void inline upd(int x) { if (!isroot(x)) upd(fa[x]); pd(x); }
	void inline splay(int x) {
		upd(x);
		for (int f; f = fa[x], !isroot(x); rotate(x)) {
			if (!isroot(f)) rotate(get(f) == get(x) ? f : x);
		}
	}
	int inline access(int x) {
		int y;
		for (y = 0; x; y = x, x = fa[x]) splay(x), ch[x][1] = y, pu(x);
		return y;
	}
	void inline enroot(int x) { access(x); splay(x); tag[x] ^= 1; pd(x); }
	void inline link(int f, int x) { enroot(x); fa[x] = f; }
	void inline split(int x, int y) { enroot(x); access(y); splay(y); }
	void inline cut(int now, int x) { split(x, now); LS = RS = fa[x] = 0; }
} t;

struct UnionFind {
	int fa[maxn];
	void inline init() { memset(fa, -1, sizeof(fa)); }
	int inline root(int x) { return fa[x] < 0 ? x : fa[x] = root(fa[x]); }
	bool inline conn(int a, int b) {
		a = root(a); b = root(b);
		if (a == b) return 0;
		return fa[b] += fa[a], fa[a] = b, 1;
	}
} uf;

int main() {
	scanf("%d%d", &N, &Q);
	uf.init();
	int nds = N;
	while (Q--) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		if (uf.conn(u, v)) {
			++nds; t.val[nds] = t.xval[nds] = w;
			t.link(u, nds); t.link(nds, v);
			puts("yes");
		}
		else {
			t.split(u, v);
			if (~t.xval[v] && (t.xval[v] ^ w) == 1) {
				t.Ban(v);
				puts("yes");
			}
			else puts("no");
		}
	}
	return 0;
}