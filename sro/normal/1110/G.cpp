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

int n;
vector<int> nei[500005];
int deg[500005];
int is[500005];

void dfs(int now, int lst) {
	if (SZ(nei[now]) == 1) return;
	parse(to, nei[now]) {
		if (to == lst) continue;
		dfs(to, now);
		if (SZ(nei[now]) == 2 && is[to]) is[now] = 3 ^ is[to];
		if ((is[to] == 1 || is[to] == 7) && SZ(nei[now]) >= 3) throw 0;
	}
	if (SZ(nei[now]) == 3) is[now] = 4;
}

char tmp[500005];

void solve() {
	scanf("%d", &n);
	cont(i, n) nei[i].clear(), deg[i] = 0, is[i] = 0;
	cont(i, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		++deg[u], ++deg[v];
		nei[u].pub(v); nei[v].pub(u);
	}
	scanf("%s", tmp + 1);
	int kk = 0;
	cont(i, n) if (tmp[i] == 'W') is[i] = 1, ++kk;
	if (n <= 2) return void(puts("Draw"));
	if (kk < 2 && n == 3) return void(puts("Draw"));
	cont(i, n) {
		if (deg[i] > 1 && is[i]) return void(puts("White"));
		if (deg[i] == 1 && deg[nei[i][0]] > 2 && is[i]) return void(puts("White"));
		if (deg[i] == 2 && deg[nei[i][0]] > 2 && deg[nei[i][1]] > 2)  return void(puts("White"));
		if (deg[i] >= 4) return void(puts("White"));
		int bs = 0;
		parse(to, nei[i]) if (is[to]) ++bs;
		if (bs >= 2) return void(puts("White"));
	}
	if (n == 3) return void(puts("Draw"));
	int mxdeg = 0;
	cont(i, n) mxdeg = max(mxdeg, deg[i]);
	if (mxdeg == 2) {
		if (kk == 2 && n % 2 == 0) {
			bool is = 0;
			cont(i, n) if (deg[i] == 2 && ::is[i]) is = 1;
			if (!is) return void(puts("Draw"));
		}
		if (kk >= 2) return void(puts("White"));
		return void(puts("Draw"));
	}
	cont(i, n) if (deg[i] == 3) {
		int ss = 0;
		parse(to, nei[i]) if (deg[to] >= 2) ++ss;
		if (ss >= 2) return void(puts("White"));
	}
	int rt = 0;
	cont(i, n) if (deg[i] == 3) rt = i;
	try { dfs(rt, 0); } catch (int) { return void(puts("White")); }
	cont(i, n) if (is[i] != 2) {
		int bs = 0;
		parse(to, nei[i]) if (is[to] == 1) ++bs;
		if (bs >= 2) return void(puts("White"));
	}
	return void(puts("Draw"));
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}
/*

1
4
1 2
1 3
1 4
0

*/