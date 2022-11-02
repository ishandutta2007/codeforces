#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, pl[1009], pr[1009]; long long p, a[1009], b[2009];
bool solve(long long x) {
	for (int i = 0; i < n; i++) {
		if (abs(a[i] - p) > x) return false;
		long long fl = min(p, a[i]), fr = max(p, a[i]);
		long long xl = fl - (x - abs(a[i] - p)) / 2, xr = fr + (x - abs(a[i] - p)) / 2;
		if (xl > xr) swap(xl, xr);
		pl[i] = lower_bound(b, b + m, xl) - b;
		pr[i] = lower_bound(b, b + m, xr + 1) - b;
		if (pl[i] == pr[i]) return false;
	}
	int ptr = 0;
	for (int i = 0; i < n; i++) {
		if (ptr >= pr[i]) return false;
		ptr = max(ptr, pl[i]) + 1;
	}
	return true;
}
int main() {
	cin >> n >> m >> p; p *= 2;
	for (int i = 0; i < n; i++) cin >> a[i], a[i] *= 2;
	for (int i = 0; i < m; i++) cin >> b[i], b[i] *= 2;
	sort(a, a + n);
	sort(b, b + m);
	long long l = -1, r = 4000000009;
	while (r - l > 1) {
		long long mid = (l + r) >> 1;
		if (solve(mid)) r = mid;
		else l = mid;
	}
	cout << r / 2 << endl;
	return 0;
}