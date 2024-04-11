#include <bits/stdc++.h>

using namespace std;

int main() {
	int _;
	cin >> _;
	while (_ --) {
		int x, y;
		cin >> x >> y;
		int z = x * x + y * y;
		// cout << z << endl;
		if (!x && !y) cout << "0\n";
		else if ((int)sqrt(z) * sqrt(z) == z) cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}