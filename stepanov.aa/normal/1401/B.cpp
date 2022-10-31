#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int a0, a1, a2;
		cin >> a0 >> a1 >> a2;
		int b0, b1, b2;
		cin >> b0 >> b1 >> b2;
		cout << 2 * (min(a2, b1) - max(0, b2 - a0 - (a2 - min(a2, b1)))) << '\n';

	}
	return 0;
}