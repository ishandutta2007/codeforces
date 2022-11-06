//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 505;

int n, m, b, mod, a[N], dp[N][N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%d%d", &n, &m, &b, &mod);
	rep(i, 1, n) scanf("%d", &a[i]);
	dp[0][0] = 1;
	rep(i, 1, n) {
		rep(j, 0, m-1) {
			rep(k, 0, b-a[i]) {
				dp[j+1][k+a[i]] += dp[j][k];
				dp[j+1][k+a[i]] %= mod;
			}
		}
	}
	rep(k, 0, b) {
		ans += dp[m][k];
		ans %= mod;
	}
	printf("%d\n", ans);
	return 0;
}