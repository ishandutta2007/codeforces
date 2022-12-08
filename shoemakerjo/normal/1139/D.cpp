#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int mod = 1000000007;

const int maxm = 100010;
int m;

ll ev[maxm]; //expected value

int fact[maxm]; //store largest prime factor of the value

ll mult(ll a, ll b) {
	return (a%mod) * (b % mod) %mod;
}

void add(ll & a, ll b) {
	a = (a + mod + b)%mod;
}

bool isprime(int u) {
	for (int i = 2; i * i <= u; i++) {
		if (u% i == 0) return false;
	}
	return true;
}

ll iv[maxm];
vector<int> primes;

int isok[maxm];

int ccount[maxm];

ll modpow(ll base, ll p) {
	if (p == 0) return 1LL;
	if (p%2 == 0) {
		ll tmp = modpow(base, p/2);
		return mult(tmp, tmp);
	}
	ll tmp = modpow(base, p-1);
	return mult(tmp, base);
}

ll inv(ll u) {
	return modpow(u, mod-2);
}

int numleft[maxm];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> m;
	for (int i = 2; i <= m; i++) {
		if (isprime(i)) {
			primes.push_back(i);
			for (int j = i; j <= m; j += i) {
				fact[j] = i;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		ev[i] = 1;
		iv[i] = inv(i);

		numleft[i] = m;
	}

	for (int i = 2; i <= m; i++) {
		isok[i] = 1;
		int prev = -1, cur = i;
		int ct = 0;

		while (cur > 1) {
			if (fact[cur] == prev) isok[i] = 0;
			prev = fact[cur];
			cur /= prev;
			ct++;
		}

		if (isok[i] == 1 && ct % 2 == 0) isok[i] = -1;
	}


	//first we calculate ev

	for (int i = 1; i <= m; i++) {

		// cout << i << "  ----   " << ev[i] << " " << numleft[i] <<  endl;

		for (int j = 1; j <= m/i; j++) {
			//build this
			ccount[j] = m/i; 
		}
		for (int j = 1; j <= m/i; j++) {

			int ct  = (m/i) / j;

			// if (i == 1) cout << "  dfkak   " << j << " : " << isok[j] << " : " << ct << endl;
			for (int k = j; k <= m/i; k += j) {
				ccount[k] -= (ct) * isok[j];
			}
		}

		//maybe print stuff here
		// if (i == 1) {

		// cout << "counts for " << i << ":   " << endl;
		// 	for (int j = 1; j <= m/i; j++) {
		// 		cout << "    val for " << j << " : " << ccount[j] << endl;
		// 	}
		// }


		if (i == 1) {
			ev[i] = 0;
		}
		else {

			// cout << "    "  <<i << "  ::: " << ev[i] << " " << m << " " << iv[m-numleft[i]] << endl;
			ev[i] = mult(mult(ev[i], m), iv[m - numleft[i]]);
		}

		for (int j = i+i; j <= m; j += i) {
			//number that work is ccount j/i

			add(ev[j], mult(ev[i], mult(ccount[j/i], iv[m])));
			numleft[j] -= ccount[j/i];
		}
	}

	ll res = 0LL;
	for (int i = 1; i <= m; i++) {
		add(res, ev[i]);
	}
	res = mult(res, iv[m]);
	add(res, 1);
	cout << res << endl;

	// for (int i = 1; i <= m; i++) {
	// 	cout << i << "  :   " << ev[i] << endl;
	// }

	// cout << "  thing2: " << iv[2] << "  thing3: " << iv[3] << endl;
	// cout << "  ot: " << mult(4, iv[3]) << endl;
}