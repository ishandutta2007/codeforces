//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5; 

int T, a, b;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &a, &b);
		int n = a + b;
		if(n & 1) {
			int mn = n / 2 - min(a, b);
			int mx = n - mn;
			int tot = mx - mn + 1;
			printf("%d\n", tot);
			rep(i, mn, mx) printf("%d%c", i, " \n"[i==mx]);
		}
		else {
			int mn = n / 2 - min(a, b);
			int mx = n - mn;
			int tot = 0;
			for(int i=mn;i<=mx;i+=2) ++tot;
			printf("%d\n", tot);
			for(int i=mn;i<=mx;i+=2) printf("%d ", i);
			puts("");
		}
	}
	return 0;
}