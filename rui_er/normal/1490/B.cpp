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
const int N = 3e4+5;

int n, a[N], buc[3];

int main() {
	mulT0 {
		fil(buc, 0);
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]), ++buc[a[i]%3];
		int goal = n / 3, ans = 0;
		rep(_, 0, 5) {
			int i = _ % 3;
			if(buc[i] > goal) {
				int diff = buc[i] - goal;
				if(diff > 0) {
					ans += diff;
					buc[(i+1)%3] += diff;
					buc[i] -= diff;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}