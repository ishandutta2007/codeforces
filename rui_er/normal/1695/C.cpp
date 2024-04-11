// Problem: CF1695C Zero Path
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1695C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e3+5, inf = 0x3f3f3f3f;

int T, n, m, a[N][N], mx[N][N], mn[N][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) {
			rep(j, 1, m) {
				scanf("%d", &a[i][j]);
				mx[i][j] = -inf;
				mn[i][j] = inf;
			}
		}
		mx[1][1] = mn[1][1] = a[1][1];
		rep(i, 2, n) mx[i][1] = mn[i][1] = mx[i-1][1] + a[i][1];
		rep(j, 2, m) mx[1][j] = mn[1][j] = mx[1][j-1] + a[1][j];
		rep(i, 2, n) {
			rep(j, 2, m) {
				mx[i][j] = max(mx[i-1][j], mx[i][j-1]) + a[i][j];
				mn[i][j] = min(mn[i-1][j], mn[i][j-1]) + a[i][j];
			}
		}
		if(mn[n][m] <= 0 && 0 <= mx[n][m] && !(mn[n][m] & 1)) puts("YES");
		else puts("NO");
	}
	return 0;
}