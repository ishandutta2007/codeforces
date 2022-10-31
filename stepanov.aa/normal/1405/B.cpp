#include <iostream>
#include <vector>


using namespace std;


int main() {
	int t;
	cin >> t;
	for (int x = 0; x < t; ++x) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int m = 0;
		int b = n - 1;
		long long res = 0;

		for (int i = 0; i < n; ++i) {

			while (a[i] != 0) {
				if (a[i] < 0) {
					m = i;
					while (a[b] <= 0) --b;
					if ((-a[m]) > a[b]) {
						a[m] += a[b];
						res += a[b];
						a[b] = 0;
					}
					else {
						res -= a[m];
						a[b] += a[m];
						a[m] = 0;
					}
				}
				else {
					while (a[m] >= 0) ++m;
					if ((-a[m]) > a[i]) {
						a[m] += a[i];
						a[i] = 0;
					}
					else {
						a[i] += a[m];
						a[m] = 0;
					}
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}