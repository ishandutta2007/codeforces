#include <vector>
#include <iostream>
using namespace std;
int n, m, a[555];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	int ret = 0;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] + a[i] < m) {
			ret += m - (a[i - 1] + a[i]);
			a[i] = m - a[i - 1];
		}
	}
	cout << ret << endl;
	for (int i = 0; i < n; i++) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
	return 0;
}