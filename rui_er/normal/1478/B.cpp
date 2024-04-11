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
const int N = 1e4+5;

int n, m, a[N];

int main() {
	mulT0 {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) {
			if(a[i] >= 10 * m) puts("YES");
			else {
				int _ = 0;
				rep(j, 1, 9) if(a[i] >= m * j && (a[i] - m * j) % 10 == 0) {puts("YES"); _ = 1; break;}
				if(!_) puts("NO");
			}
		}
	}
	return 0;
}