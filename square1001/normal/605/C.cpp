#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, p, q;
	cin >> n >> p >> q;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}
	double l = 0.0, r = 1.0e+10;
	for (int i = 0; i < n; ++i) {
		if (1LL * p * b[i] == 1LL * q * a[i]) {
			r = min(r, 1.0 * p / a[i]);
		}
	}
	for (int i = 0; i < 70; ++i) {
		double m = (l + r) * 0.5;
		double pl = 0.0, pr = m / p;
		for (int j = 0; j < n; ++j) {
			if (1LL * p * b[j] == 1LL * q * a[j]) continue;
			double pos = (b[j] * m - q) / (1LL * b[j] * p - 1LL * a[j] * q);
			if (1LL * p * b[j] > 1LL * q * a[j]) {
				pl = max(pl, pos);
			}
			else {
				pr = min(pr, pos);
			}
		}
		if (pl > pr) r = m;
		else l = m;
	}
	cout << fixed << setprecision(15) << l << endl;
	return 0;
}