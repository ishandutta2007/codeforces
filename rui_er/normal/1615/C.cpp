//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5, inf = 0x3f3f3f3f;

int T, n, a[N], b[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%1d", &a[i]);
		rep(i, 1, n) scanf("%1d", &b[i]);
		int sum = 0, same = 1;
		rep(i, 1, n) {
			sum += a[i];
			same &= a[i] == b[i];
		}
		if(same) {puts("0"); continue;}
		if(!sum) {puts("-1"); continue;}
		int cnt[2][2];
		rep(i, 0, 1) rep(j, 0, 1) cnt[i][j] = 0;
		rep(i, 1, n) ++cnt[a[i]][b[i]];
		int ans = inf;
		if(cnt[0][1] == cnt[1][0]) chkmin(ans, cnt[0][1]+cnt[1][0]);
		if(cnt[0][0] + 1 == cnt[1][1]) chkmin(ans, cnt[0][0]+cnt[1][1]);
		if(ans == inf) puts("-1");
		else printf("%d\n", ans);
	}
    return 0;
}