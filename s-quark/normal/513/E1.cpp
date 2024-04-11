#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const int MAXN = 31234;
const int MAXM = 212;

int _f[MAXN][MAXM][5][3];
/*
 * f[0..n][0..m][-2..2][-1..1]
 * f[i][j][x][y]: x for current segment, y for between cur and next(+1 for cur>next).
 */
int (*f)[MAXM][5][3] = (int(*)[MAXM][5][3])&_f[0][0][2][1];
int a[MAXN];

inline void up(int &a, int b){
	a = max(a, b);
}

int main(){
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n, m;
	int i, j, k, x, y;

	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	memset(_f, -100, sizeof _f);
	f[0][0][0][0] = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j <= m; j++)
			for(x = -2; x <= 2; x++)
				for(y = -1; y <= 1; y++)
					if(f[i][j][x][y] >= int(-1e9)){
						//continue cur
						up(f[i+1][j][x][y], f[i][j][x][y] + x*a[i]);

						//end cur
						up(f[i+1][j][0][y], f[i][j][x][y]);

						//new seg
						if(j < m){
							for(k = -1; k <= 1; k++)
								up(f[i+1][j+1][-y+k][k], f[i][j][x][y] + (-y+k)*a[i]);
						}
					}

	int ans = -1;
	for(x = -2; x <= 2; x++)
		up(ans, f[n][m][x][0]);
	printf("%d\n", ans);
	return 0;
}