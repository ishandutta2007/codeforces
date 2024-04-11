//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 55, M = 1e5+5, mod = 998244353ll;

ll n, m, L[N], R[N], s[2][M], ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
ll p[M], tab[M], mu[M], tot;
void sieveMu(ll lim) {
	mu[1] = 1;
	rep(i, 2, lim) {
		if(!tab[i]) {
			mu[i] = -1;
			p[++tot] = i;
		}
		rep(j, 1, tot) {
			if(i * p[j] > lim) break;
			tab[i*p[j]] = 1;
			if(i % p[j]) mu[i*p[j]] = -mu[i];
			else break;
		}
	}
}

int main() {
	scanf("%lld%lld", &n, &m);
	sieveMu(M-5);
	rep(i, 1, n) scanf("%lld%lld", &L[i], &R[i]);
	rep(i, 1, m) {
		ll k = m / i, ok = 1;
		rep(j, 1, n) {
			ll l = (L[j] + i - 1) / i, r = R[j] / i;
			chkmax(l, 1ll);
			if(!r || l > r) {ok = 0; break;}
			if(j == 1) {
				rep(t, 1, k) s[0][t] = 0;
				rep(t, l, r) s[0][t] = 1;
				rep(t, 2, k) s[0][t] += s[0][t-1];
				continue;
			}
			rep(t, 1, k) s[1][t] = s[0][max(t-l, 0ll)] - s[0][max(t-r-1, 0ll)];
			rep(t, 1, k) s[0][t] = 0;
			rep(t, 1, k) s[0][t] = (s[0][t-1] + s[1][t]) % mod;
		}
		if(ok) {
			ll qwq = 0;
			rep(j, 0, k) qwq = (qwq + s[1][j]) % mod;
			ans = (ans + (mu[i] * qwq) % mod) % mod;
		}
	}
	ans = (ans + mod) % mod;
	printf("%lld\n", ans);
	return 0;
}