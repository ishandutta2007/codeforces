#include <map>
#include <set>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const int inf = 1012345678;
const double pi = acos(-1.0);
int main() {
	int Q;
	cin >> Q;
	cout.precision(20);
	while (Q--) {
		int N;
		cin >> N; N *= 2;
		double pang = 2 * pi * (N % 4 == 0 ? 360.0 / (2 * N) : 360.0 / (4 * N)) / 360;
		double xl = 1.0e+99, xr = -1.0e+99, yl = 1.0e+99, yr = -1.0e+99;
		for (int j = 0; j < N; ++j) {
			double px = cos(2 * pi * j / N + pang);
			double py = sin(2 * pi * j / N + pang);
			xl = min(xl, px);
			xr = max(xr, px);
			yl = min(yl, py);
			yr = max(yr, py);
		}
		double opt2 = max(xr - xl, yr - yl);
		cout << fixed << opt2 / sin(pi / N) / 2 << endl;
	}
	return 0;
}