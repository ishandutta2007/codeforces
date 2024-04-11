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

int n, a, b, c, d;

int main() {
	mulT0 {
		scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
		a *= n; b *= n;
		if(a - b > c + d || a + b < c - d) puts("No");
		else puts("Yes");
	}
	return 0;
}