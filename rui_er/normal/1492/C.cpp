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
const int N = 2e5+5;

int n, m, pre[N], suf[N], le[N], ri[N], ans;
char s[N], t[N];

int main() {
	scanf("%d%d%s%s", &n, &m, s+1, t+1); suf[n+1] = m + 1;
	rep(i, 1, n) pre[i] = pre[i-1] + ((s[i] == t[pre[i-1]+1]) ? 1 : 0);
	per(i, n, 1) suf[i] = suf[i+1] - ((s[i] == t[suf[i+1]-1]) ? 1 : 0);
	rep(i, 1, n) ri[suf[i]] = i;
	per(i, n, 1) le[pre[i]] = i;
	rep(i, 2, n) ans = max(ans, ri[i]-le[i-1]);
	printf("%d\n", ans);
	return 0;
}