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
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		sort(a+1, a+1+n);
		int tot = 0;
		rep(i, 1, n) if(a[i] == a[1]) ++tot; else break;
		printf("%d\n", n-tot);
	} 
	return 0;
}