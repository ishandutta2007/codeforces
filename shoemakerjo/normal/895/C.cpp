#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define maxn 100010

// ll fact[maxn];
// ll invfact[maxn];
ll twos[maxn];
ll curvals[600000];
ll nvals[600000];

// ll inv[maxn];

// ll powe(ll base, int p) {
// 	if (p == 0) return 1ll;
// 	if (p == 1) return base;
// 	if (p %2 == 1) {
// 		ll tempo = powe(base, p-1);
// 		ll cur = (tempo*base)%mod;
// 		return cur;
// 	}
// 	ll tempo = powe(base, p/2);
// 	ll cur = (tempo*tempo)%mod;
// 	return cur;
// }

bool isprime(int u) {
	for (int i = 2; i <= sqrt(u); i++) {
		if (u%i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	ll mod = 1000000007LL;

	vector<int> primes;
	for (int i = 2; i <= 70; i++) {
		if (isprime(i)) primes.push_back(i);
	}

	// fact[0] = 1LL;
	// invfact[0] = 1LL;
	// for (int i = 1; i <= n; i++) {
	// 	fact[i] = (fact[i-1]*(i+0LL))%mod;
	// 	invfact[i] = powe(fact[i], mod-2);
	// 	// inv[i] = powe(i, mod-2);
	// }

	twos[0] = 1LL;
	for (int i = 1; i <= n+5; i++) {
		twos[i] = (2LL*twos[i-1])%mod;
	}

	int cont[71];
	for (int i = 0; i <= 70; i++) cont[i] = 0;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		cont[cur]++;
	}
	int allodd = (1 << 19) - 1;
	for (int i = 0; i < 60000; i++) {
		curvals[i] = 0LL;
	}
	curvals[0] = 1LL;
	// cout << "BEFORE LOOP" << endl;
	for (int i = 1; i <= 70; i++) {
		for (int j = 0; j <= allodd; j++) {
			nvals[j] = curvals[j];
		}
		// cout << "i   " << i << endl;
		if (cont[i] == 0) continue;
		ll evenmult = twos[cont[i]-1]-1;
		ll oddmult = twos[cont[i]-1];
		int bi = 0;
		for (int j = 0; j < 19; j++) {
			int ct = 0;
			int cur = i;
			while (cur % primes[j] == 0) {
				// cout << "here " << endl;
				ct++;
				cur = cur/primes[j];
			}
			if (ct % 2 == 1) {
				bi += (1 << j);
			}
		}
		
		for (int j = 0; j <= allodd; j++) {
			int nmask = j ^ bi;
			ll oadd = (oddmult*curvals[j])%mod;
			nvals[nmask]  = (nvals[nmask]+oadd)%mod;
			ll eadd = (evenmult*curvals[j])%mod;
			nvals[j] = (nvals[j]+eadd)%mod;
		}
		for (int j = 0; j <= allodd; j++) {
			curvals[j] = nvals[j];
		}

	}
	if (curvals[0] == 0LL) curvals[0] = mod;
	curvals[0] -= 1LL;
	cout << curvals[0] << endl;
	// cout << primes.size() << endl;
	cin >> n;
}