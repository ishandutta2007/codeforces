#include <iostream>
#include <iomanip>

using namespace std;

typedef long long ll;

ll x, y, m;

ll max(ll a, ll b) { return (a > b) ? a : b; }
void swap(ll &a, ll &b) {
	ll tmp = a;
	a = b;
	b = tmp;
}

ll get(ll x, ll y) {
	return (y - x + y - 1) / y;
}

int main() {
	cin >> x >> y >> m;
	if (max(x, y) >= m) {
		cout << 0 << endl;
		return 0;
	}
	if (max(x, y) <= 0) {
		cout << "-1" << endl;
		return 0;
	}
	if (x > y) swap(x, y);
	ll res = 0LL;
	while (max(x, y) < m) {
		ll cur = get(x, y);
		x += cur * y;
		if (x == y) ++res, x += y;
		swap(x, y);
		res += cur;
	}
	cout << res << endl;
	return 0;
}