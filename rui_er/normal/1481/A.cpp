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
const int N = 1e5+5; 

int x, y;
char c[N];

int main() {
	mulT0 {
		scanf("%d%d", &x, &y);
		int u, d, r, l; u = d = r = l = 0;
		scanf("%s", c+1);
		int len = strlen(c+1);
		rep(i, 1, len) {
			if(c[i] == 'U') ++u;
			else if(c[i] == 'D') ++d;
			else if(c[i] == 'R') ++r;
			else ++l;
		}
		if(x >= 0 && r >= x && y >= 0 && u >= y) puts("YES");
		else if(x >= 0 && r >= x && y <= 0 && d >= -y) puts("YES");
		else if(x <= 0 && l >= -x && y >= 0 && u >= y) puts("YES");
		else if(x <= 0 && l >= -x && y <= 0 && d >= -y) puts("YES");
		else puts("NO");
	}
	return 0;
}