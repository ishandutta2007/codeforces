#include <bits/stdc++.h>
using namespace std;
int t, x, y, p, q;
int main() {
	cin >> t;
	while(t--) {
		cin >> x >> y >> p >> q;
		if(p == 0) cout << (x == 0 ? 0 : -1) << endl;
		else if(p == q) cout << (x == y ? 0 : -1) << endl;
		else cout << 1LL * max((x + p - 1) / p, (y - x + q - p - 1) / (q - p)) * q - y << endl;
	}
	return 0;
}