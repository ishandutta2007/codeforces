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
const int N = 1e5+5;

int n, m, a[N], contribution[N], suspect[N], tot, s;

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		if(a[i] > 0) ++contribution[a[i]];
		else --contribution[-a[i]], ++s;
	}
	rep(i, 1, n) if(s + contribution[i] == m) suspect[i] = 1, ++tot;
	rep(i, 1, n) {
		if(a[i] > 0) {
			if(!suspect[a[i]]) puts("Lie");
			else if(tot == 1) puts("Truth");
			else puts("Not defined");
		}
		else {
			if(!suspect[-a[i]]) puts("Truth");
			else if(tot == 1) puts("Lie");
			else puts("Not defined");
		}
	}
	return 0;
}