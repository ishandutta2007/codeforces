//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 405; 

int T, n, m, a[N][N], s[N][N], bk[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int sum(int l, int r, int u, int d) {
	return s[d][r] - s[d][l-1] - s[u-1][r] + s[u-1][l-1];
} 

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) rep(j, 1, m) scanf("%1d", &a[i][j]);
		rep(i, 1, n+1) bk[i] = 0;
		rep(i, 1, n) rep(j, 1, m) s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
		int ans = 18;
		rep(l, 1, m) rep(r, l+3, m) {
			per(u, n-3, 1) {
				bk[u] = (r - l - 1) - sum(l+1, r-1, u+3, u+3);
				bk[u] += sum(l+1, r-1, u, u+2);
				bk[u] += 3 - sum(l, l, u, u+2);
				bk[u] += 3 - sum(r, r, u, u+2);
				if(u < n - 3) {
					int nxt = bk[u+1] + (!a[u][l]) + (!a[u][r]) + sum(l+1, r-1, u, u);
					chkmin(bk[u], nxt);
				}
			}
			rep(u, 1, n-4) chkmin(ans, bk[u+1]+(r-l-1)-sum(l+1, r-1, u, u));
		}
		printf("%d\n", ans);
	}
    return 0;
}