#include <iostream>
#include <algorithm>
using namespace std;
int n, d, a[109];
int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ret = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (a[i] - a[j] <= d) {
				ret = min(ret, n - (i - j + 1));
			}
		}
	}
	cout << ret << endl;
	return 0;
}