#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	bool ok = false;
	for (int i = 2; i < n; i++) {
		if (a[i - 2] + a[i - 1] > a[i]) ok = true;
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}