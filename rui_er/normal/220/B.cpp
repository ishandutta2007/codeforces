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
const int N = 1e5+5, M = 5e2+5;
 
int n, q, a[N], tot[N], b[N], tp, s[M][N];
void discretization() {
	rep(i, 1, n) if(a[i] <= n) ++tot[a[i]];
	rep(i, 1, n) {
		if(tot[i] < i) continue;
		b[++tp] = i;
		rep(j, 1, n) s[tp][j] = s[tp][j-1] + (a[j] == i);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d", &a[i]);
	discretization();
	rep(i, 1, q) {
		int l, r, ans = 0;
		scanf("%d%d", &l, &r);
		rep(i, 1, tp) ans += (s[i][r] - s[i][l-1] == b[i]);
		printf("%d\n", ans);
	}
	return 0;
}