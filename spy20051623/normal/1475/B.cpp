#include <bits/stdc++.h>
using namespace std;

main() {
	int t, n, x, y;
	cin >> t;
	while (t--) {
		cin >> n;
		x = n / 2020;
		y = n % 2020;
		if (x >= y)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}