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
const int N = 2e3+5;

int n, a[N];

int main() {
	mulT0 {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		auto cmp = [=](int x, int y) -> bool {
			if((x & 1) && (y & 1)) return x > y;
			if(x & 1) return 0;
			if(y & 1) return 1;
			return x > y;
		};
		sort(a+1, a+1+n, cmp);
//		rep(i, 1, n) fprintf(stderr, "%d%c", a[i], " \n"[i==n]);
		int ans = 0;
		rep(i, 1, n) rep(j, i+1, n) ans += (__gcd(a[i], 2*a[j]) > 1);
		printf("%d\n", ans);
	}
	return 0;
}