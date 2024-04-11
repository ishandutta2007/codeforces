#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct UnionFind {
	int fa[10005];
	void inline init() {memset(fa, -1, sizeof(fa));}
	int inline root(int x) {return fa[x] < 0 ? x : fa[x] = root(fa[x]);}
	bool inline conn(int a, int b) {
		a = root(a); b = root(b);
		if(a == b) return 0;
		if(fa[a] < fa[b]) swap(a, b);
		return fa[b] += fa[a], fa[a] = b, 1;
	}
} uf;

int m, n;
vector<int> ns, stk;
vector<pair<int, int> > egs, nei[10005];
int deg[10005], iter[10005];
map<pair<int, int>, vector<int> > ids;
bool lgl[10005];

void dfs(int now) {
	for (int &i = iter[now]; i < SZ(nei[now]); ++i) {
		int to = nei[now][i].first, id = nei[now][i].second;
		if (lgl[id]) continue;
		lgl[id] = 1; dfs(to);
	}
	stk.pub(now);
}

int main() {
	#ifndef HCl10
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	scanf("%d", &m); uf.init();
	cont(i, m) {
		int a, b; scanf("%d%d", &a, &b);
		egs.emb(a, b); ns.pub(a); ns.pub(b);
	}
	if (m == 1) return puts("-1"), 0;
	sort(all(ns)); ns.erase(unique(all(ns)), ns.end()); n = SZ(ns);
	loop(i, m) {
		int u, v; tie(u, v) = egs[i];
		u = lower_bound(all(ns), u) - ns.begin() + 1;
		v = lower_bound(all(ns), v) - ns.begin() + 1;
		nei[u].emb(v, i + 1); nei[v].emb(u, i + 1);
		++deg[u], ++deg[v];
		uf.conn(u, v);
		ids[mak(u, v)].pub(i + 1);
		ids[mak(v, u)].pub(i + 1);
	}
	
	int ltk = 0;
	cont(i, n) if (uf.root(i) == i) ++ltk;
	if (ltk > 2) return puts("-1"), 0;
	
	if (ltk == 2) {
		vector<int> ls;
		cont(i, n) if (uf.root(i) == i) ls.pub(i);
		// assert(SZ(ls) == 2);
		int ar = ls[0], br = ls[1];
		int am = 0, bm = 0;
		cont(i, n) (uf.root(i) == ar ? am : bm) += (deg[i] & 1);
		if (am > 2 || bm > 2) return puts("-1"), 0;
		int rt = ar;
		cont(i, n) if (uf.root(i) == ar && (deg[i] & 1)) rt = i;
		stk.clear(); dfs(rt);
		printf("%d\n", SZ(stk) - 1);
		loop(i, SZ(stk) - 1) {
			int u = stk[i], v = stk[i + 1];
			int id = ids[mak(u, v)].back();
			ids[mak(u, v)].pob(); ids[mak(v, u)].pob();
			printf("%d ", id);
		}
		puts("");
		rt = br;
		cont(i, n) if (uf.root(i) == br && (deg[i] & 1)) rt = i;
		stk.clear(); dfs(rt);
		printf("%d\n", SZ(stk) - 1);
		loop(i, SZ(stk) - 1) {
			int u = stk[i], v = stk[i + 1];
			int id = ids[mak(u, v)].back();
			ids[mak(u, v)].pob(); ids[mak(v, u)].pob();
			printf("%d ", id);
		}
		return puts(""), 0;
	}

	int ds = 0;
	cont(i, n) if (deg[i] & 1) ++ds;
	if (ds > 4) return puts("-1"), 0;

	if (ds == 4) {
		vector<int> ls;
		cont(i, n) if (deg[i] & 1) ls.pub(i);
		// assert(SZ(ls) == 4);
		nei[ls[2]].emb(ls[3], m + 1);
		nei[ls[3]].emb(ls[2], m + 1);
		ids[mak(ls[2], ls[3])].pub(m + 1);
		ids[mak(ls[3], ls[2])].pub(m + 1);
		dfs(ls[0]);
		vector<int> f[2];
		int cur = 0;
		loop(i, SZ(stk) - 1) {
			int u = stk[i], v = stk[i + 1];
			int id = ids[mak(u, v)].back();
			ids[mak(u, v)].pob(); ids[mak(v, u)].pob();
			if (id == m + 1) ++cur;
			else f[cur].pub(id);
		}
		printf("%d\n", SZ(f[0]));
		parse(i, f[0]) printf("%d ", i);
		printf("\n%d\n", SZ(f[1]));
		parse(i, f[1]) printf("%d ", i);
		return puts(""), 0;
	}
	
	int rt = 1;
	cont(i, n) if (deg[i] & 1) rt = i;
	dfs(rt); printf("%d\n", SZ(stk) - 2);
	loop(i, SZ(stk) - 2) {
		int u = stk[i], v = stk[i + 1];
		int id = ids[mak(u, v)].back();
		ids[mak(u, v)].pob(); ids[mak(v, u)].pob();
		printf("%d ", id);
	}
	puts("\n1");
	int u = stk[SZ(stk) - 2], v = stk.back();
	printf("%d\n", ids[mak(u, v)].back());
	return 0;
}