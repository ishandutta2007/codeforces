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
#define M 1000000007
#define N 2022
using namespace std;
typedef pair<int,int> pt;

int n;
int e[N][N], d[N][N];
pair<int, pt> q[4000444];
vector<int> v[N];
int was[N];
int T = 0;
vector<pt> W;

void dfs(int x, int dist) {
	if (was[x] == T) return;
	was[x] = T;
	W.pb(mp(x, dist));
	for (int i = 0; i < v[x].size(); i++) dfs(v[x][i], dist + d[x][v[x][i]]);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &e[i][j]);
			if (j > i) q[k++] = mp(e[i][j], mp(i, j));
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (e[i][j] != e[j][i] || (i == j && e[i][j] != 0) || (i != j && e[i][j] == 0)) {
			puts("NO");
			return 0;
		}

	}
	sort(q, q + k);

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = -1;

	for (int i = 0; i < k; i++) {	
		int x = q[i].S.F;
		int y = q[i].S.S;
		if (d[x][y] != -1) {
			if (d[x][y] != e[x][y]) {
				puts("NO");
				return 0;
			}
			continue;
		}
		T++;
		W.clear();
		dfs(x, 0);

		vector<pt> q1 = W;

		T++;
		W.clear();
		dfs(y, 0);

		for (int u = 0; u < q1.size(); u++) for (int uu = 0; uu < W.size(); uu++) {
			int xx = q1[u].F;
			int yy = W[uu].F;
			d[xx][yy] = d[yy][xx] = q[i].F + q1[u].S + W[uu].S;
		}

		v[x].pb(y);
		v[y].pb(x);
	}
	puts("YES");
	return 0;
}