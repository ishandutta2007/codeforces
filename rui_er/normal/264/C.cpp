//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(ll (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n, m, c[N], v[N], dp[N], ma[2];

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &v[i]);
	rep(i, 1, n) scanf("%lld", &c[i]);
	while(m--) {
		ll a, b, s = 0, ans = 0;
		scanf("%lld%lld", &a, &b);
		ma[0] = ma[1] = 0;
		fil(dp, ~0x3f);
		rep(i, 1, n) {
			s = max(max(b*v[i], dp[c[i]]+a*v[i]), (c[i]==ma[0])?(dp[ma[1]]+b*v[i]):(dp[ma[0]]+b*v[i]));
			if(s > dp[ma[0]]) {if(c[i] != ma[0]) ma[1] = ma[0], ma[0] = c[i];}
			else if(s > dp[ma[1]] && c[i] != ma[0]) ma[1] = c[i];
			dp[c[i]] = max(dp[c[i]], s);
			ans = max(ans, s);
		}
		printf("%lld\n", ans);
	}
	return 0;
}