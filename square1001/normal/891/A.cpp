#include <iostream>
#include <algorithm>
using namespace std;
int n, a[2009];
int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main() {
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) cnt++;
	}
	if (cnt != 0) cout << n - cnt << endl;
	else {
		int ret = (1 << 30);
		for (int i = 0; i < n; i++) {
			int g = a[i];
			for (int j = i + 1; j < n; j++) {
				g = gcd(g, a[j]);
				if (g == 1) ret = min(ret, j - i - 1);
			}
		}
		cout << (ret == (1 << 30) ? -1 : n + ret) << endl;
	}
	return 0;
}