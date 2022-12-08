#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define maxn 300010
#define maxv 15000010

int nums[maxn];
bool iscomp[maxv];
int fact[maxv];
int n;
int ct[maxv];
vector<int> primes;

void sieve() {

	for (int i = 2; i < maxv; i++) {
		if (!iscomp[i]) {
			primes.push_back(i);
			fact[i] = i;
		}
		for (int j = 0; j < primes.size() && i * primes[j] < maxv; j++) {
			iscomp[i*primes[j]] = true;
			fact[i*primes[j]] = primes[j];
			if (i%primes[j] == 0) break;
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	int og = nums[1];
	for (int i = 2; i <= n; i++) {
		og = __gcd(og, nums[i]);
	}
	for (int i = 1; i <= n; i++) {
		nums[i] /= og;
	}
	sieve();
	// cout << "done with sieve" << endl;
	int mosttake = 0;
	for (int i = 1; i <= n; i++) {
		// cout << "onto " << i << endl;
		int prev = -1;
		while (nums[i] != 1) {
			// cout << i << " : " << nums[i] << endl;
			if (fact[nums[i]] != prev) {
				ct[fact[nums[i]]]++;
				
			}
			prev = fact[nums[i]];
			nums[i] /= fact[nums[i]];
		}
	}
	// cout << "down here" << endl;
	for (int i = 0; i < maxv; i++) {
		mosttake = max(mosttake, ct[i]);
	}
	if (mosttake == 0) cout << -1 << endl;
	else cout << n-mosttake << endl;

}