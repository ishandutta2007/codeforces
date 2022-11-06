//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 5e4+5, K = 1e6+5;

int n, m, a[N], L[N], R[N], s[K], dp[N], ans[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, m) scanf("%d%d", &L[i], &R[i]);
	rep(i, 1, K-1) s[i] = s[i-1] ^ i;
	rep(i, 1, n) {
		dp[i] = a[i];
		rep(j, i+1, n) {
			int l = min(a[i], a[j]);
			int r = max(a[i], a[j]);
			dp[j] = max(dp[j-1], s[l-1]^s[r]);
		}
		rep(j, 1, m) {
			if(L[j] <= i && i <= R[j]) {
				chkmax(ans[j], dp[R[j]]);
			}
		}
	}
	rep(i, 1, m) printf("%d\n", ans[i]);
	return 0;
}