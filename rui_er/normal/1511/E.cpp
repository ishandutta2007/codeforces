#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define per(i,a,b) for(ll i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const ll N = 6e5+5, mod = 998244353;

ll n, m, dp[N], pw2[N] = {1}, len, qaq, tg, ans;
vector<char> a[N];
char qwq[N];

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) a[i].resize(m+1);
	rep(i, 1, n) scanf("%s", &a[i][1]);
	rep(i, 1, n) rep(j, 1, m) if(a[i][j] == 'o') ++tg;
	rep(i, 1, n*m) pw2[i] = pw2[i-1] * 2 % mod;
	rep(i, 2, n*m) dp[i] = (dp[i-1] + 2 * dp[i-2] + pw2[i-2]) % mod;
	rep(i, 1, n) {
		rep(j, 1, m) qwq[++len] = a[i][j];
		qwq[++len] = '*';
	}
	rep(i, 1, len) {
		if(qwq[i] == 'o') ++qaq;
		else ans = (ans + dp[qaq] * pw2[tg-qaq] % mod) % mod, qaq = 0;
	}
	len = qaq = 0;
	rep(i, 1, m) {
		rep(j, 1, n) qwq[++len] = a[j][i];
		qwq[++len] = '*';
	}
	rep(i, 1, len) {
		if(qwq[i] == 'o') ++qaq;
		else ans = (ans + dp[qaq] * pw2[tg-qaq] % mod) % mod, qaq = 0;
	}
	printf("%lld\n", ans);
	return 0;
}