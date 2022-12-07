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
#define N 1011
using namespace std;
typedef pair<int,int> pt;

int n, m;
int ans = 1e9;
char a[N][N], b[N][N];
int was[N][N], e[N][N];

void solve() {
	int x = -1, y = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (a[i][j] == 'X') {
			x = i;
			y = j;
			break;
		}
		if (x != -1) break;
	}		
	int h = 1, w = 1;
	while (y + w < m && a[x][y + w] == 'X') w++;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) was[i][j] = 0;

	for(;;) {
		was[x][y] = 1;
		int right = 0;
		int down = 0;
		if (y + w < m && a[x][y + w] == 'X') right = 1;
		if (x + h < n && a[x + h][y] == 'X') down = 1;
		if (down + right == 0) break;

		if (down + right == 2) {
			h++;
			continue;
		}
		if (down) x++; else y++;
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) e[i][j] = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (was[i][j]) {
		int t = was[i][j];
		e[i][j] += t;
		e[i + h][j] -= t;
		e[i][j + w] -= t;
		e[i + h][j + w] += t;
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (i > 0) e[i][j] += e[i - 1][j];
		if (j > 0) e[i][j] += e[i][j - 1];
		if (i > 0 && j > 0) e[i][j] -= e[i - 1][j - 1];
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		int cov = 0;
		if (e[i][j] > 0) cov = 1;
		if (a[i][j] == 'X' && cov == 0) return;
		if (a[i][j] == '.' && cov == 1) return;
	}
	ans = min(ans, w * h);


}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; i++) gets(a[i]);
	solve();
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) b[i][j] = a[j][i];
	swap(n, m);		

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) a[i][j] = b[i][j];

	solve();
	if (ans == 1e9) ans = -1;
	cout << ans << endl;
			


	return 0;
}