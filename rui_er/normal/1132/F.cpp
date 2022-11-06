// Problem: CF1132F Clear the String
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1132F
// Memory Limit: 250 MB
// Time Limit: 3000 ms
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
const int N = 505;

int n, dp[N][N];
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	memset(dp, 0x3f, sizeof(dp));
	scanf("%d%s", &n, s+1);
	rep(i, 1, n) dp[i][i] = 1;
	rep(delta, 1, n-1) {
		rep(L, 1, n-delta) {
			int R = L + delta;
			rep(M, L, R-1) chkmin(dp[L][R], dp[L][M]+dp[M+1][R]-(s[L]==s[R]));
		}
	}
	printf("%d\n", dp[1][n]);
	return 0;
}