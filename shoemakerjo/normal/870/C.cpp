#include <bits/stdc++.h>

using namespace std;

int main() {
	int q;
	cin >> q;
	int n;
	for (int i = 0; i < q; i++) {
		cin >> n;
		if (n == 1 || n == 2 || n == 3 || n == 5 || n == 7 || n == 11) {
			cout << -1 << '\n';
		}
		else {
			if (n%4 == 0) {
				cout << n/4 << '\n';
			}
			if (n%4 == 1) {
				cout << 1 + (n-9)/4 << '\n';
			}
			if (n%4 == 2) {
				cout << 1 + (n-6)/4 << '\n';
			}
			if (n%4 == 3) {
				cout << 2 + (n-15)/4 << '\n';

			}
		}
	}
	// cin >> n;
}