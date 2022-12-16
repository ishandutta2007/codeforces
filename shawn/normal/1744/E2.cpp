#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	int _;
	cin >> _;
	while (_--) {
		ll a, b, c, d, x, y;
		bool flag = false;
		cin >> a >> b >> c >> d;
		std::vector<ll> va;
		std::vector<ll> vb;
		for (int i = 1; i * i <= a; i++) {
			if (a % i) continue;
			va.push_back(i);
			if (i * i != a) va.push_back(a / i);
		}
		for (int i = 1; i * i <= b; i++) {
			if (b % i) continue;
			vb.push_back(i);
			if (i * i != b) vb.push_back(b / i);
		}

		for (ll p : va) {
			if (flag) break;
			for (ll q : vb) {
				ll k1 = p * q;
				ll k2 = a * b / k1;
				x = (a + 1 + (k1 - 1)) / k1 * k1;
				y = (b + 1 + (k2 - 1)) / k2 * k2;
				if (x <= c && y <= d) {
					flag = true;
					break;
				}
			}
		}

		if (flag) {
			cout << x << " " << y << "\n";
			// cout <<"mod = " << ((x * y) % (a * b)) << "\n";
		}
		else cout << "-1 -1\n";
	}
	return 0;	
	return 0;	
}