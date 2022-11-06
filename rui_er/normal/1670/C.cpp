//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5, mod = 1e9+7;

int T, n, a[N], b[N], c[N], vis[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) scanf("%d", &b[a[i]]);
		rep(i, 1, n) scanf("%d", &c[a[i]]);
		int ans = 1;
		rep(i, 1, n) {
			if(!vis[i]) {
				int sz = 0, fix = 0;
				for(int j=i;!vis[j];j=b[j]) {
					vis[j] = 1;
					++sz;
					fix |= !!c[j];
				}
				if(!fix && sz > 1) ans = 2LL * ans % mod;
			}
		}
		printf("%d\n", ans);
		rep(i, 1, n) vis[i] = 0;
	}
	return 0;
}