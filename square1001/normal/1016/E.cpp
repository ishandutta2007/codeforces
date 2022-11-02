#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int sy, a, b, x, y, n, q;
	scanf("%d%d%d%d", &sy, &a, &b, &n);
	vector<double> v(2 * n);
	for (int i = 0; i < 2 * n; ++i) scanf("%Lf", &v[i]);
	vector<double> lens(n + 1);
	for (int i = 0; i < n; ++i) lens[i + 1] = lens[i] + (v[2 * i + 1] - v[2 * i]);
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &x, &y);
		double l = x + 1.0 * (a - x) * y / (y - sy), r = x + 1.0 * (b - x) * y / (y - sy);
		int pl = lower_bound(v.begin(), v.end(), l) - v.begin();
		int pr = lower_bound(v.begin(), v.end(), r) - v.begin();
		if (pl == pr) {
			printf("%d\n", pl % 2 == 1 ? b - a : 0);
		}
		else {
			double cs = lens[pr >> 1] - lens[(pl + 1) >> 1];
			if (pl % 2 == 1) cs += v[pl] - l;
			if (pr % 2 == 1) cs += r - v[pr - 1];
			printf("%.15Lf\n", cs / (r - l) * (b - a));
		}
	}
	return 0;
}