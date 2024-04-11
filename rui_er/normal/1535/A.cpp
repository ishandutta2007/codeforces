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

int a[4];

int main() {
	mulT0 {
		rep(i, 0, 3) scanf("%d", &a[i]);
		if(min(a[0], a[1]) > max(a[2], a[3]) || max(a[0], a[1]) < min(a[2], a[3])) puts("NO");
		else puts("YES");
	} 
	return 0;
}