#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d %d", &n, &k);
		vector<int> divisors;
		for (int i = 1; i <= sqrt(n) + 100; ++i) {
			if (n % i == 0) {
				divisors.push_back(i);
				divisors.push_back(n / i);
			}
		}
		int ans = 1000000000;
		for (int x : divisors) {
			if (x <= k) ans = min(ans, n/x);
		}
		printf("%d\n", ans);
	}
	return 0;
}