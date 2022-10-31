#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; ++c) {
		int n;
		cin >> n;
		vector<bool> s;
		for (int i = 0; i < 2 * n - 1; ++i) {
			char x;
			cin >> x;
			if (x == '0') {
				s.push_back(false);
			}
			else if (x == '1') {
				s.push_back(true);
			}
		}


		for (int i = 0; i < n; ++i) {
			cout << s[2 * i];
		}
		cout << '\n';
	}
	return 0;
}