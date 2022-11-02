#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int mi = 10000000, ma = -10000000;
	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		mi = min(mi, x[i]);
		ma = max(ma, x[i]);
	}
	if (ma - mi != 2) {
		cout << n << '\n';
		for (int i = 0; i < n; i++) {
			cout << x[i] << " ";
		}
	}
	else {
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < n; i++) {
			if (x[i] == mi) {
				a++;
			}
			else {
				if (x[i] == ma) {
					c++;
				}
				else {
					b++;
				}
			}
		}
		//cout << a << " " << b << " " << c;
		if (a >= c) {
			if (n - 2 * c <= n - (b / 2) * 2) {
				cout << n - 2 * c << '\n';
				for (int i = 0; i < a - c; i++) {
					cout << mi << " ";
				}
				for (int i = 0; i < n - (a - c); i++) {
					cout << mi + 1 << " ";
				}
			}
			else {
				cout << n - (b / 2) * 2 << '\n';
				if (b % 2 == 1) {
					cout << mi + 1 << " ";
				}
				for (int i = 0; i < a + (b / 2); i++) {
					cout << mi << " ";
				}
				for (int i = 0; i < c + (b / 2); i++) {
					cout << ma << " ";
				}
			}
		}
		else {
			if (n - 2 * a <= n - (b / 2) * 2) {
				cout << n - 2 * a << '\n';
				for (int i = 0; i < c - a; i++) {
					cout << ma << " ";
				}
				for (int i = 0; i < n - (c - a); i++) {
					cout << mi + 1 << " ";
				}
			}
			else {
				cout << n - (b / 2) * 2 << '\n';
				if (b % 2 == 1) {
					cout << mi + 1 << " ";
				}
				for (int i = 0; i < a + (b / 2); i++) {
					cout << mi << " ";
				}
				for (int i = 0; i < c + (b / 2); i++) {
					cout << ma << " ";
				}
			}
		}
	}
	return 0;
}