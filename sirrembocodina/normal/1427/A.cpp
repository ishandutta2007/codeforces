#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		int n;
		cin >> n;
		vector<int> a(n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if (sum == 0) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			if (sum < 0) {
				for (int i = 0; i < n; i++) {
					if (a[i] < 0) {
						cout << a[i] << " ";
					}
				}
				for (int i = 0; i < n; i++) {
					if (a[i] > 0) {
						cout << a[i] << " ";
					}
				}
				for (int i = 0; i < n; i++) {
					if (a[i] == 0) {
						cout << a[i] << " ";
					}
				}
			} else {
				for (int i = 0; i < n; i++) {
					if (a[i] > 0) {
						cout << a[i] << " ";
					}
				}
				for (int i = 0; i < n; i++) {
					if (a[i] < 0) {
						cout << a[i] << " ";
					}
				}
				for (int i = 0; i < n; i++) {
					if (a[i] == 0) {
						cout << a[i] << " ";
					}
				}
			}
			cout << endl;
		}
	}
}