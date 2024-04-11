#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k;
		cin >> n >> k;
		if (k % 2 != n % 2 && n > k) {
			cout << 1 << '\n';
		}
		else {
			cout << max(0, k - n) << '\n';
		}
	}
	return 0;
}