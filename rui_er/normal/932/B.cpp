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
const int N = 1e6+5, K = 15;

int qwq[N], s[N][K], l, r, k;
int f(int x) {
	int res = 1;
	while(x) {
		if(x % 10) res *= x % 10;
		x /= 10;
	}
	return res;
}
int g(int x) {
	if(qwq[x]) return qwq[x];
	if(x < 10) return qwq[x] = x;
	return qwq[x] = g(f(x));
}

int main() {
	rep(i, 1, N-5) {
		rep(j, 0, 9) s[i][j] = s[i-1][j];
		int _ = g(i);
		++s[i][_];
//		rep(j, 0, 9) printf("%d%c", s[i][j], " \n"[j==9]);
	}
	mulT0 {
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", s[r][k]-s[l-1][k]);
	}
	return 0;
}