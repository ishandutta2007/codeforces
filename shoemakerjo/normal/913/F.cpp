#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 2010
const ll mod = 998244353LL;
ll ppow[maxn]; //p to the i
ll npow[maxn]; // 1 - p to the i
ll cp[maxn][maxn];
ll strong[maxn];
ll ans[maxn];

ll exp(ll base, ll power) {
	if (power == 0LL) return 1LL;
	if (power == 1LL) return base;
	if (power % 2LL == 0LL) {
		// cout << "here " << endl;
		ll temp = exp(base, power/2);
		temp = (temp*temp)%mod;
		return temp;
	}
	ll temp = exp(base, power-1);
	temp = (temp*base)%mod;
	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ll a, b;
	cin >> n >> a >> b;
	ll p = (a*exp(b, mod-2))%mod;
	//learn how to not need to use fractions here
	ppow[0] = 1LL;
	ll np = 1-p+mod;
	npow[0] = 1LL;
	// cout << "HERE" << endl;
	for (int i = 1; i <= n; i++) {
		ppow[i] = (ppow[i-1]*p)%mod;
		npow[i] = (npow[i-1]*np)%mod;
	}
	// cout << "HERE 2 " << endl;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cp[i][j] = 0LL;
		}
	}
	cp[0][0] = 1LL;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cp[i+1][j] = (cp[i+1][j] + ppow[j]*cp[i][j])%mod;
			cp[i+1][j+1] = (cp[i+1][j+1] + npow[i-j]*cp[i][j])%mod;
		}
	}

	strong[0] = strong[1] = 1LL;
	for (int i = 2; i <= n; i++) {
		strong[i] = 1LL;
		for (int j = 1; j < i; j++) {
			ll sub = (strong[j]*cp[i][j])%mod;
			strong[i] = (strong[i]-sub);
			while (strong[i] < 0) strong[i] += mod;
		}
	}
	ans[1] = 0LL;
	for (int i = 2; i <= n; i++) {
		// cout << "i   " << i << endl;
		ans[i] = 0LL;
		for (int j = 1; j < i; j++) {
			ll fp = (strong[j]*cp[i][j])%mod;
			ll sp = (j*(i-j) + (j*(j-1))/2 + ans[j]+ans[i-j])%mod;
			ll mult = (fp*sp)%mod;
			ans[i] = (ans[i] + mult)%mod;
		}
		ans[i] = (ans[i] + strong[i]*((i*(i-1LL))/2LL))%mod;
		ll inv = exp(1-strong[i]+mod, mod-2);
		ans[i] = (ans[i]*inv)%mod;
	}
	cout << ans[n] << endl;
	cin >> n;

}