#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; ++c) {
		string s;
		cin >> s;
		int x;
		cin >> x;
		int n = s.size();
		vector<bool> w(n, 1);
		signed int res = 0;
		for (int i = 0; i < n; ++i) {
			if ((i - x >= 0 && s[i - x] == '0') || (i + x < n && s[i + x] == '0')) {
				w[i] = 0;
			}
		}
		for (int i = 0; i < n; ++i) {
			if ((i - x >= 0 && w[i - x]) || (i + x < n && w[i + x])) {
				if (s[i] == '0') {
					res = -1;
				}
			}
			else {
				if (s[i] == '1') {
					res = -1;
				}
			}
		}
		if (res == 0) {
			for (int i = 0; i < n; ++i) {
				cout << w[i];
			}
			cout << '\n';
		}
		else {
			cout << "-1" << '\n';
		}
	}
	return 0;
}