//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 25, inf = 0x3f3f3f3f;

int n, l, r, x, a[N], ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%d%d", &n, &l, &r, &x);
	rep(i, 0, n-1) scanf("%d", &a[i]);
	rep(i, 1, (1<<n)-1) {
		int mi = inf, ma = -inf, s = 0;
		rep(j, 0, n-1) if((i >> j) & 1) {
			chkmin(mi, a[j]);
			chkmax(ma, a[j]);
			s += a[j];
		}
		if(l <= s && s <= r && ma - mi >= x) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}