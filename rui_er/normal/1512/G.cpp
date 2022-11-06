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
const ll N = 1e7+5, K = 1e7;

ll n, tab[N], tmp[N], s[N], prime[N], tot, ans[N];
void sieve() {
	s[1] = 1;
	rep(i, 2, K) {
		if(!tab[i]) {
			prime[++tot] = i;
			s[i] = tmp[i] = i + 1;
		}
		rep(j, 1, tot) {
			if(prime[j] * i > K) break;
			tab[prime[j]*i] = 1;
			if(i % prime[j]) {
				s[prime[j]*i] = s[i] * s[prime[j]];
				tmp[prime[j]*i] = prime[j] + 1;
			}
			else {
				s[prime[j]*i] = s[i] / tmp[i] * (tmp[i] * prime[j] + 1);
				tmp[prime[j]*i] = tmp[i] * prime[j] + 1;
				break;
			}
		}
	}
}

int main() {
	sieve();
	fil(ans, -1);
	rep(i, 1, K) if(!~ans[s[i]]) ans[s[i]] = i;
	mulT0 {ll x; scanf("%lld", &x); printf("%lld\n", ans[x]);}
	return 0;
}