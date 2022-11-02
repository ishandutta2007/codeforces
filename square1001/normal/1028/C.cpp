#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> XA(N), YA(N), XB(N), YB(N);
	for (int i = 0; i < N; ++i) {
		cin >> XA[i] >> YA[i] >> XB[i] >> YB[i];
	}
	vector<int> mxl(N + 1, -inf), myl(N + 1, -inf), mxr(N + 1, inf), myr(N + 1, inf);
	for (int i = N - 1; i >= 0; --i) {
		mxl[i] = max(mxl[i + 1], XA[i]);
		myl[i] = max(myl[i + 1], YA[i]);
		mxr[i] = min(mxr[i + 1], XB[i]);
		myr[i] = min(myr[i + 1], YB[i]);
	}
	int xl = -inf, yl = -inf, xr = inf, yr = inf;
	for (int i = 0; i < N; ++i) {
		int cxl = max(xl, mxl[i + 1]);
		int cyl = max(yl, myl[i + 1]);
		int cxr = min(xr, mxr[i + 1]);
		int cyr = min(yr, myr[i + 1]);
		if (cxl <= cxr && cyl <= cyr) {
			cout << cxl << ' ' << cyl << endl;
			break;
		}
		xl = max(xl, XA[i]);
		yl = max(yl, YA[i]);
		xr = min(xr, XB[i]);
		yr = min(yr, YB[i]);
	}
	return 0;
}