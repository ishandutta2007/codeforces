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
const int N = 55;

int n, a[N]; 

int main() {
	mulT0 {
		int ans = 0;
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 2, n) {
			if(a[i] > a[i-1]) {
				while(a[i] > a[i-1] * 2) {
					a[i-1] <<= 1;
					++ans;
				}
			}
			else {
				int tmp = a[i];
				while(a[i] * 2 < a[i-1]) {
					a[i] <<= 1;
					++ans;
				}
				a[i] = tmp;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}