#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	long long n, m, k, k2;
	cin >> n >> m >> k;
	k2 = k;
	if (k2 < n) {
		cout << k2 + 1 << " " << 1;
		return 0;
	}
	k2 -= n;
	long long ans1 = n - (k2 / (m - 1));
	long long ans2 = k2 % (2 * m - 2);
	if (ans1 % 2 == 0) {
		ans2 = ans2 + 2;
	}
	else {
		ans2 = m - (ans2 - (m - 1));
	}
	cout << ans1 << " " << ans2;
	return 0;
}