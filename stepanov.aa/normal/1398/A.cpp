#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; ++c) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		if (a[0] + a[1] <= a[n - 1]) {
			cout << 1 << " " << 2 << " " << n << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
	return 0;
}