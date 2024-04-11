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
const int N = 3e5+5;

char c[N]; 

int main() {
	mulT0 {
		scanf("%s", c);
		int n = strlen(c), ok = 0;
		rep(i, 0, n-1) if(c[i] != 'a') {ok = 1; break;}
		if(!ok) puts("NO");
		else {
			puts("YES");
			int pos = -1;
			rep(i, 0, n-1) if(c[i] != 'a') {pos = n - i; break;}
			rep(i, 0, pos-1) putchar(c[i]);
			putchar('a');
			rep(i, pos, n-1) putchar(c[i]);
			puts("");
		}
	}
	return 0;
}