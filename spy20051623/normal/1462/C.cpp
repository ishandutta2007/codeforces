#include <bits/stdc++.h>
using namespace std;

main() {
	int t, x, i, sum;
	cin >> t;
	while (t--) {
		cin >> x;
		if (x > 45)
			cout << "-1" << endl;
		else {
			i = 9;
			sum = 0;
			while (x > i) {
				sum += i * pow(10, 9 - i);
				x -= i;
				--i;
			}
			sum += x * pow(10, 9 - i);
			cout << sum << endl;
		}
	}
}