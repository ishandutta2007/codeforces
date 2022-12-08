#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = 998244353LL;
int n;

vector<ll> pq; //numbers that are p*q
vector<ll> facts;

map<ll, int> freq;
map<ll, int> pqf; 
set<ll> oldpq;

bool isprime(ll cur) {
	for (ll i = 2; i <= sqrt(cur); ++i) {
		if (cur % i == 0) return false;
	}
	return true;
}

ll getc(ll u) {
	return u * u * u;
}

ll gcd(ll a, ll b) {
	if ( a < b) swap(a, b);
	if (a % b == 0) return b;

	return gcd(b, a%b);

}


void tookout(ll f1, ll f2) {

	vector<ll> tko;
	vector<ll> tf1;
	vector<ll> tf2;

	for (ll x : oldpq) {
		if (x % f1 == 0) {
			ll ot = x/f1;
			freq[f1] += pqf[x];
			if (freq[ot] == 0) facts.push_back(ot);
			freq[ot] += pqf[x];

			tko.push_back(x);
			tf1.push_back(f1);
			tf2.push_back(ot);

		}
		else if (x % f2 == 0) {
			ll ot = x/f2;
			freq[f2] += pqf[x];
			if (freq[ot] == 0) facts.push_back(ot);
			freq[ot] += pqf[x];

			tko.push_back(x);
			tf1.push_back(f2);
			tf2.push_back(ot);
		}
	}
	for (ll x : tko) oldpq.erase(oldpq.find(x));

	for (int i = 0; i < tko.size(); i++) {
		tookout(tf1[i], tf2[i]);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	ll ai;
	for (int i = 0; i < n; i++) {
		cin >> ai;

		// if (ai % 67867967 == 0) cout << "THIs" << endl;

		ll sq = sqrt(ai);
		if (sq *sq != ai) {
			if ((sq -1) * (sq-1) == ai) {
				sq--;
			}
			if ((sq+1) * (sq+1) == ai) sq++;
		}
		if (sq*sq == ai) {
			//must be 2 or 4
			if (isprime(sq)) {
				if (freq[sq] == 0) {
					facts.push_back(sq);
				}
				// cout << sq << " has " << 2 << endl;
				freq[sq] += 2;
			}
			else {
				ll mys = sqrt(sq);

				if ((mys - 1LL) * (mys - 1LL) == sq) mys--;
				if ((mys+1LL) * (mys+1LL) == sq) mys++;

				if (freq[mys] == 0) facts.push_back(mys);
				freq[mys] += 4;

			}
			continue;
		}
		//check for cube root
		ll cb = cbrt(ai);
		if (getc(cb-1) == ai) --cb;
		if (getc(cb+1) == ai) ++cb;
		if (getc(cb) == ai) {
			if (freq[cb] == 0) facts.push_back(cb);
			freq[cb] += 3;

			continue;
		}

		if (pqf[ai] == 0) pq.push_back(ai);
		pqf[ai]++;

	}

	// set<ll> oldpq;

	for (int i = 0; i < pq.size(); i++) {


		ll cv = pq[i];

		// cout << cv << " WAS HERE: " << pqf[cv]  << endl;

		bool done = false;
		for (ll ov : facts) {
			if (cv % ov == 0) {
				//found a prime factor of it
				ll ofact = cv/ov;

				// cout << cv << "  and   " << ofact << endl;
				freq[ov] += pqf[cv];
				if (freq[ofact] == 0) {
					facts.push_back(ofact);
				}
				freq[ofact] += pqf[cv];

				done = true;

				tookout(ov, ofact);

				break;

			}
		}

		if (done) continue;

		for (ll ot : oldpq) {
			ll gc = gcd(ot, cv);
			if (gc == 1LL) continue;

			ll f1 = gc;
			ll f2 = cv/gc;
			ll f3 = ot/gc;

			oldpq.erase(oldpq.find(ot));
			if (freq[f1] == 0) {
				facts.push_back(f1);
			}
			if (freq[f2] == 0) {
				facts.push_back(f2);
			}
			if (freq[f3] == 0) {
				facts.push_back(f3);
			}
			freq[f1] += pqf[ot] + pqf[cv];
			freq[f2] += pqf[cv];
			freq[f3] += pqf[ot];

			tookout(f1, f2);
			tookout(f1, f3);

			done = true;
			break;

		}
		if (!done) oldpq.insert(cv);
	}

	ll ans = 1LL;
	for (ll u : facts) {
		// cout << u << " with a freq of: " << freq[u] << endl;
		ans = (ans * (freq[u] + 1LL))%mod;
	}

	for (ll u : oldpq) {
		// cout << u << " is left" << endl;
		ans = (ans * (pqf[u] + 1LL))%mod;
		ans = (ans * (pqf[u] + 1LL))%mod;
	}
	cout << ans << endl;





}