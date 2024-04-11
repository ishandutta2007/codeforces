//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n, k, a[N], BIT[15][N], dp[15][N], ans;
ll lowbit(ll x) {return x&(-x);}
void insert(ll *c, ll x, ll y) {for(;x<=n;x+=lowbit(x)) c[x] += y;}
ll query(ll *c, ll x) {ll res = 0; for(;x;x-=lowbit(x)) res += c[x]; return res;}

int main() {
	scanf("%lld%lld", &n, &k); ++k;
	rep(i, 1, n) scanf("%lld", &a[i]);
	if(k == 1) return printf("%lld\n", n), 0;
	rep(i, 1, n) {
		insert(BIT[1], a[i], 1);
		rep(j, 2, k) insert(BIT[j], a[i], dp[j][i] = query(BIT[j-1], a[i]-1));
		ans += dp[k][i];
	}
	printf("%lld\n", ans);
	return 0;
}