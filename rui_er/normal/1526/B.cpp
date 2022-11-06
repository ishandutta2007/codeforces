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
const int N = 1115, K = 1111;
const int a[] = {0, 0, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};

int n, ok[N];

int main() {
	rep(i, 1, K) {
		rep(j, 2, 4) if(i % a[j] == 0) ok[i] = 1;
		rep(j, 2, 4) if(i > a[j]) ok[i] |= ok[i-a[j]];
	}
	mulT0 {
		scanf("%d", &n);
		if(n <= K) puts(ok[n]?"YES":"NO");
		else puts("YES");
	}
	return 0;
}