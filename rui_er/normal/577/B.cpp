//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e3+5; 

int n, m, a[N], dp[N][N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	if(n > m) return puts("YES")&0;
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		a[i] %= m;
		if(!a[i]) return puts("YES")&0;
		dp[i][a[i]] = 1;
	}
	rep(i, 1, n) {
		rep(j, 0, m-1) {
			dp[i][j] |= dp[i-1][j];
			dp[i][(j+a[i])%m] |= dp[i-1][j];
		}
		if(dp[i][0]) return puts("YES")&0;
	}
	puts("NO");
	return 0;
}