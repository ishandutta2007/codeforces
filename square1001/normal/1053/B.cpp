#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int c0 = 1, c1 = 0, s = 0;
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		long long x;
		cin >> x;
		while (x) {
			if (x & 1) ++b[i];
			x >>= 1;
		}
		s ^= b[i] % 2;
		if (s == 0) ++c0;
		else ++c1;
	}
	long long ans = 1LL * c0 * (c0 - 1) / 2 + 1LL * c1 * (c1 - 1) / 2;
	for (int i = 0; i < n; ++i) {
		int mx = 0, sum = 0;
		for (int j = 0; j < 62 && i + j < n; ++j) {
			mx = max(mx, b[i + j]);
			sum += b[i + j];
			if (sum % 2 == 0 && mx * 2 > sum) --ans;
		}
	}
	cout << ans << endl;
	return 0;
}