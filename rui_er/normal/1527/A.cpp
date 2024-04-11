//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;

int n;

int main() {
	mulT0 {
		scanf("%d", &n);
		int ans = 0;
		per(i, 29, 0) if((n >> i) & 1) {ans = (1 << i) - 1; break;}
		printf("%d\n", ans);
	} 
	return 0;
}