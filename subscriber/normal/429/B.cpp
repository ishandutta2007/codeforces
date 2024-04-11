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
#define y1 ololo
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

int mx[2][2] = {{1, 0}, {0, 1}};
int my[2][2] = {{-1, 0}, {0, 1}};
int n, m;
int a[N][N], x1[N][N], x2[N][N], y1[N][N], y2[N][N];


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
	x1[0][0] = a[0][0];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		for (int u = 0; u < 2; u++) {
			int ii = i + mx[u][0];
			int jj = j + mx[u][1];
			if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
			x1[ii][jj] = max(x1[ii][jj], x1[i][j] + a[ii][jj]);
		}
	}
	x2[n - 1][m - 1] = a[n - 1][m - 1];
	for (int i = n - 1; i >= 0; i--) for (int j = m - 1; j >= 0; j--) {
		for (int u = 0; u < 2; u++) {
			int ii = i - mx[u][0];
			int jj = j - mx[u][1];
			if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
			x2[ii][jj] = max(x2[ii][jj], x2[i][j] + a[ii][jj]);
		}
	}
	
	y1[n - 1][0] = a[n - 1][0];
	for (int i = n - 1; i >= 0; i--) for (int j = 0; j < m; j++) {
		for (int u = 0; u < 2; u++) {
			int ii = i + my[u][0];
			int jj = j + my[u][1];
			if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
			y1[ii][jj] = max(y1[ii][jj], y1[i][j] + a[ii][jj]);
		}
	}

	y2[0][m - 1] = a[0][m - 1];
	for (int i = 0; i < n; i++) for (int j = m - 1; j >= 0; j--) {
		for (int u = 0; u < 2; u++) {
			int ii = i - my[u][0];
			int jj = j - my[u][1];
			if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
			y2[ii][jj] = max(y2[ii][jj], y2[i][j] + a[ii][jj]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		for (int ux1 = 0; ux1 < 2; ux1++)
			for (int ux2 = 0; ux2 < 2; ux2++) {
				int ix1 = i - mx[ux1][0];
				int jx1 = j - mx[ux1][1];
				int ix2 = i + mx[ux2][0];
				int jx2 = j + mx[ux2][1];
				if (ix1 < 0 || ix1 >= n || jx1 < 0 || jx1 >= m) continue;
				if (ix2 < 0 || ix2 >= n || jx2 < 0 || jx2 >= m) continue;
				for (int uy1 = 0; uy1 < 2; uy1++)
					for (int uy2 = 0; uy2 < 2; uy2++) {
						int iy1 = i - my[uy1][0];
						int jy1 = j - my[uy1][1];
						int iy2 = i + my[uy2][0];
						int jy2 = j + my[uy2][1];
						if (iy1 < 0 || iy1 >= n || jy1 < 0 || jy1 >= m) continue;
						if (iy2 < 0 || iy2 >= n || jy2 < 0 || jy2 >= m) continue;
						if (ix1 == iy1 && jx1 == jy1) continue;
						if (ix2 == iy2 && jx2 == jy2) continue;

						if (ix1 == iy2 && jx1 == jy2) continue;
						if (ix2 == iy1 && jx2 == jy1) continue;
						ans = max(ans, x1[ix1][jx1] + x2[ix2][jx2] + y1[iy1][jy1] + y2[iy2][jy2]);
					}
			}
	}
	cout << ans << endl;

	return 0;
}