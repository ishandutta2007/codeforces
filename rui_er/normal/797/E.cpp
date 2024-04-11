//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5, K = 320; 

int n, a[N], m, dp[N][K];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	int k = sqrt(n);
	per(i, n, 1) {
		rep(j, 1, k) {
			int nxt = i + a[i] + j;
			if(nxt > n) dp[i][j] = 1;
			else dp[i][j] = dp[nxt][j] + 1;
		}
	}
	for(scanf("%d", &m);m;m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(y <= k) printf("%d\n", dp[x][y]);
		else {
			int ans = 0;
			for(;x<=n;x+=a[x]+y,++ans);
			printf("%d\n", ans);
		}
	}
    return 0;
}