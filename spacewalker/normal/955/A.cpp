#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef long long ll;

ll ceildiv(ll x, ll y) {
	return x / y + (x % y != 0);
}

int main() {
	cout << setprecision(9) << fixed;
	int hh, mm; cin >> hh >> mm;
	ll h, d, c, n; cin >> h >> d >> c >> n;
	if (hh >= 20) {
		cout << ceildiv(h, n) * c * 0.8;
	} else {
		ll hungerAt8 = h + (60-mm + 60*(20-hh-1))*d;
		cout << min(ceildiv(hungerAt8, n) * c * 0.8, (double)ceildiv(h, n) * c);
	}
	return 0;
}