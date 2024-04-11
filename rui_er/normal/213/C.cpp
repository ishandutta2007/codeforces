// Problem: CF213C Relay Race
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF213C
// Memory Limit: 250 MB
// Time Limit: 4000 ms
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
const int N = 305;

int n, a[N][N], dp[N<<1][N][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) rep(j, 1, n) scanf("%d", &a[i][j]);
	memset(dp, ~0x3f, sizeof(dp));
	dp[1][1][1] = a[1][1];
	rep(i, 2, 2*n-1) {
		rep(ax, 1, n) {
			int ay = i - ax + 1;
			if(ay < 1 || ay > n) continue;
			rep(bx, 1, n) {
				int by = i - bx + 1;
				if(by < 1 || by > n) continue;
				chkmax(dp[i][ax][bx], dp[i-1][ax-1][bx-1]);
				chkmax(dp[i][ax][bx], dp[i-1][ax-1][bx]);
				chkmax(dp[i][ax][bx], dp[i-1][ax][bx-1]);
				chkmax(dp[i][ax][bx], dp[i-1][ax][bx]);
				if(ax != bx) dp[i][ax][bx] += a[ax][ay] + a[bx][by];
				else dp[i][ax][bx] += a[ax][ay];
			}
		}
	}
	printf("%d\n", dp[2*n-1][n][n]);
	return 0;
}