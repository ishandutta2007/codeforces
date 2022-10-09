#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int mn = -2000000000, mx = 2000000000, s = 0;
	for (int i = 0; i < n; ++i) {
		int x, d;
		cin >> x >> d;
		if (d == 1) {
			mn = max(mn, 1900 - s);
		} else {
			mx = min(mx, 1899 - s);
		}
		s += x;
	}
	if (mx == 2000000000) {
		cout << "Infinity\n";
		return 0;
	}
	if (mx < mn) {
		cout << "Impossible\n";
		return 0;
	}
	cout << mx + s << endl;
	return 0;
}