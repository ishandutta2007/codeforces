#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int p = *min_element(a, a + n);
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (a[i] % p != 0) f = false;
	}
	if (!f) cout << -1 << endl;
	else {
		cout << n * 2 - 1 << endl;
		cout << a[0];
		for (int i = 1; i < n; i++) cout << ' ' << p << ' ' << a[i];
		cout << endl;
	}
	return 0;
}