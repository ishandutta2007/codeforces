// Problem: CF1205B Shortest Cycle
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1205B
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e5+5, M = 150, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, a[N], e[M][M], dis[M][M], ans = inf;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		if(!a[i]) --i, --n;
	}
	if(n > 120) return puts("3")&0;
	memset(e, 0x3f, sizeof(e));
	memset(dis, 0x3f, sizeof(dis));
	rep(i, 1, n) {
		e[i][i] = dis[i][i] = 0;
		rep(j, i+1, n) {
			if(a[i] & a[j]) {
				e[i][j] = e[j][i] = 1;
				dis[i][j] = dis[j][i] = 1;
			}
		}
	}
	rep(k, 1, n) {
		rep(i, 1, k-1) {
			rep(j, 1, i-1) {
				if(dis[i][j] < inf && e[i][k] < inf && e[j][k] < inf) {
					chkmin(ans, dis[i][j]+e[i][k]+e[j][k]);
				}
			}
		}
		rep(i, 1, n) {
			rep(j, 1, n) {
				chkmin(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	printf("%lld\n", ans==inf?-1:ans);
	return 0;
}