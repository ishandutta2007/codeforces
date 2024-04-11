#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100009];
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int mn = *min_element(a, a + n);
	int mx = *max_element(a, a + n);
	int md = mx - mn;
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == mn) ++x;
		if (a[i] == mn + 1) ++y;
		if (a[i] == mn + 2) ++z;
	}
	int mcrash = n + 1, xa = -1;
	for (int i = 0; i <= n; ++i) {
		int xd = i, zd = (z - x) + xd, yd = n - xd - zd;
		int crash = min(x, xd) + min(y, yd) + min(z, zd);
		if (zd >= 0 && yd >= 0 && (md == 2 || zd == 0) && (md >= 1 || yd == 0) && mcrash > crash) {
			mcrash = crash;
			xa = i;
		}
	}
	int za = (z - x) + xa, ya = n - xa - za;
	cout << mcrash << endl;
	for (int i = 0; i < xa; ++i) cout << mn << ' ';
	for (int i = 0; i < ya; ++i) cout << mn + 1 << ' ';
	for (int i = 0; i < za; ++i) cout << mn + 2 << ' ';
	return 0;
}