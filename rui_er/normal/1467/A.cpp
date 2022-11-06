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

int n;

int main() {
	mulT0 {
		scanf("%d", &n);
		if(n == 1) puts("9");
		else {
			printf("98");
			int _ = 9;
			rep(i, 3, n) {
				printf("%d", _);
				if(++_ > 9) _ = 0;
			}
			puts("");
		}
	} 
	return 0;
}