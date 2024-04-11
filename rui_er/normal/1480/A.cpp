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

char c[55];

int main() {
	mulT0 {
		scanf("%s", c+1);
		int n = strlen(c+1);
		rep(i, 1, n) {
			if(i & 1) {
				if(c[i] == 'a') c[i] = 'b';
				else c[i] = 'a';
			}
			else {
				if(c[i] == 'z') c[i] = 'y';
				else c[i] = 'z';
			}
		}
		printf("%s\n", c+1);
	} 
	return 0;
}