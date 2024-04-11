#include <bits/stdc++.h>

using namespace std;

bool iscom[1000010];
int spf[1000010];

vector<int> primes;

void sieve() {
	fill(iscom, iscom+1000010, false);
	for (int i = 2; i <= 1000000; i++) {
		spf[i] = i;
	}
	for (int i = 4; i <= 1000000; i+=2) {
		spf[i] = 2;
	}
	for (int i = 2; i <= 1000000; i++) {
		if (!iscom[i]) {
			primes.push_back(i);
			// if (i < 100) cout << i << " " << endl;
		}
		for (int j = 0; j < primes.size() && i*primes[j] <= 1000000; j++) {
			iscom[i*primes[j]] = true;
			spf[i*primes[j]] = primes[j];
			if (i % primes[j] == 0) break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x2;
	cin >> x2;
	sieve();
	// cout << primes.size() << endl;
	// cin >> x2;
	int mval = x2;
	for (int i = 0; i < primes.size(); i++) {
		if (x2 % primes[i] == 0 && x2 != primes[i]) {
			int cval = x2-primes[i]+1;
			mval = min(mval, cval);
		}
	}
	int ans = x2;
	for (int i = mval; i <= x2; i++) {
		int cur = i;
		int bigp = 0;
		while (cur != 1) {
			bigp = max(bigp, spf[cur]);
			cur /= spf[cur];
		}
		if (bigp == i) continue;
		ans = min(ans, i-bigp+1);
	}
	cout << ans << endl;
	cin >> ans;

}