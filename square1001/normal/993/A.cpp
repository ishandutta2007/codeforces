#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	vector<int> xa(4), ya(4), xb(4), yb(4);
	for (int i = 0; i < 4; ++i) {
		cin >> xa[i] >> ya[i];
	}
	int lx = *min_element(xa.begin(), xa.end());
	int ly = *min_element(ya.begin(), ya.end());
	int rx = *max_element(xa.begin(), xa.end());
	int ry = *max_element(ya.begin(), ya.end());
	int cx = 0, cy = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> xb[i] >> yb[i];
		cx += xb[i];
		cy += yb[i];
	}
	cx /= 4;
	cy /= 4;
	int cr = abs(xb[0] - cx) + abs(yb[0] - cy);
	bool ok = false;
	for (int i = lx; i <= rx; ++i) {
		for (int j = ly; j <= ry; ++j) {
			if (abs(i - cx) + abs(j - cy) <= cr) ok = true;
		}
	}
	cout << (ok ? "Yes\n" : "No\n");
	return 0;
}