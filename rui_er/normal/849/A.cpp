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
	scanf("%d", &n);
	if(!(n&1)) return puts("No"), 0;
	rep(i, 1, n) scanf("%d", &a[i]);
	puts((a[1]&1)&&(a[n]&1)?"Yes":"No");
	return 0;
}