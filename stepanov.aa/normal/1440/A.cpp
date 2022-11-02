#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, c0, c1, h;
		cin >> n >> c0 >> c1 >> h;
		if (c0 <= c1) {
			c1 = min(c1, c0 + h);
		}
		else {
			c0 = min(c0, c1 + h);
		}
		long long res = 0;
		for (int i = 0; i < n; ++i) {
			char c;
			cin >> c;
			if (c == '0') {
				res += c0;
			}
			else if (c == '1') {
				res += c1;
			}
		}
		cout << res << "\n";
	}
	return 0;
}