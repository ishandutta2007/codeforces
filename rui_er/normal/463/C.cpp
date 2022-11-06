//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e3+5; 

ll n, a[N][N], col[N][N], UL[N][N], UR[N][N], DL[N][N], DR[N][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) {
		rep(j, 1, n) {
			scanf("%lld", &a[i][j]);
			col[i][j] = (i + j) & 1;
		}
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			UL[i][j] = UL[i-1][j-1] + a[i][j];
		}
	}
	rep(i, 1, n) {
		per(j, n, 1) {
			UR[i][j] = UR[i-1][j+1] + a[i][j];
		}
	}
	per(i, n, 1) {
		rep(j, 1, n) {
			DL[i][j] = DL[i+1][j-1] + a[i][j];
		}
	}
	per(i, n, 1) {
		per(j, n, 1) {
			DR[i][j] = DR[i+1][j+1] + a[i][j];
		}
	}
	ll X0 = 0, Y0 = 0, X1 = 0, Y1 = 0, now0 = -1, now1 = -1;
	rep(i, 1, n) {
		rep(j, 1, n) {
			ll qwq = UL[i][j] + UR[i][j] + DL[i][j] + DR[i][j] - 3 * a[i][j];
			ll& x = col[i][j] ? X1 : X0;
			ll& y = col[i][j] ? Y1 : Y0;
			ll& now = col[i][j] ? now1 : now0;
			if(qwq > now) {
				x = i;
				y = j;
				now = qwq;
			}
		}
	}
	printf("%lld\n%lld %lld %lld %lld\n", now0+now1, X0, Y0, X1, Y1);
	return 0;
}