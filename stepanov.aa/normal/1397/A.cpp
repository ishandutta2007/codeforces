#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vector<int> a(255, 0);
		for (int j = 0; j < n; ++j) {
			string s;
			cin >> s;
			for (char x : s) {
				++a[(float)(x)];
			}
		}
		bool ok = true;
		for (auto x : a) {
			ok &= x % n == 0;
		}
		if (ok) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}