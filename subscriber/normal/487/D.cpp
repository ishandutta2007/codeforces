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

int n, m, q;

char a[N][13];
pair<int, int> g[N][13];

const int C = 120;

void recalc(int l, int r) {
	for (int i = l; i <= r; i++) {
		for (int j = 0; j < m; j++) g[i][j] = mp(i, j);
		if (i == l) {
			for (int j = 0; j < m; j++) if (a[i][j] == '^') g[i][j] = mp(i - 1, j);
		} else {
			for (int j = 0; j < m; j++) if (a[i][j] == '^') g[i][j] = g[i - 1][j];
		}
		if (a[i][0] == '<') g[i][0] = mp(i, -1);
		for (int j = 1; j < m; j++) if (a[i][j] == '<') g[i][j] = g[i][j - 1];

		if (a[i][m - 1] == '>') g[i][m - 1] = mp(i, m);
		for (int j = m - 2; j >= 0; j--) if (a[i][j] == '>') g[i][j] = g[i][j + 1];

/*		for (int j = 0; j < m - 1; j++) if (a[i][j] == '>' && a[i][j + 1] == '<') {
			g[i][j] = mp(i, j);
			g[i][j + 1] = mp(i, j + 1);
		}*/
	}
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	scanf("%d%d%d\n", &n, &m, &q);
	for (int i = 0; i < n; i++) gets(a[i]);

	for (int i = 0; i < n; i += C) recalc(i, min(i + C - 1, n - 1));

	while (q--) {
		char type;
		int x, y;
		scanf("%c", &type);
		if (type == 'A') {
			scanf("%d%d\n", &x, &y);
			x--;
			y--;
			int xx, yy;
			while (x >= 0 && y >= 0 && y < m) {
				xx = g[x][y].F;
				yy = g[x][y].S;
				if (x == xx && yy >= 0 && yy < m) {
					x = xx;
					y = yy;
					break;
				}
				x = xx;
				y = yy;
			}
			if (x >= 0 && y >= 0 && y < m) puts("-1 -1"); else printf("%d %d\n", x + 1, y + 1);
		} else {
			char q;
			scanf("%d%d %c\n", &x, &y, &q);
			x--;
			y--;
			a[x][y] = q;

			recalc(x / C * C, min(x / C * C + C - 1, n - 1));
		}
	}
	

	return 0;
}