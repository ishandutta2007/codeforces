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
		while(k > 3) {printf("1 "); --k; --n;}
		if(n & 1) printf("1 %d %d\n", n/2, n/2);
		else if((n >> 1) & 1) printf("2 %d %d\n", (n>>1)-1, (n>>1)-1);
		else printf("%d %d %d\n", n>>2, n>>2, n>>1);
	}
	return 0;
}