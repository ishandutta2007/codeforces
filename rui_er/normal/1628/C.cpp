//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int T, n, a[N][N], bk[N][N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		ans = 0;
		scanf("%d", &n);
		rep(i, 1, n) rep(j, 1, n) scanf("%d", &a[i][j]);
		rep(i, 2, n) {
			rep(j, 1, n) {
				if(!bk[i-1][j]) {
					ans ^= a[i][j];
					bk[i-1][j] ^= 1;
					bk[i][j-1] ^= 1;
					bk[i][j+1] ^= 1;
					bk[i+1][j] ^= 1;
//					printf("%d,%d\n", i, j);
				}
			}
		}
		printf("%d\n", ans);
		rep(i, 0, n+1) rep(j, 0, n+1) bk[i][j] = 0;
	}
	return 0;
}