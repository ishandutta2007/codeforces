#include <iostream>

using namespace std;

typedef long long ll;

ll rev(ll k) {
	ll sum = 0;
	ll scal = 1;
	while (k) {
		ll d = k % 10;
		k /= 10;

		sum += scal * (9 - d);
		scal *= 10;
	}
	return sum;
}

ll best = 0;

ll a, b;

void test(ll k) {
	if (k < a || k > b) return;
	ll prod = k * rev(k);
	if (prod > best) {
		best = prod;
	}
}

int main() {
	cin >> a >> b;

	ll p = 10;
	while ((p - 1) / 2 <= b) {
		test((p - 1) / 2);
		p *= 10;
	}

	test(a);
	test(b);

	cout << best << "\n";
	return 0;
}