#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll mod;

ll pow(ll base, ll power) {
	if (power == 0LL) return 1LL;
	if (power == 1LL) return base;
	if (power % 2LL == 0LL) {
		ll tempo = pow(base, power/2);
		ll ans = (tempo*tempo)%mod;
		return ans;
	}
	ll tempo = pow(base, power-1);
	ll ans = (base*tempo)%mod;
	return ans;
}

int main() {
	ll n, m;
	int k;
	cin >> n >> m >> k;
	mod = 1000000007LL;
	ll inv = (mod+1LL)/2LL;
	if (n == 1LL) {
		if (k == -1) {
			if (m%2LL == 0LL) {
				cout << 0 << endl;
			}
			else cout << 1 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
	else if (m == 1LL) {
		if (k == -1) {
			if (n%2LL == 0LL) {
				cout << 0 << endl;
			}
			else cout << 1 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
	else if (k == -1 && n%2LL != m%2LL) {
		cout << 0 << endl;
	}
	else {
		ll p = pow(2LL, m-1)%mod;
		p = pow(p, n-1)%mod;
		// p = (p*inv)%mod;
		// p = (p*inv)%mod;
		cout << p << endl;
	}
	cin >> n;

}