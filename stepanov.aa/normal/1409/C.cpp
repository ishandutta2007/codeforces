#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, x, y;
		cin >> n >> x >> y;
		if (n < y - x + 1) {
			int j;
			for (j = 1; j <= y - x; ++j) {
				if ((y - x) % j == 0 && ((y - x) / j) + 1 <= n) {
					break;
				}
			}
			int a;
			if (x % j != 0) {
				a = max(x % j, y - j * (n - 1));
			}
			else {
				a = max(x % j + j, y - j * (n - 1));
			}
			cout << a << ' ';
			for (int c = 0; c < n - 1; ++c) {
				a += j;
				cout << a << ' ';
			}
		}
		else {
			int j = 1;
			int a = max(1, y - j * (n - 1));
			cout << a << ' ';
			for (int c = 0; c < n - 1; ++c) {
				a += j;
				cout << a << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}