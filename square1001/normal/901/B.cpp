#include <iostream>
using namespace std;
int n, a[155][155];
int main() {
	cin >> n;
	a[0][0] = 1;
	a[1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			a[i][j + 1] ^= a[i - 1][j];
			a[i][j] ^= a[i - 2][j];
		}
	}
	cout << n << '\n';
	for (int i = 0; i <= n; ++i) {
		cout << a[n][i] << ' ';
	}
	cout << '\n';
	cout << n - 1 << '\n';
	for (int i = 0; i < n; ++i) {
		cout << a[n - 1][i] << ' ';
	}
	return 0;
}