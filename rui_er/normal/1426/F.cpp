//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;
const ll N = 2e5+5, mod = 1e9+7;

ll n, dp[3], tot = 1; char s[N];

int main() {
	scanf("%lld%s", &n, s+1);
	rep(i, 1, n) {
		if(s[i] == 'a') (dp[0] += tot) %= mod;
		else if(s[i] == 'b') (dp[1] += dp[0]) %= mod;
		else if(s[i] == 'c') (dp[2] += dp[1]) %= mod;
		else {
			((dp[2] *= 3) += dp[1]) %= mod;
			((dp[1] *= 3) += dp[0]) %= mod;
			((dp[0] *= 3) += tot) %= mod;
			(tot *= 3) %= mod;
		}
	}
	printf("%lld\n", dp[2]);
	return 0;
}