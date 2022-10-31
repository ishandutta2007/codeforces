#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; ++c) {
		int n;
		cin >> n;
		int mn = 2e9;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			mn = min(mn, a[i]);
		}
		int l = 0;
		vector<int> ind;
		vector<int> b;
		for (int i = 0; i < n; ++i) {
			if (a[i] % mn != 0) {
				if (a[i] >= l) {
					l = a[i];
				}
				else {
					l = -1;
					break;
				}
			}
			else {
				ind.push_back(i);
				b.push_back(a[i]);
			}
		}
		if (l == -1) {
			cout << "NO" << '\n';
			continue;
		}
		sort(b.begin(), b.end());
		int j = 0;
		l = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] % mn != 0) {
				if (a[i] >= l) {
					l = a[i];
				}
				else {
					l = -1;
					break;
				}
			}
			else {
				if (b[j] >= l) {
					l = b[j];
				}
				else {
					l = -1;
					break;
				}
				++j;
			}
		}
		if (l == -1) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}
	return 0;
}