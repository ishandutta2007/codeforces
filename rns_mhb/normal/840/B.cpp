#include <bits/stdc++.h>
using namespace std;
#define N 300010
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
#define fi first
#define se second
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;

int n, m, d[N];
vector<pii> g[N];
bool flag, cnt, vis[N];
vector<int> rlt;

bool dfs(int u) {
	vis[u] = 1;
	bool tmp = 0;
	for (int i = 0; i < g[u].size(); i ++) {
		int v = g[u][i].fi;
		if (vis[v]) continue;
		if (dfs(v)) {
			tmp ^= 1;
			if (g[u][i].se) rlt.pb(g[u][i].se);
		}
	}
	if (d[u] == 1) tmp ^= 1;
	return tmp;
}

int main() {
	scanf("%d%d", &n, &m);
	flag = cnt = 0;
	int sp;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", d + i);
		if (d[i] < 0) flag = 1, sp = i;
		if (d[i] > 0) cnt ^= 1;
	}
	int u, v;
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d", &u, &v);
		g[u].pb(mp(v, i));
		g[v].pb(mp(u, i));
	}
	if (!flag && cnt) puts("-1");
	else {
		if (cnt) d[sp] = 1;
		int rt = 0;
		g[rt].clear();
		g[rt].pb(mp(1, 0));
		dfs(0);
		printf("%d\n", rlt.size());
		for (int i = 0; i < rlt.size(); i ++) printf("%d\n", rlt[i]);
	}
    return 0;
}