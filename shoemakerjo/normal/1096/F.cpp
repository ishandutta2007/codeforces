#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define maxn 200010
int n;

const int mod = 998244353;

int nums[maxn];
ll numbef[maxn]; //how many open spots before me
bool ispres[maxn];

ll modpow(ll u, int p) {
	if (p == 0) return 1LL;
	if (p % 2 == 0) {
		ll tmp = modpow(u, p/2);
		return (tmp*tmp)%mod;
	}
	ll tmp = modpow(u, p-1);
	return (u*tmp)%mod;
}

ll inv(ll u) {
	return modpow(u, mod-2);
}

void add(ll &a, ll b) {
	a = (a+mod+b)%mod;
}

ll mult(ll a, ll b) {
	return (a*b)%mod;
}

ll BIT[maxn];

ll query(int u) {
	//how many less than or equal to u
	ll res = 0LL;
	while (u > 0) {
		res += BIT[u];
		u -= u & (-u);
	}
	return res;
}

void upd(int u) {
	// cout << "INITIAL VALUE: " << u << endl;
	while (u <= n) {
		// cout << " --- " << u << endl;	
		BIT[u]++;
		u += u & (-u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		if (nums[i] > 0) ispres[nums[i]] = true;
	}
	int numop = 0;
	for (int i = 1; i <= n; i++) {
		if (nums[i] == -1) {
			numop++;
			continue;
		}
		numbef[nums[i]] = numop;
	}

	ll cfact = 1LL;
	for (ll i = 1LL; i < numop; i += 1LL) {
		cfact = mult(cfact, i);
	}

	// cout << "numop: " << numop << endl;

	ll tp = 0LL;
	if (numop >= 2) {
		ll ofact = 1LL;
		for (ll i = 1LL; i < numop-1; i += 1LL) {
			ofact = mult(ofact, i);
		}
		ll c2;
		c2 = mult(numop, numop-1);
		// cout << "before stuff :: " << c2 << endl;
		c2 = mult(c2, inv(2LL));

		// cout << "c2 : " << c2 << endl;

		ll cur = mult(c2, c2);
		tp = mult(cur, ofact);
	}

	// assert(tp >= 0);

	// cout << "current tp: " << tp << endl;

	ll cv = 0LL;
	for (int i = 1; i <= n; i++) {
		if (ispres[i]) {
			add(cv, numop - numbef[i]);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!ispres[i]) {
			add(tp, mult(cfact, cv));
		}

		else {
			add(cv, (numbef[i] - (numop - numbef[i])) % mod);
		}
	}

	// assert(tp >= 0);

	//now we must add og inversions
	ll og = 0LL;

	for (int i = n; i >= 1; i--) {
		if (nums[i] == -1) continue;
		// cout << i << " ::: " << nums[i] << endl;

		add(og, query(nums[i]));
		upd(nums[i]);
	}

	if (numop) cfact = mult(cfact, numop);

	add(tp, mult(cfact, og));

	// cout << "top of the fraction: " << tp << endl;

	ll ans = tp;
	ans = mult(ans, inv(cfact));
	cout << ans << endl;

}