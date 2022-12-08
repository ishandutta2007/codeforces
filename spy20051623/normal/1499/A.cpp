#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, k1, k2, w, b, ww, bb;
	cin >> t;
	while (t--) {
		cin >> n >> k1 >> k2;
		cin >> w >> b;
		ww = k1 + k2;
		bb = 2 * n - ww;
		if (ww >= w * 2 && bb >= b * 2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}