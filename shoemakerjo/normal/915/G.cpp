#include <bits/stdc++.h>

using namespace std;

#define maxn 2000010

int mobius[maxn];
bool iscomp[maxn];
vector<int> primes;
int pows[maxn];
const int mod = 1000000007;
vector<vector<int>> di(maxn);

int exp(int base, int pow) {
	if (pow == 0) return 1;
	if (pow % 2 == 0) {
		return exp((base*1LL*base)%mod, pow/2);
	}
	return (base*1LL*(exp(base, pow-1)))%mod;
}

int inv(int u) {
	return exp(u, mod-2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	mobius[1] = 1;
	int mx = max(n, k);
	fill(iscomp, iscomp + maxn, false);
	
	// cout << "set up the vector" << endl;
	for (int i = 1; i <= k; i++) {
		for (int j = i; j <= k; j += i) {
			di[j].push_back(i);
		}
	}
	// cout << "done with divisors" << endl;
	
	iscomp[1] = true;
	int ct = 0;
	int ct2 = 0;
	for (int i = 1; i <= mx; i++) {
		
		if (!iscomp[i]) {
			primes.push_back(i);
			mobius[i] = -1;
		}
		
		for (int j = 0; j < primes.size() && (i * primes[j] <= mx); j++) {
			ct2++;
			iscomp[i*primes[j]] = true;
			mobius[i*primes[j]] = mobius[i]*mobius[primes[j]];
			if (i% primes[j] == 0) {
				mobius[i*primes[j]] = 0;
				break;
			}
		}
	}
	// cout << "here" << endl;
	for (int i = 1; i <= k; i++) {
		pows[i] = exp(i, n);
	}
	// cout << "past expos " << endl;
	int ans = 0;
	int cur = 0;
	// int ct = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < di[i].size(); j++) {
			// ct++;
			int v = di[i][j];
			int cp = i/v;
			// if (i%v != 0) cout << "THIS IS BAD" << endl;
			int f = pows[cp];
			f = (f+mod-pows[cp-1])%mod;
			// cout << "mob   " << mobius[v] << "   -   " << f <<  "  for val " << v << endl;
			f = (mobius[v]*f + mod)%mod;
			cur = (cur + f)%mod;
		}
		// cout << i << " -  " << cur << endl;
		ans = (ans + (cur^i))%mod;
	}

	cout << ans << endl;
	// cout << "ct   " << ct << " , " << ct2 << endl;
	cin >> ans;

}