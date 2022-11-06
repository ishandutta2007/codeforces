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
const int N = 55;

int n, a[N];

int main() {
	mulT0 {
		scanf("%d", &n);
		rep(i, 1, 2*n) scanf("%d", &a[i]);
		sort(a+1, a+1+2*n);
		int L = 1, R = 2 * n;
		while(L < R) printf("%d %d ", a[L++], a[R--]);
		puts("");
	}
	return 0;
}