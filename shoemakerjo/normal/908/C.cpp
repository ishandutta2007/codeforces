#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r;
	cin >> n >> r;
	int xs[n];
	for (int i = 0; i < n; i++) {
		cin >> xs[i];
	}
	double ans[n];
	for (int i = 0; i < n; i++) {
		ans[i] = r;
		for (int j = 0; j < i; j++) {
			if (abs(xs[i]-xs[j]) <= 2*r) {
				double xdiff = xs[i]-xs[j];
				double ydiff = sqrt(4*r*r - xdiff*xdiff);
				ans[i] = max(ans[i], ydiff+ans[j]);
			}
		}
	}
	cout << fixed << setprecision(10);
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	cin >> n;
}