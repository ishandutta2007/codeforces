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

int n, q;
vector<int> nei[1 << 17];
int dfn[1 << 17], tmc;
int fa[18][1 << 17], lvl[1 << 17];

void dfs(int now, int lst) {
	fa[0][now] = lst; lvl[now] = lvl[lst] + 1;
	cont(i, 17) fa[i][now] = fa[i - 1][fa[i - 1][now]];
	dfn[now] = ++tmc;
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		if(to == lst) continue;
		dfs(to, now);
	}
}

int lca(int a, int b) {
	if(lvl[a] > lvl[b]) swap(a, b);
	int up = lvl[b] - lvl[a];
	loop(i, 18) if((up >> i) & 1) b = fa[i][b];
	if(a == b) return a;
	range(i, 17, 0, -1) if(fa[i][a] != fa[i][b]) a = fa[i][a], b = fa[i][b];
	return fa[0][a];
}

bool inline DfnLess(int a, int b) {return dfn[a] < dfn[b];}

vector<int> son[1 << 17];
int lgl[1 << 17];
vector<int> stk;
bool valid;
int gg[1 << 17];
int res;

void inline add(int a) {
	if(a == 1) return;
	int lc = lca(a, stk.back());
	if(lc != stk.back()) {
		while(dfn[lc] <= dfn[stk[stk.size() - 2]]) {
			son[stk[stk.size() - 2]].pub(stk.back());
			stk.pob();
		}
		if(lc != stk.back()) {
			son[lc].pub(stk.back());
			stk.pob(); stk.pub(lc);
		}
	}
	stk.pub(a);
}

void inline check(int now) {
	int sm = 0;
	loop(i, SZ(son[now])) {
		int to = son[now][i];
		if(fa[0][to] == now && lgl[now] == q && lgl[to] == q) valid = 0;
		check(to);
		sm += gg[to];
	}
	if(lgl[now] == q) {
		res += sm;
		gg[now] = 1;
	} else {
		if(!sm) gg[now] = 0;
		else if(sm == 1) gg[now] = 1;
		else res++, gg[now] = 0;
	}
	son[now].clear();
}

int main() {
	scanf("%d", &n);
	cont(i, n - 1) {
		int a, b; scanf("%d%d", &a, &b);
		nei[a].pub(b); nei[b].pub(a);
	}
	dfs(1, 0);
	scanf("%d", &q);
	memset(lgl, -1, sizeof(lgl));
	while(q--) {
		vector<int> is;
		int len; scanf("%d", &len);
		is.resize(len);
		loop(i, len) scanf("%d", &is[i]), lgl[is[i]] = q;
		sort(all(is), DfnLess);
		stk.clear(); stk.pub(0); stk.pub(1);
		loop(i, len) add(is[i]);
		while(stk.size() > 2) {
			son[stk[stk.size() - 2]].pub(stk.back());
			stk.pob();
		}
		res = 0; valid = 1;
		check(1);
		if(!valid) puts("-1");
		else printf("%d\n", res);
	}
	return 0;
}