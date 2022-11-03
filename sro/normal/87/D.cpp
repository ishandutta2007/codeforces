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

int n;
map<int, vector<pair<pair<int, int>, int> > > egs;
vector<pair<int, int> > nei[1 << 17];
vector<int> pst;
int siz[1 << 17];
ll res[1 << 17];

struct UnionFind {
	int fa[1 << 17];
	void inline init() {loop(i, 1 << 17) fa[i] = -1;}
	int inline root(int x) {return fa[x] < 0 ? x : fa[x] = root(fa[x]);}
	void inline conn(int a, int b) {
		a = root(a); b = root(b);
		if(a == b) return;
		if(fa[a] < fa[b]) swap(a, b);
		fa[b] += fa[a]; fa[a] = b;
	}
} dsu;

int dfs(int now, int lst, int id) {
	if(id) pst.pub(id);
	siz[id] = -dsu.fa[now];
	foreach(i, nei[now]) {
		if(i->first == lst) continue;
		siz[id] += dfs(i->first, now, i->second);
	}
	nei[now].clear();
	return siz[id];
}

int main() {
	dsu.init();
	scanf("%d", &n);
	cont(i, n - 1) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		egs[c].pub(mak(mak(a, b), i));
	}
	foreach(it, egs) {
		set<int> xs;
		foreach(j, it->second) {
			int x = dsu.root(j->first.first), y = dsu.root(j->first.second);
			xs.insert(x);
			nei[x].pub(mak(y, j->second));
			nei[y].pub(mak(x, j->second));
		}
		foreach(i, xs) {
			if(!SZ(nei[*i])) continue;
			int Sz = dfs(*i, 0, 0);
			foreach(j, pst) res[*j] = 2ll * siz[*j] * (Sz - siz[*j]);
			pst.clear();
		}
		foreach(j, it->second) {
			dsu.conn(j->first.first, j->first.second);
		}
	}
	ll ans = 0;
	cont(i, n - 1) ans = max(ans, res[i]);
	vector<int> ls;
	cont(i, n - 1) if(res[i] == ans) ls.pub(i);
	printf("%lld %d\n", ans, SZ(ls));
	loop(i, SZ(ls)) printf("%d%c", ls[i], " \n"[i == SZ(ls) - 1]);
	return 0;
}