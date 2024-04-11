#include <iostream>
#include <algorithm>
using namespace std;
int n, w, a[109], p[109], s[109];
int main() {
	cin >> n >> w;
	for (int i = 0; i < n; i++) cin >> a[i], p[i] = i, s[i] = (a[i] + 1) / 2, w -= s[i];
	sort(p, p + n, [](int i, int j) { return a[i] < a[j]; });
	if (w < 0) cout << -1 << endl;
	else {
		for (int i = n - 1; i >= 0; i--) {
			if (w >= a[p[i]] - s[p[i]]) {
				w -= a[p[i]] - s[p[i]];
				s[p[i]] = a[p[i]];
			}
			else {
				s[p[i]] += w;
				w = 0;
			}
		}
		for (int i = 0; i < n; i++) cout << s[i] << ' ';
		cout << endl;
	}
	return 0;
}