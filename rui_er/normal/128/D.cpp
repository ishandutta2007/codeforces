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
const int N = 1e5+5, inf = 1e9;

int n, a[N], buc[N], mi = inf;

int main() {
	scanf("%d", &n);
	if(n & 1) return puts("NO"), 0;
	rep(i, 1, n) scanf("%d", &a[i]), mi = min(mi, a[i]);
	sort(a+1, a+1+n);
	rep(i, 2, n) if(a[i] - a[i-1] > 1) return puts("NO"), 0;
	rep(i, 1, n) ++buc[a[i]-mi+1];
	int u = 1; --buc[1];
	loop {
		if(buc[u+1]) --buc[++u];
		else if(buc[u-1]) --buc[--u];
		else break;
	}
	if(u != 2) return puts("NO"), 0;
	rep(i, 0, N-1) if(buc[i]) return puts("NO"), 0;
	return puts("YES"), 0;
}