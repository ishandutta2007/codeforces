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
const double eps = 1e-6;

int n;
bool judge(int x) {return ceil(sqrt(x)) - floor(sqrt(x)) <= eps;}

int main() {
	mulT0 {
		scanf("%d", &n);
		if(!(n & 1) && judge(n>>1) || !(n & 3) && judge(n>>2)) puts("YES");
		else puts("NO");
	}
	return 0;
}