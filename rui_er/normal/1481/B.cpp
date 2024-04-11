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

int n, k, h[N], s, mx;

int main() {
	mulT0 {
		fil(h, 0); s = mx = 0;
		scanf("%d%d", &n, &k);
		rep(i, 1, n) scanf("%d", &h[i]);
		mx = h[n];
		per(i, n-1, 1) {
			if(h[i] < mx) s += mx - h[i];
			else mx = h[i];
		}
		if(k > s) puts("-1");
		else {
			rep(i, 1, k) {
				int _ = 0;
				rep(j, 2, n) {
					if(h[j] > h[j-1]) {
						++h[j-1];
						_ = j - 1;
						break;
					}
				}
				if(i == k) {
					if(!_) puts("-1");
					else printf("%d\n", _);
				}
			}
		}
	}
	return 0;
}