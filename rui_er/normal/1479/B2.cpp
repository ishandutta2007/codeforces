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
const int N = 1e5+5, inf = 0x3f3f3f3f;

int n, a[N], pos[N], lst[N];

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) pos[i] = n + 1;
	per(i, n, 1) {lst[i] = pos[a[i]]; pos[a[i]] = i;}
	lst[0] = inf;
	int x = 0, y = 0, ans = 0;
	rep(i, 1, n) {
		if(a[x] == a[i]) x = i;
		else if(a[y] == a[i]) y = i;
		else if(lst[x] < lst[y]) y = i, ++ans;
		else x = i, ++ans;
	}
	printf("%d\n", ans);
    return 0;
}