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
const int N = 3e5+5;

int n, a[N], b[N], ok[N];

int main() {
	mulT0 {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%1d", &a[i]);
		rep(i, 1, n) scanf("%1d", &b[i]);
		rep(i, 1, n) ok[i] = 0;
		int s = 0, rev = 0, ans = 1;
		rep(i, 1, n) {
			if(a[i]) ++s;
			else --s;
			if(!s) ok[i] = 1;
		}
		per(i, n, 1) {
			if((a[i] ^ rev) != b[i]) {
				if(!ok[i]) {ans = 0; break;}
				rev ^= 1;
			}
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}