#include <bits/stdc++.h>
using namespace std;

main() {
	int t, q, d, a, y, i;
	cin >> t;
	while (t--) {
		cin >> q >> d;
		while (q--) {
			cin >> a;
			y = a % d;
			while ((y - d) % 10 && y < 10 * d)
				y += d;
			if (y > a)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}
}