/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
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

template<int siz> struct UndoableUnionFind {
	int fa[siz + 5], ops;
	vector<pair<pair<int, int>, pair<int, int> > > pr;
	void inline init() {memset(fa, -1, sizeof(fa)); pr.clear(); ops = 0;}
	UndoableUnionFind() {init();}
	int inline root(int x) {return fa[x] < 0 ? x : root(fa[x]);}
	bool inline conn(int a, int b) {
		a = root(a); b = root(b);
		if(a == b) return 0;
		if(fa[a] < fa[b]) swap(a, b);
		pr.pub(mak(mak(a, fa[a]), mak(b, fa[b])));
		return fa[b] += fa[a], fa[a] = b, ops++, 1;
	}
	void inline undo() {
		pair<pair<int, int>, pair<int, int> > p = pr.back();
		pr.pob(); ops--;
		fa[p.first.first] = p.first.second;
		fa[p.second.first] = p.second.second;
	}
	void inline undo(int op) {
		while(ops > op) undo();
	}
};

UndoableUnionFind<1 << 17> uf;

struct Event {
	int u, v, w, d, mode;
	Event(): mode(0) {}
	Event(int u, int v, int w, int d, int mode = 0): u(u), v(v), w(w), d(d), mode(mode) {}
};

int n, q, k, m;
vector<Event> ev;
queue<Event> es;
vector<pair<int, int> > qrs[1 << 20];
int ent[1 << 20];
int ans[1 << 20];

struct Segtree {
	vector<int> dt[1 << 22];
	void inline add(int l, int r, int x, int now = 1, int nl = 0, int nr = m) {
		if(nl >= l && nr <= r) {
			dt[now].pub(x);
			return;
		}
		if(nl > r || nr < l) return;
		int m = (nl + nr) >> 1;
		add(l, r, x, now << 1, nl, m);
		add(l, r, x, now << 1 | 1, m + 1, nr);
	}
	void inline parse(int now = 1, int nl = 0, int nr = m) {
		int op = uf.ops;
		loop(i, SZ(dt[now])) {
			int id = dt[now][i];
			uf.conn(ev[id].u, ev[id].v);
		}
		if(nl == nr) {
			loop(i, SZ(qrs[nl])) {
				int u = qrs[nl][i].first, id = qrs[nl][i].second;
				ans[id] = -uf.fa[uf.root(u)];
			}
		} else {
			int m = (nl + nr) >> 1;
			parse(now << 1, nl, m);
			parse(now << 1 | 1, m + 1, nr);
		}
		uf.undo(op);
	}
} seg;

int main() {
	memset(ans, -1, sizeof(ans));
	scanf("%d%d%d", &n, &q, &k);
	loop(i, q << 1) ent[i] = Inf;
	int ds = 0;
	cont(i, q) {
		int t; scanf("%d", &t);
		if(t == 3) {
			ds++;
			ev.pub(Event());
			while(SZ(es) && es.front().d <= ds - k) {
				Event e = es.front(); es.pop();
				ent[e.w] = SZ(ev);
				ev.pub(Event(e.u, e.v, e.w, ds, -1));
			}
		} else if(t == 1) {
			int u, v; scanf("%d%d", &u, &v);
			Event e(u, v, i, ds, 1);
			ev.pub(e); es.push(e);
		} else {
			int u; scanf("%d", &u);
			qrs[SZ(ev)].pub(mak(u, i));
		}
	}
	m = SZ(ev);
	loop(i, m) {
		if(ev[i].mode != 1) continue;
		int en = ent[ev[i].w];
		seg.add(i + 1, en, i);
	}
	seg.parse();
	cont(i, q) if(~ans[i]) printf("%d\n", ans[i]);
	return 0 & puts("");
}