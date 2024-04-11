#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (n == 1) cout << a[0] << '\n';
	else {
		int mx = *max_element(a.begin(), a.end());
		int mn = *min_element(a.begin(), a.end());
		int cx = 0, cn = 0; long long ans = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] >= 0) ans += a[i], ++cx;
			else ans -= a[i], ++cn;
		}
		if (cx == 0) ans += 2 * mx;
		if (cn == 0) ans -= 2 * mn;
		cout << ans << '\n';
	}
	return 0;
}