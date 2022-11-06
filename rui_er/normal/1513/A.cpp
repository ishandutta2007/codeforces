//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;

int n, k;

int main() {
	mulT0 {
		scanf("%d%d", &n, &k);
		int lim = (n - 1) / 2;
		if(k > lim) puts("-1");
		else {
			int L = 0, R = n + 1;
			rep(i, 1, k) printf("%d %d ", ++L, --R);
			rep(i, L+1, R-1) printf("%d ", i);
			puts("");
		}
	} 
	return 0;
}