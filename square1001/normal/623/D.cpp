#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<double> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] /= 100;
	}
	vector<int> c(n, 1);
	double ans = n;
	double cur = 1;
	for (int i = 0; i < n; ++i) {
		cur *= 1.0 - pow(1.0 - a[i], c[i]);
	}
	while (true) {
		ans += 1.0 - cur;
		if (cur > 1.0 - 1.0e-9) break;
		int mx = -1; double delta = -1.0;
		for (int i = 0; i < n; ++i) {
			double d = (1.0 - pow(1.0 - a[i], c[i] + 1)) / (1.0 - pow(1.0 - a[i], c[i]));
			if (d > delta) {
				delta = d;
				mx = i;
			}
		}
		++c[mx];
		cur *= delta;
	}
	cout.precision(15);
	cout << ans << endl;
	return 0;
}