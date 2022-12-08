#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int x[n], y[n];
	int xs[n], ys[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		xs[i] = y[i];
		ys[i] = x[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (x[i] + x[j] <= a) {
				if (y[j] <= b && y[i] <= b) {
					ans = max(ans, x[i]*y[i] + x[j]*y[j]);
				}
			}
			if (y[i] + y[j] <= b) {
				if (x[j] <= a && x[i] <= a) {
					ans = max(ans, x[i]*y[i] + x[j]*y[j]);
				}
			}

			if (xs[i] + x[j] <= a) {
				if (y[j] <= b && ys[i] <= b) {
					ans = max(ans, x[i]*y[i] + x[j]*y[j]);
				}
			}
			if (ys[i] + y[j] <= b) {
				if (x[j] <= a && xs[i] <= a) {
					ans = max(ans, x[i]*y[i] + x[j]*y[j]);
				}
			}

			if (x[i] + xs[j] <= a) {
				if (ys[j] <= b && y[i] <= b) {
					ans = max(ans, x[i]*y[i] + x[j]*y[j]);
				}
			}
			if (y[i] + ys[j] <= b) {
				if (xs[j] <= a && x[i] <= a) {
					ans = max(ans, x[i]*y[i] + x[j]*y[j]);
				}
			}

			if (xs[i] + xs[j] <= a) {
				if (ys[j] <= b && ys[i] <= b) {
					ans = max(ans, x[i]*y[i] + x[j]*y[j]);
				}
			}
			if (ys[i] + ys[j] <= b) {
				if (xs[j] <= a && xs[i] <= a) {
					ans = max(ans, x[i]*y[i] + x[j]*y[j]);
				}
			}
		}
	}
	cout << ans << "\n";
	cin >> n;
}