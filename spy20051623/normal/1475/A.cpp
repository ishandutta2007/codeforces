#include <bits/stdc++.h>
using namespace std;

main() {
	int t, flag;
	long long n, i;
	cin >> t;
	while (t--) {
		cin >> n;
		flag = 0;
		while (n > 1) {
			if (n % 2 == 0)
				n /= 2;
			else {
				flag = 1;
				break;
			}
		}
		if (n == 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}