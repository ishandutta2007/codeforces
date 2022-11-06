//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1005;

ll n, k, dp[N][N], cnt[N];
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct State {
	ll nxt[26];
	State() {
		memset(nxt, 0, sizeof(nxt));
	}
};
struct SSAM {
	State t[N];
	void build(char* s, ll n) {
		State now;
		rep(i, 0, 25) now.nxt[i] = n + 1;
		per(i, n, 0) {
			t[i] = now;
			if(i) now.nxt[s[i] - 'a'] = i;
		}
	}
	void solve() {
		dp[0][0] = 1;
		rep(i, 0, n) {
			rep(j, 0, n-1) {
				rep(k, 0, 25) {
					dp[t[i].nxt[k]][j+1] += dp[i][j];
				}
			}
		}
	}
}ssam;

int main() {
//	fileIO("string");
	scanf("%lld%lld%s", &n, &k, s+1);
	ssam.build(s, n);
	ssam.solve();
//	rep(i, 0, n) rep(j, 0, 25) debug("%lld%c", ssam.t[i].nxt[j], " \n"[j==25]);
//	rep(i, 0, n+1) rep(j, 0, n) debug("%lld%c", dp[i][j], " \n"[j==n]);
	rep(i, 0, n) rep(j, 0, n) cnt[j] += dp[i][j];
	ll ans = 0;
	per(i, n, 0) {
		ll qwq = min(k, cnt[i]);
		k -= qwq;
		ans += qwq * (n - i);
		if(!k) return printf("%lld\n", ans)&0;
	}
	puts("-1");
	return 0;
}