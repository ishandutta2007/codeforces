// Problem: CF1616D Keep the Average High
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1616D
// Memory Limit: 250 MB
// Time Limit: 1500 ms
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
const int N = 1e5+5, inf = 0x7fffffff / 3;

int T, n, x, a[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		scanf("%d", &x);
		rep(i, 1, n) a[i] -= x;
		rep(i, 2, n) {
			if(a[i-1] + a[i] < 0) a[i] = inf;
			else if(a[i-2] + a[i-1] + a[i] < 0) a[i] = inf;
		}
		int ans = 0;
		rep(i, 1, n) ans += a[i] < inf;
		printf("%d\n", ans);
	}
	return 0;
}