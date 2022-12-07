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
int e[444][444];
int d[444][444][2];

int q[4000444];
int q1, q2;

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		e[x][y] = e[y][x] = 1;
	}
	d[0][0][0] = 1;
	q[q1++] = 0;
	q[q1++] = 0;
	q[q1++] = 0;
	while (q1 != q2) {
		int x = q[q2++];
		int y = q[q2++];
		int z = q[q2++];

		if (z == 0) {
			if (x == n - 1) {
				if (d[x][y][1] == 0) {
					d[x][y][1] = d[x][y][z] + 1;
					q[q1++] = x;
					q[q1++] = y;
					q[q1++] = 1;
				}
			} else {
				for (int i = 0; i < n; i++) if (i != x && e[x][i] == 0 && d[i][y][1] == 0) {
					d[i][y][1] = d[x][y][z] + 1;
					q[q1++] = i;
					q[q1++] = y;
					q[q1++] = 1;
				}
			}
		} else {
			if (y == n - 1) {
				if (d[x][y][0] == 0) {
					d[x][y][0] = d[x][y][z] + 1;
					q[q1++] = x;
					q[q1++] = y;
					q[q1++] = 0;
				}
			} else {
				for (int i = 0; i < n; i++) if (i != y && e[y][i] == 1 && d[x][i][0] == 0) {
					if (x != n - 1 && i == x) continue;
					d[x][i][0] = d[x][y][z] + 1;
					q[q1++] = x;
					q[q1++] = i;
					q[q1++] = 0;
				}
			}
		}
	}
	int ans = d[n - 1][n - 1][0] / 2;
	if (ans == 0) ans = -1;
	cout << ans << endl;
	return 0;
}