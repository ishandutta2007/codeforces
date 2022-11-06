// Problem: CF1272D Remove One Element
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1272D
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
const int N = 2e5+5, inf = 0x3f3f3f3f;

int n, a[N], dp[N][2], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	a[0] = inf; dp[1][0] = 1; dp[1][1] = 0;
	rep(i, 2, n) {
		dp[i][0] = a[i-1] < a[i] ? dp[i-1][0] + 1 : 1;
		dp[i][1] = max(a[i-2] < a[i] ? dp[i-2][0] + 1 : 1, 
					   a[i-1] < a[i] ? dp[i-1][1] + 1 : 1);
		chkmax(ans, dp[i][0]);
		chkmax(ans, dp[i][1]);
	}
	printf("%d\n", ans);
	return 0;
}