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
const int N = 180+5;

int n, ans[N];
void init() {
	rep(i, 3, 360) rep(j, 1, i-2) {
		int _ = 180 * j;
		int notInteger = _ % i;
		if(notInteger) continue;
		int angle = _ / i;
		if(!ans[angle]) ans[angle] = i;
	}
}
void solve() {scanf("%d", &n); printf("%d\n", ans[n]);}

int main() {
	init();
	mulT0 solve();
	return 0;
}