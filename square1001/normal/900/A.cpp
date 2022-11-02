#include <iostream>
using namespace std;
int n, x, y;
int main() {
	cin >> n;
	int lc = 0, rc = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		if (x < 0) ++lc;
		else ++rc;
	}
	cout << (lc <= 1 || rc <= 1 ? "Yes\n" : "No\n");
	return 0;
}