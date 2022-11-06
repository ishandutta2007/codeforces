//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 4e3+5;

int n, a[N], b[N], tot, dp[N][N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b+1, b+1+n);
	tot = unique(b+1, b+1+n) - b - 1;
	rep(i, 1, n) a[i] = lower_bound(b+1, b+1+tot, a[i]) - b;
	rep(i, 1, n) {
		rep(j, 1, i-1) {
			chkmax(dp[i][a[j]], dp[j][a[i]]+1);
			chkmax(ans, dp[i][a[j]]);
		}
	}
	printf("%d\n", ans+1);
	return 0;
}