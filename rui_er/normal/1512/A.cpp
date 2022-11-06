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
const int N = 105;

int n, a[N]; 

int main() {
	mulT0 {
		int x = 0, y = 0, posX = 0, posY = 0, ans = 0;
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			if(a[i] == x) ans = posY;
			else if(a[i] == y) ans = posX;
			else if(!x) x = a[i], posX = i;
			else y = a[i], posY = i;
		}
		if(!ans) ans = posY;
		printf("%d\n", ans);
	}
	return 0;
}