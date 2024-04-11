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

int n, a[105][105];

int main() {
	mulT0 {
		scanf("%d", &n);
		if(n & 1) {
			rep(i, 1, n-1) {
				rep(j, i+1, n) {
					if((j - i) & 1) a[i][j] = 1;
					else a[i][j] = -1;
				}
			}
		}
		else {
			rep(i, 1, n-1) {
				rep(j, i+1, n) {
					if(j - i == n / 2) a[i][j] = 0;
					else if(j - i < n / 2) a[i][j] = -1;
					else a[i][j] = 1;
				}
			}
		}
		rep(i, 1, n-1) rep(j, i+1, n) printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}