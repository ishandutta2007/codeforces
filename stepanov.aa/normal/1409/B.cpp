#include <iostream>
#include <algorithm>


using namespace std;


int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		long long a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		if (a > b) {
			swap(a, b);
			swap(x, y);
		}
		if (n > a - x && x > max(b - n, y)) {
			swap(a, b);
			swap(x, y);
		}
		if (n > a - x) {
			n -= a - x;
			a = x;
			b = max(b - n, y);
		}
		else {
			a -= n;
			n = 0;
		}
		cout << a * b << '\n';
	}
	return 0;
}