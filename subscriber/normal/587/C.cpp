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
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, m, q;
int d[N];
int pr[19][N];

int li[19][N][11];

int as[11], as2[11];

vector<int> pe[N];
vector<int> v[N];

void dfs(int x, int dd, int p) {
	pr[0][x] = p;
	d[x] = dd;
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (to == p) continue;
		dfs(to, dd + 1, x);
	}
}

int lca(int x, int y) {
	for (int i = 17; i >= 0; i--) if (pr[i][x] != -1 && d[pr[i][x]] >= d[y]) x = pr[i][x];
	for (int i = 17; i >= 0; i--) if (pr[i][y] != -1 && d[pr[i][y]] >= d[x]) y = pr[i][y];

	if (x == y) return x;

	for (int i = 17; i >= 0; i--) if (pr[i][x] != -1 && pr[i][y] != -1 && pr[i][x] != pr[i][y]) {
		x = pr[i][x];
		y = pr[i][y];
	}
	return pr[0][x];
}

void merg(int w, int g) {
	int u1 = 0;
	int u2 = 0;

	while (u1 + u2 < 10) {
		if (u2 == 10 || u1 < 10 && li[w][g][u1] <= as[u2]) {
			as2[u1 + u2] = li[w][g][u1];
			u1++;
		} else {
			as2[u1 + u2] = as[u2];
			u2++;
		}
	}
	for (int i = 0; i < 10; i++) as[i] = as2[i];
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m >> q;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		pe[x - 1].pb(i);
	}
	dfs(0, 0, -1);
	for (int i = 0; i < n; i++) {
		sort(pe[i].begin(), pe[i].end());
		for (int j = 0; j < 10; j++) li[0][i][j] = m + 5;
		int g = min(10, (int)pe[i].size());
		for (int j = 0; j < g; j++) li[0][i][j] = pe[i][j];
	}		
	for (int w = 1; w <= 17; w++) for (int i = 0; i < n; i++) {
		if (pr[w - 1][i] == -1) {
			pr[w][i] = -1;
			continue;
		}
		pr[w][i] = pr[w - 1][pr[w - 1][i]];
		if (pr[w][i] == -1) continue;

		int u1 = 0;
		int u2 = 0;

		int x1 = i;
		int x2 = pr[w - 1][i];

		while (u1 + u2 < 10) {
			if (u2 == 10 || u1 < 10 && li[w - 1][x1][u1] <= li[w - 1][x2][u2]) {
				li[w][i][u1 + u2] = li[w - 1][x1][u1];
				u1++;								
			} else {
				li[w][i][u1 + u2] = li[w - 1][x2][u2];
				u2++;
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int x, y, aa;
		scanf("%d%d%d", &x, &y, &aa);
		x--;
		y--;
		int z = lca(x, y);

		for (int j = 0; j < 10; j++) as[j] = m + 5;
		for (int j = 17; j >= 0; j--) if (pr[j][x] != -1 && d[pr[j][x]] >= d[z]) {
			merg(j, x);
			x = pr[j][x];
		}
		for (int j = 17; j >= 0; j--) if (pr[j][y] != -1 && d[pr[j][y]] >= d[z]) {
			merg(j, y);
			y = pr[j][y];
		}
		merg(0, z);

		int k = aa;
		while (k >= 1 && as[k - 1] == m + 5) k--;
		printf("%d", k);
		for (int i = 0; i < k; i++) printf(" %d", as[i] + 1);
		puts("");
	}
	return 0;
}