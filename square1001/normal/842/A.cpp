#include <iostream>
using namespace std;
int l, r, x, y, k;
int main() {
	cin >> l >> r >> x >> y >> k;
	bool flag = false;
	for (int i = x; i <= y; i++) {
		if (l <= 1LL * i * k && 1LL * i * k <= r) {
			flag = true;
		}
	}
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}