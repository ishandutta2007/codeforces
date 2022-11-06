// Problem: CF253D Table with Letters - 2
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF253D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug prllf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 405;

ll n, m, k, sum[N][N], buc[26], ans;
char s[N][N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	rep(i, 1, n) scanf("%s", s[i]+1);
	rep(i, 1, n) rep(j, 1, m) sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (s[i][j] == 'a');
	rep(u, 1, n) {
		rep(d, u+1, n) {
			memset(buc, 0, sizeof(buc));
			ll l = 1, r = 1, now = 0;
			while(l < m) {
				while(r <= m && sum[d][r] - sum[u-1][r] - sum[d][l-1] + sum[u-1][l-1] <= k) {
					if(s[u][r] == s[d][r]) ++buc[s[u][r]-'a'];
					++r;
				}
				if(l < r && s[u][l] == s[d][l]) {
					--buc[s[u][l]-'a'];
					now += buc[s[u][l]-'a'];
				}
				++l;
			}
			ans += now;
		}
	}
	printf("%lld\n", ans);
	return 0;
}//qwq