#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)

int main() {
	int H, W; cin >> H >> W;
	vector<string> a(H);
	rep(y, H) cin >> a[y];
	int yl = H, yr = 0, xl = W, xr = 0;
	rep(y, H) rep(x, W) {
		if (a[y][x] == 'B') {
			yl = min(yl, y);
			yr = max(yr, y + 1);
			xl = min(xl, x);
			xr = max(xr, x + 1);
		}
	}
	int ym = (yl + yr) / 2;
	int xm = (xl + xr) / 2;
	cout << ym + 1 << ' ' << xm + 1 << endl;
}