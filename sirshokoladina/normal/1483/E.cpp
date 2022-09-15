#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long l = 1e14 + 1, r = 0, s = 1, x;
		while (l - r > 1) {
			x = r + 1.5 + 0.5 * (l - r - 2) * s / (s + l);
			x = max(min(x, s), r);
			cout << "? " << x << endl;
			string res;
			cin >> res;
			if (res[0] == 'L') {
				r = x;
				s += x;
			} else {
				l = x;
				s -= x;
			}
		}
		cout << "! " << r << endl;
	}
}