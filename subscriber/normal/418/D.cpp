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
#define M 1000000007
#define N 111111
using namespace std;
typedef pair<int,int> pt;

int d[N], mostd[N];
int pr[21][N], prplus[21][N], prminus[21][N];
int n, m;
vector<int> v[N];
vector<pt> qq[N];
                             
void dfs(int x, int p, int dd) {
	d[x] = dd;
	mostd[x] = 0;
	for (int i = 0; i < v[x].size(); i++) {
		if (v[x][i] == p) continue;
		dfs(v[x][i], x, dd + 1);
		qq[x].pb(mp(-mostd[v[x][i]] - 1, v[x][i]));
		mostd[x] = max(mostd[x], mostd[v[x][i]] + 1);
	}
	qq[x].pb(mp(0, x));
	sort(qq[x].begin(), qq[x].end());
	for (int i = 0; i < v[x].size(); i++) {
		if (v[x][i] == p) continue;
		pr[0][v[x][i]] = x;
		int t = -qq[x][0].F;
		if (qq[x][0].S == v[x][i]) t = -qq[x][1].F;		
		prplus[0][v[x][i]] = t + d[x];
		prminus[0][v[x][i]] = t - d[x];
	}
}

int lca(int x, int y) {
	for (int i = 19; i >= 0; i--) if (pr[i][x] != -1 && d[pr[i][x]] >= d[y]) x = pr[i][x];
	for (int i = 19; i >= 0; i--) if (pr[i][y] != -1 && d[pr[i][y]] >= d[x]) y = pr[i][y];
	for (int i = 19; i >= 0; i--) if (pr[i][x] != -1 && pr[i][x] != pr[i][y]) {
		x = pr[i][x];
		y = pr[i][y];
	}
	if (x == y) return x;
	return pr[0][x];
	
}

int solve(int x, int y, int z) {
	int mid = x;
	for (int i = 19; i >= 0; i--) if (pr[i][mid] != -1) {
		int to = pr[i][mid];
		if (d[to] < d[z]) continue;
		int distx = abs(d[x] - d[to]);
		int disty = abs(d[z] - d[to]) + abs(d[z] - d[y]);
		if (disty >= distx) mid = to;
	}
	int ans = 0;
	if (x != z) ans = mostd[x];
	int q = x;
	for (int i = 19; i >= 0; i--) if (pr[i][q] != -1 && d[pr[i][q]] >= d[mid]) {
		if (pr[i][q] == z) continue;
		ans = max(ans, prminus[i][q] + d[x]);
		q = pr[i][q];
	}
	for (int i = 19; i >= 0; i--) if (pr[i][q] != -1 && d[pr[i][q]] > d[z]) {
		ans = max(ans, prplus[i][q] + d[y] - 2 * d[z]);
		q = pr[i][q];
	}
	return ans;
}

int solve2(int x, int dd) {
	int ans = 0;
	int q = x;
	for (int i = 19; i >= 0; i--) if (pr[i][q] != -1) {
		ans = max(ans, prminus[i][q] + dd);
		q = pr[i][q];
	}
	return ans;
}	


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i = 1; i< n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	for (int i = 0; i < n; i++) pr[0][i] = -1;
	dfs(0, -1, 0);
	for (int i = 1; i < 20; i++) for (int j = 0; j < n; j++) {
		if (pr[i - 1][j] == -1) {
			pr[i][j] = -1;
			continue;
		}
		pr[i][j] = pr[i - 1][pr[i - 1][j]];
		prplus[i][j] = max(prplus[i - 1][j], prplus[i - 1][pr[i - 1][j]]);
		prminus[i][j] = max(prminus[i - 1][j], prminus[i - 1][pr[i - 1][j]]);
	}
	cin >> m;
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		int z = lca(x, y);

		int q1 = solve(x, y, z);
		int q2 = solve(y, x, z);
		int out = max(q1, q2);
		if (d[x] > d[y]) swap(x, y);
		int dd = d[x];
		for (int i = 19; i >= 0; i--) if (pr[i][x] != -1 && d[pr[i][x]] > d[z]) x = pr[i][x];
		for (int i = 19; i >= 0; i--) if (pr[i][y] != -1 && d[pr[i][y]] > d[z]) y = pr[i][y];
		out = max(out, solve2(z, dd));
		int h = 0;
		while (qq[z][h].S == x || qq[z][h].S == y) h++;
		if (h < qq[z].size()) out = max(out, -qq[z][h].F + dd - d[z]);
		printf("%d\n", out);
	}
	return 0;
}