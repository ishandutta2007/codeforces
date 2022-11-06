// Problem: CF1097B Petr and a Combination Lock
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1097B
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 16, M = 360;

int n, a[N], dp[N][M];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	dp[0][0] = 1;
	rep(i, 1, n) {
		rep(j, 0, M-1) {
			dp[i][j] |= dp[i-1][(j+a[i])%M];
			dp[i][j] |= dp[i-1][(j+M-a[i])%M];
		}
	}
	puts(dp[n][0]?"YES":"NO");
	return 0;
}