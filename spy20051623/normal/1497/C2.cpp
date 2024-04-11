#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (; k > 3; --n, --k) {
			cout << 1 << ' ';
		}
		if (n & 1) {
			cout << 1 << ' ' << n / 2 << ' ' << n / 2 << endl;
		} else if (n == 4) {
			cout << 2 << ' ' << 1 << ' ' << 1 << endl;
		} else if (n % 4 == 0) {
			cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << endl;
		} else {
			cout << 2 << ' ' << (n - 2) / 2 << ' ' << (n - 2) / 2 << endl;
		}
	}
	return 0;
}