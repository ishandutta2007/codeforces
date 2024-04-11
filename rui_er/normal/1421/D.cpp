// Problem: CF1421D Hexagons
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1421D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

ll T, x, y, c1, c2, c3, c4, c5, c6;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &x, &y, &c1, &c2, &c3, &c4, &c5, &c6);
		rep(i, 1, 6) {
			chkmin(c1, c6 + c2);
			chkmin(c2, c1 + c3);
			chkmin(c3, c2 + c4);
			chkmin(c4, c3 + c5);
			chkmin(c5, c4 + c6);
			chkmin(c6, c5 + c1);
		}
		ll X = abs(x), Y = abs(y);
		if(x >= 0) {
			if(y >= 0) {
				if(x >= y) printf("%lld\n", Y*c1+(X-Y)*c6);
				else printf("%lld\n", X*c1+(Y-X)*c2);
			}
			else printf("%lld\n", X*c6+Y*c5);
		}
		else {
			if(y >= 0) printf("%lld\n", X*c3+Y*c2);
			else {
				if(x >= y) printf("%lld\n", X*c4+(Y-X)*c5);
				else printf("%lld\n", Y*c4+(X-Y)*c3);
			}
		}
	}
	return 0;
}