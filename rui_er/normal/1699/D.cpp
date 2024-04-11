// Problem: D. Almost Triple Deletions
// Contest: Codeforces - Codeforces Round #804 (Div. 2)
// URL: https://codeforces.com/contest/1699/problem/D
// Memory Limit: 256 MB
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
const int N = 5e3+5, inf = 0x3f3f3f3f;

int T, n, a[N], buc[N], del[N][N], dp[N][N]; // dp[i][j] : a[1..i], value=j max length
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n+1) {
			rep(j, 0, n) {
				del[i][j] = i > j;
				dp[i][j] = -inf;
			}
		}
		rep(L, 1, n) {
			rep(i, 1, n) buc[i] = 0;
			int mx = 0, len = 0;
			rep(R, L, n) {
				++len;
				chkmax(mx, ++buc[a[R]]);
				del[L][R] = (!(len & 1)) && (mx * 2 <= len);
			}
		}
		rep(i, 1, n) {
			rep(j, 0, i-1) {
				if(del[j+1][i-1]) {
					chkmax(dp[i][a[i]], dp[j][a[i]]+1);
				}
			}
		}
		int ans = 0;
		rep(i, 1, n) {
			rep(j, 1, n) {
				if(del[i+1][n]) {
					chkmax(ans, dp[i][j]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}