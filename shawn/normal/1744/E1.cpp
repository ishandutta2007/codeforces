#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	int _;
	cin >> _;
	while (_--) {
		ll a, b, c, d, t, x, y;
		bool flag = false;
		cin >> a >> b >> c >> d;
		for (x = a + 1; x <= c; x++) {
			t = a * b / __gcd(a * b, x);
			y = d / t * t;
			if (y > b) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << x << " " << y << "\n";
			// cout <<"mod = " << ((x * y) % (a * b)) << "\n";
		}
		else cout << "-1 -1\n";
	}
	return 0;	
}