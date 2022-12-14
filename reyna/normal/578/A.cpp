//In the name of God
#include <bits/stdc++.h>
using namespace std;
long double calc(int a, int b, int k = 1) {
	if (a < b)
		return 1e11;
	int l = 0, r = 1e9 + 9;
	while (l < r - 1) {
		int mid = l + r >> 1;
		if ((long double)a / (mid * 2 + k) >= b)
			l = mid;
		else
			r = mid;
	}
	if (!l || (long double)a / (l * 2 + k) < b)
		return 1e11;
//	cerr << "hi " << l << endl;
	return (long double)a / (l * 2 + k);
}
int main() {
	int a, b; cin >> a >> b;
	long double x = calc(a - b, b, 0), y = calc(a + b, b, 0);
	if (x > 1e10 && y > 1e10) {
		cout << -1 << endl;
		return 0;
	}
	cerr << x << ' ' << y << endl;
	cout << setprecision(9) << fixed << min(x, y) << endl;
	return 0;
}