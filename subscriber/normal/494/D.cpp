#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
vector<pair<int, int> > vv[N];
int sum1[N], sum2[N], kol[N];
int k[N], s1[N], s2[N];

int pr[20][N];
int d[N];
int pl[N];

void dfs(int x, int p) {
	sum1[x] = 0;
	sum2[x] = 0;
	kol[x] = 1;
	for (int i = 0; i < vv[x].size(); i++) {
		int to = vv[x][i].F;
		if (to == p) continue;
		dfs(to, x);
		kol[x] = (kol[x] + kol[to]) % M;

		sum1[x] = (sum1[x] + sum1[to] + vv[x][i].S * 1ll * kol[to]) % M;

		sum2[x] = (sum2[x] + sum2[to] + kol[to] * 1ll * vv[x][i].S % M * vv[x][i].S % M + 2ll * sum1[to] * vv[x][i].S) % M;
	}
}

void dfsd(int x, int p, int KOL, int SUM1, int SUM2) {
	k[x] = (KOL + 1) % M;
	s1[x] = SUM1;
	s2[x] = SUM2;


	int curk = (KOL + 1) % M;
	int curs1 = SUM1;
	int curs2 = SUM2;

	for (int i = 0; i < vv[x].size(); i++) {
		int to = vv[x][i].F;
		if (to == p) continue;

		int v = kol[to];
		int v1 = (sum1[to] + vv[x][i].S * 1ll * kol[to]) % M;
		int v2 = (sum2[to] + kol[to] * 1ll * vv[x][i].S % M * vv[x][i].S % M + 2ll * sum1[to] * vv[x][i].S) % M;

		curk = (curk + v) % M;
		curs1 = (curs1 + v1) % M;
		curs2 = (curs2 + v2) % M;
	}
	for (int i = 0; i < vv[x].size(); i++) {
		int to = vv[x][i].F;
		if (to == p) continue;

		int v = kol[to];
		int v1 = (sum1[to] + vv[x][i].S * 1ll * kol[to]) % M;
		int v2 = (sum2[to] + kol[to] * 1ll * vv[x][i].S % M * vv[x][i].S % M + 2ll * sum1[to] * vv[x][i].S) % M;

		int g = (curk - v + M) % M;
		int g1 = (curs1 - v1 + M) % M;
		int g2 = (curs2 - v2 + M) % M;

		int z = g;
		int z1 = (g1 + g * 1ll * vv[x][i].S) % M;
		int z2 = (g2 + g * 1ll * vv[x][i].S % M * vv[x][i].S % M + 2ll * g1 * vv[x][i].S) % M;
		dfsd(to, x, z, z1, z2);
	}
	
}

void prep(int x, int p, int dd, int len) {
	pl[x] = len;

	d[x] = dd;
	pr[0][x] = p;
	for (int i = 0; i < vv[x].size(); i++) if (vv[x][i].F != p) {
		prep(vv[x][i].F, x, dd + 1, (len + vv[x][i].S) % M);
	}
}

int lca(int x, int y) {
	for (int i = 19; i >= 0; i--) if (d[pr[i][x]] >= d[y]) x = pr[i][x];
	for (int i = 19; i >= 0; i--) if (d[pr[i][y]] >= d[x]) y = pr[i][y];

	for (int i = 19; i >= 0; i--) if (pr[i][x] != pr[i][y]) {
		x = pr[i][x];
		y = pr[i][y];
	}
	if (x == y) return x;
	return pr[0][x];
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i= 0 ; i < n - 1; i++) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		x--;
		y--;
		vv[x].pb(mp(y, c));
		vv[y].pb(mp(x, c));
	}
	prep(0, 0, 0, 0);
	for (int i = 1; i < 20; i++) for (int j = 0; j < n; j++) pr[i][j] = pr[i - 1][pr[i - 1][j]];

	dfs(0, 0);

	dfsd(0, -1, 0, 0, 0);
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		swap(x, y);
		int all = (sum2[y] + s2[y]) % M;
		int ans;

		if (lca(x, y) == x) {

			int d = (pl[y] - pl[x] + M) % M;

			int cs2 = (s2[x] + k[x] * 1ll * d % M * d % M + 2ll * s1[x] * d) % M;
			cs2 = (cs2 - d * 1ll * d + M * 1ll * M) % M;

			ans = (all - cs2 * 2ll + M + M) % M;
		} else {
			int d = (pl[x] + pl[y] - 2ll * pl[lca(x, y)] + M * 1ll * M) % M;

			int cs2 = (sum2[x] + kol[x] * 1ll * d % M * d % M + 2ll * sum1[x] * d) % M;

			ans = (cs2 * 2ll - all + M ) % M;
		}
		printf("%d\n", ans);
	}
	return 0;
}