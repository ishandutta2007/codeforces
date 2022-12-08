#include <bits/stdc++.h>
using namespace std;

main() {
	int t, n, k, a;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (n > k) {
			if (n % k)
				a = 2;
			else
				a = 1;
		} else {
			if (k % n)
				a = k / n + 1;
			else
				a = k / n;
		}
		cout << a << endl;
	}
}