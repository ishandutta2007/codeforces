#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll mod = 1000000007;
	int n;
	cin >> n;
	int nums[n];
	int big = -1;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		big = max(big, nums[i]);
	}
	int numfactors[big+1];
	for (int i = 0; i <= big; i++) {
		numfactors[i] = 0;
	}
	ll pows[n+1];
	pows[0] = 0; //technicallity
	pows[1] = 2;
	for (int i = 2; i <= n; i++) {
		pows[i] = (pows[i-1]*2)%mod;
	}
	ll po[n+1];
	po[0] = 0;
	po[1] = 1;
	for (int i = 2; i <= n; i++) {
		po[i] = (i*pows[i-1])%mod;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <=sqrt(nums[i]); j++) {
			if (nums[i]%j == 0) {
				numfactors[j]++;
				if (j*j!=nums[i]) {
					numfactors[nums[i]/j]++;
				}
			}
		}
	}
	ll ans = 0;
	vector<int> primes;
	for (int i =  2; i <= 1000; i++) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}
	ll ansnum[big+1];
	for (int i = big; i >= 2; i--) {
		// if (numfactors[i] < 2) continue;
		// bool pri = true;
		// for (int j = 0; j < primes.size(); j++) {
		// 	if (i%primes[j] == 0 && i != primes[j]) {
		// 		pri = false;
		// 		break;
		// 	}
		// 	if (primes[j]*primes[j] > i) break;
		// }
		// if (!pri) continue;
		ansnum[i] = (po[numfactors[i]])%mod;
		for (int j = 2; j <= big; j++) {
			if (j*i > big) break;
			ansnum[i] = (mod + (ansnum[i] - ansnum[i*j])) % mod;
		}
		// cout << i << "  " << po[numfactors[i]] << " " << numfactors[i] <<  endl;
		ans = (mod + (ans + ansnum[i]*i)) % mod;
	}
	cout << ans << endl;
	// cin >> n;
}