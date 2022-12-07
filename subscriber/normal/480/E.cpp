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
#define N 2111
using namespace std;
typedef pair<int,int> pt;

int n, m, k;
char a[N][N];
int up[N][N], down[N][N];
int q[N], qq[N];  
int x[N], y[N];
int ans[N];

bool can(int r, int d) {
	if (d > min(n, m)) return 0;
	
	int q1 = 0, q2 = 0;

	int qq1 = 0, qq2 = 0;

	for (int i = 0; i < m; i++) {
		while (q1 > q2 && up[r][q[q1 - 1]] >= up[r][i]) q1--;
		q[q1++] = i;

		while (qq1 > qq2 && down[r][qq[qq1 - 1]] >= down[r][i]) qq1--;
		qq[qq1++] = i;

		if (i >= d) {
			if (q[q2] == i - d) q2++;
			if (qq[qq2] == i - d) qq2++;
		}

		if (i >= d - 1) {
			int val = up[r][q[q2]] + down[r][qq[qq2]] - 1;
			if (val >= d) return 1;
		}
	}
	return 0;


}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	scanf("%d%d%d\n", &n, &m, &k);
	for (int i = 0; i < n; i++) gets(a[i]);

	int cur = 0;
	
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &x[i], &y[i]);
		x[i]--;
		y[i]--;
		a[x[i]][y[i]] = 'X';
	}		


	for (int i = 0; i < m; i++) up[0][i] = (a[0][i] == '.');
	
	for (int i = 0; i < m; i++) down[n - 1][i] = (a[n - 1][i] == '.');

	for (int i = 1; i < n; i++) for (int j = 0; j < m; j++) {
		if (a[i][j] == 'X') up[i][j] = 0; else up[i][j] = 1 + up[i - 1][j];
	}


	for (int i = n - 2; i >= 0; i--) for (int j = 0; j < m; j++) {
		if (a[i][j] == 'X') down[i][j] = 0; else down[i][j] = 1 + down[i + 1][j];
	}
	

	for (int i = 0; i < n; i++) {
		while (can(i, cur + 1)) cur++;
	}

	for (int ii = k - 1; ii >= 0; ii--) {
		ans[ii] = cur;

		a[x[ii]][y[ii]] = '.';
		int c = y[ii];

		up[0][c] = (a[0][c] == '.');
		down[n - 1][c] = (a[n - 1][c] == '.');

		for (int i = 1; i < n; i++) {
			if (a[i][c] == 'X') up[i][c] = 0; else up[i][c] = 1 + up[i - 1][c];
		}

		for (int i = n - 2; i >= 0; i--) {
			if (a[i][c] == 'X') down[i][c] = 0; else down[i][c] = 1 + down[i + 1][c];
		}

		while (can(x[ii], cur + 1)) cur++;
	}

	for (int i = 0; i < k; i++) printf("%d\n", ans[i]);


	return 0;
}