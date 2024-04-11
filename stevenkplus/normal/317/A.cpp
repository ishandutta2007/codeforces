#include <iostream>

using namespace std;

typedef long long ll;

ll x, y, m;

ll go() {
	cin >> x >> y >> m;

	if (x >= m || y >= m) return 0;
	if (x > y) swap(x, y);
	if (x <= 0 && y <= 0) {
		return -1;
	}

	ll ret = 0;
	if (x <= 0) {
		ll need = (-x) / y;
		x += need * y;
		ret += need;
	}

	while (x < m && y < m) {
		++ret;
		ll z = x + y;
		if (x < y) x = z;
		else y = z;
	}

	return ret;
}

int main() {
	ll ans = go();
	cout << ans << "\n";
}