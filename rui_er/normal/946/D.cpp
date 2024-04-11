//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 505;

int n, m, k, s[N][N], v[N][N], dp[N][N];
char a[N][N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, n) {
		scanf("%s", a[i]+1);
		rep(j, 1, m) s[i][j] = s[i][j-1] + a[i][j] - '0';
		v[i][s[i][m]] = m;
		rep(l, 1, m) rep(r, l, m) chkmax(v[i][s[i][m]-s[i][r]+s[i][l-1]], m-r+l-1);
	}
	rep(i, 1, n) per(j, s[i][m], 0) per(p, k, j) chkmax(dp[i][p], dp[i-1][p-j]+v[i][j]);
	printf("%d\n", n*m-dp[n][k]);
	return 0;
}