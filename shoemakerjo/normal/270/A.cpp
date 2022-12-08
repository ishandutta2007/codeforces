#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		if (360 % (180-n) == 0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	// cin >> t;
}