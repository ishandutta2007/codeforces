#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1000000007;

ll raise(ll base, ll power) {
	if (power == 0LL) return 1LL;
	if (power % 2LL == 1LL) {
		ll tempo  = raise(base, power-1LL);
		return (tempo*base)%mod;
	}
	ll tempo = raise(base, power/2LL);
	return (tempo*tempo)%mod;
}

ll inv(ll base) {
	return raise(base, mod-2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int s1[n], s2[n];
	for (int i = 0; i < n; i++) {
		cin >> s1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> s2[i];
	}
	ll invm = inv(m);
	ll inv2m = inv(2*m);
	// cout << invm << " " << inv2m << endl;
	ll cpow = 1LL;

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		if (s1[i] == 0 && s2[i] == 0) {

			ll prob = ((m-1)*inv2m)%mod;
			prob = (prob*cpow)%mod;
			ans = (ans+prob)%mod;
			cpow = (cpow*invm)%mod;
		}
		else if (s1[i] == 0) {
			ll abov = m-s2[i];
			ll frac = (abov*invm)%mod;
			// cout << "      " << frac << " - " << cpow << endl;
			frac = (frac*cpow)%mod;
			// cout << "-->   " << frac << endl;
			ans = (ans+frac)%mod;
			cpow = (cpow*invm)%mod;
			// cout << "cp    " << cpow << endl;

		}
		else if (s2[i] == 0) {
			ll bel = s1[i]-1LL;
			ll frac = (bel*invm)%mod;
			frac = (frac*cpow)%mod;
			// cout << "     " << frac << endl;
			ans = (ans+frac)%mod;
			cpow = (cpow*invm)%mod;
		}
		else {
			if (s1[i] > s2[i]) {
				ans = (ans+cpow)%mod;
				break;
			}
			if (s2[i] > s1[i]) break;
		}
	}

	cout << ans << endl;
	cin >> n;

}