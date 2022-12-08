#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long t;
	vector<int> primes;
	for (int i = 2; i <= 1000; ++i) {
		bool ok = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i%j==0) {
				ok = false;
				break;
			}
		}
		if (ok) primes.push_back(i);
	}
	for (int i = 0; i < n; ++i) {


		// ios_base::sync_with_stdio(false);
  //   	cin.tie(NULL);

		cin >> t;
		double d = sqrt(t);
		long long d2 = rint(d);
		bool ok = true;
		if (d2*d2!=t) {
			ok = false;
		}
		for (int j = 0; j < primes.size(); j++) {
			int num = primes[j];
			if (num > sqrt(d2)) break;
			if (d2%num==0) {
				ok = false;
				break;
			}
			if (num > 2) {
				num++;
			}
		}

		if (ok && t != 1) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	// cin >> n;
}