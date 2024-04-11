#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int mod = 998244353;


void add(ll &a, ll b) {
	a = (a+mod+b)%mod;
}

ll mult(ll a, ll b) {
	return (a*b)%mod;
}


ll combos[6010][105];
int p, s, r;

ll sbars(int nstars, int places) {

	if (places == 0) {
		if (nstars == 0) return 1LL;
		return 0LL;
	}

	// cout << "attempting to do " << nstars << " vs " << places << endl;

	if (nstars == 0) return 1LL;

	int tt = nstars + places-1;

	// cout << tt << " - " << nstars << " ::: " << combos[tt][nstars] << endl;
	return combos[tt][places-1];
}

void createcombos() {
	combos[0][0] = 1LL;
	combos[1][0] = 1;
	combos[1][1] = 1;
	for (int i = 2; i < 6010; i++) {
		combos[i][0] = 1;
		for (int j = 1; j < 105; j++) {
			combos[i][j] = combos[i-1][j-1];
			add(combos[i][j], combos[i-1][j]);
		}
	}
}

ll modpow(ll u, int p) {
	if (p == 0) return 1LL;
	if (p%2 == 0) {
		ll tmp = modpow(u, p/2);
		return (tmp*tmp)%mod;
	}
	ll tmp = modpow(u, p-1);
	return (tmp*u)%mod;

}

ll inv(ll u) {
	return modpow(u, mod-2);
}

ll iv[5010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> p >> s >> r;
	createcombos();

	for (int i = 1; i <= 5000; i++) {
		iv[i] = inv(i);
	}

	int numleft = 0;

	ll tp = 0LL;
	ll bt = 0LL;

	ll csum = 0LL;

	for (int i = r; i <= s; i++) {
		//fix the value to be i
		numleft = s-i;

		add(bt, sbars(numleft, p-1));
		// cout << "        after " << i << " :: " << bt << endl;
		// cout << numleft << " vs " << p-1 << " gives: " << sbars(numleft, p-1) << endl;

		for (int j = 0; j <= p-1; j++) {
			//j others are exactly equal to i
			ll cv = 0LL;
			numleft = s-i-j*i;
			if (numleft < 0) continue;
			cv = sbars(numleft, p-j-1); //fit the rest all in
			cv = mult(cv, combos[p-1][j]); //pick the places 

			// cout << "number of pre-ways if I set i to " << i << " with " << j << " equal "
			// 	": " << cv << endl;

			for (int k = 1; k <= p-j-1; k++) {
				//k of what is left are greater than or equal to i
				ll sv = 0LL;
				numleft = s-i-j*i-k*i;
				if (numleft < 0) continue;

				sv = sbars(numleft, p-j-1);
				sv = mult(sv, combos[p-j-1][k]);
				sv = mult(sv, combos[p-1][j]); //maybe this will help

				if (k % 2 == 1) {
					add(cv, 0-sv);
				}
				else add(cv, sv);

			}

			// cout << "number of ways if I set i to " << i << " with " << j << " equal "
			// 	": " << cv << endl;
			add(csum, cv);

			add(tp, mult(cv, iv[j+1]));

		}

		// cout << "       csum after " << i << " :: " << csum << endl;

	}

	// cout << tp << " over " << bt << endl;
	// cout << "csum is " << csum << endl;

	ll ans = mult(tp, inv(bt));
	cout << ans << endl;

}