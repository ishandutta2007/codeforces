#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		int x, y;
		cin >> x >> y;
		int r = x * x + y * y;
		int s = int(sqrt(r) + 1e-9);
		if (r == 0) cout << 0 << "\n";
		else if (s * s == r) {
			cout << 1 << "\n";
		} else {
			cout << 2 << "\n";
		}
	}
}