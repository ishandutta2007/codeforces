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

int h, w, H, W;

int main() {
	mulT0 {
		char op[2];
		scanf("%s%d%d", op, &h, &w);
		if(h > w) swap(h, w);
		if(op[0] == '+') H = max(H, h), W = max(W, w);
		else puts((const char*[]){"NO", "YES"}[H<=h&&W<=w]); 
	} 
	return 0;
}