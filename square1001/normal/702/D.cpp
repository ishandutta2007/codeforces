#include <iostream>
#include <algorithm>
using namespace std;
long long d, k, a, b, t;
int main() {
	cin >> d >> k >> a >> b >> t;
	if (d <= k) cout << d * a << endl;
	else {
		long long c1 = k * a + (d - k) * b;
		long long c2 = (d / k * k) * a + (d / k - 1) * t + (d % k) * b;
		long long c3 = d * a + (d / k) * t;
		cout << min({ c1, c2, c3 }) << endl;
	}
	return 0;
}