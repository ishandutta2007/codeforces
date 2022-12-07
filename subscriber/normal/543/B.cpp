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

int n, m;
vector<int> v[4444];
int d[3333][3333];
int a[2], b[2], c[2];

int q[3333], q1, q2;

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	for (int i = 0; i < 2; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		a[i]--;
		b[i]--;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) d[i][j] = 1e8;
		d[i][i] = 0;
		q1 = q2 = 0;
		q[q1++] = i;
		while (q1 != q2) {
			int x = q[q2++];
			for (int j = 0; j < v[x].size(); j++) {
				int to = v[x][j];
				if (d[i][to] == 1e8) {
					d[i][to] = d[i][x] + 1;
					q[q1++] = to;
				}
			}			
		}
	}
	if (d[a[0]][b[0]] > c[0] || d[a[1]][b[1]] > c[1]) {
		puts("-1");
		return 0;
	}
	int ans = d[a[0]][b[0]] + d[a[1]][b[1]];
	for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) {
		if (d[a[0]][x] + d[x][y] + d[y][b[0]] > c[0]) continue;
		if (d[a[1]][x] + d[x][y] + d[y][b[1]] > c[1]) continue;

		int t = d[a[0]][x] + d[a[1]][x] + d[x][y] + d[y][b[0]] + d[y][b[1]];
		ans = min(ans, t);
	}
	for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) {
		if (d[a[0]][x] + d[x][y] + d[y][b[0]] > c[0]) continue;
		if (d[b[1]][x] + d[x][y] + d[y][a[1]] > c[1]) continue;
		int t = d[a[0]][x] + d[b[1]][x] + d[x][y] + d[y][b[0]] + d[y][a[1]];
		ans = min(ans, t);
	}
	cout << m - ans << endl;

	return 0;
}