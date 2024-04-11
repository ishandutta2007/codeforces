#include <iostream>
#include <algorithm>
using namespace std;
int n, a[200009];
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ctr = a[0], d = 0, num = 1;
	for (int i = 0; i <= 30; ++i) {
		for (int j = 0; j < n; ++j) {
			if (binary_search(a, a + n, a[j] + (1 << i))) {
				if (num <= 2) {
					ctr = a[j];
					num = 2;
					d = i;
				}
				if (binary_search(a, a + n, a[j] - (1 << i))) {
					ctr = a[j];
					num = 3;
					d = i;
				}
			}
		}
	}
	cout << num << endl;
	if (num == 1) cout << ctr << '\n';
	if (num == 2) cout << ctr << ' ' << ctr + (1 << d) << '\n';
	if (num == 3) cout << ctr - (1 << d) << ' ' << ctr << ' ' << ctr + (1 << d) << '\n';
	return 0;
}