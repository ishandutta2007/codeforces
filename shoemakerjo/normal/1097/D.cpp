#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pli pair<ll, int>

ll n;
int k;
const int mod = 1000000007;

ll modpow(ll u, ll p) {
	if (p == 0) return 1;

	if (p%2 == 0) {
		ll tmp = modpow(u, p/2);
		return (tmp*tmp)%mod;
	}

	ll tmp = modpow(u, p-1);
	return (tmp*u)%mod;
}

map<ll, ll> iv;

ll inv(ll u) {
	if (iv.count(u)) {
		return iv[u];
	}
	else iv[u] = modpow(u%mod, mod-2);
	return iv[u];
}

void add(ll &a, ll b) {
	a = a%mod;
	b = b%mod;
	a = (a + mod + b)%mod;
}

ll mult(ll a, ll b) {
	a %= mod;
	b %= mod;
	return (a*b)%mod;
}

ll prob[55][55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	vector<ll> facts;
	vector<pli> pfact;

	ll cur = n;
	for (ll i = 2LL; i*i <= cur; i+=1LL) {
		if (cur%i == 0) {
			int ct = 0;
			while (cur%i == 0) {
				ct++;
				cur/=i;
			}
			pfact.push_back(mp(i, ct));
		}
		
	}
	if (cur > 1) pfact.push_back(mp(cur, 1));

	for (ll i = 1LL; i*i <= n; i +=1LL) {
		if (n%i == 0) {
			facts.push_back(i);
			if (i*i != n) facts.push_back(n/i);
		}
	}

	for (int i = 1; i <= 52; i++) {

		prob[i][0] = 1LL;

		for (int j = 1; j <= k; j++) {

			for (int pos = 0; pos <= i; pos++) {

				//set it to be 0
				prob[i][pos] = mult(prob[i][pos], inv(i-pos+1));
				if (pos > 0) add(prob[i][pos], prob[i][pos-1]);

			}

		}

	}


	ll ans = 0LL;
	ll csum = 0LL;

	for (ll v : facts) {

		ll cv = n/v;

		ll pat = 1LL;

		for (pli val : pfact) {
			//find number of this that divide into me

			int ct = 0;
			while (cv%val.first == 0) {
				cv /= val.first;
				ct++;
			}

			// cout << n/v << " has " << ct << " of " << val.first << endl;

			pat = mult(pat, prob[val.second][ct]);

		}

		// cout << "pat for " << v << " is " << pat << endl;
		add(csum, pat);

		add(ans, mult(pat, v));

	}

	assert(csum == 1LL);

	cout << ans << endl;
	

}