//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 105;

int r, s, p;
double dp[N][N][N], Pr, Ps, Pp;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%d", &r, &s, &p);
	dp[r][s][p] = 1.0;
	per(i, r, 0) {
		per(j, s, 0) {
			per(k, p, 0) {
				int tot = i * j + j * k + k * i;
				if(i && j) dp[i][j-1][k] += dp[i][j][k] * (1.0 * i * j / tot);
				if(j && k) dp[i][j][k-1] += dp[i][j][k] * (1.0 * j * k / tot);
				if(k && i) dp[i-1][j][k] += dp[i][j][k] * (1.0 * k * i / tot);
			}
		}
	}
	rep(i, 1, r) Pr += dp[i][0][0];
	rep(j, 1, s) Ps += dp[0][j][0];
	rep(k, 1, p) Pp += dp[0][0][k];
	printf("%.12lf %.12lf %.12lf\n", Pr, Ps, Pp);
	return 0;
}