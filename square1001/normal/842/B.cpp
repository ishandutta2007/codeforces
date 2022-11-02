#include <iostream>
using namespace std;
int r, d, n, x, y, c;
int main() {
	cin >> r >> d >> n;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> c;
		if ((r - d + c) * (r - d + c) <= x * x + y * y && x * x + y * y <= (r - c) * (r - c)) ret++;
	}
	cout << ret << endl;
	return 0;
}