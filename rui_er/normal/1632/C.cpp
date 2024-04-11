//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

int T, a, b;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int calc(int x) {
	int c = x;
	per(i, 21, 0) {
		if(!((x >> i) & 1)) continue;
		if(c - (1 << i) >= a) c -= 1 << i;
	}
	return c;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &a, &b);
		int ans = b - a;
		rep(c, b, ((b<<1)|b)) {
			int now = (c - b) + (calc(c) - a + 1);
			chkmin(ans, now);
		}
		printf("%d\n", ans);
	}
	return 0;
}