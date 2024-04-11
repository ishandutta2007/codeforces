#include <iostream>
#include <algorithm>
using namespace std;
long long n, m;
int main() {
	cin >> n >> m;
	long long l = 0, r = 2000000009;
	while (r - l > 1) {
		long long mid = (l + r) >> 1;
		if (mid * (mid + 1) / 2 + (m + mid + 1) >= n) r = mid;
		else l = mid;
	}
	cout << min(n, m + r + 1) << endl;
	return 0;
}