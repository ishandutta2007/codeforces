#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
typedef pair<long long, long long> ii;
const long long INF = 40000000000000000LL;
int main() {
	long long x0, y0, ax, ay, bx, by, xs, ys, t;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &x0, &y0, &ax, &ay, &bx, &by, &xs, &ys, &t);
	vector<ii> coords;
	while (x0 <= INF && y0 <= INF) {
		coords.push_back(ii(x0, y0));
		x0 = x0 * ax + bx;
		y0 = y0 * ay + by;
	}
	int ans = 0;
	for (int i = 0; i < coords.size(); ++i) {
		int temp = 0;
		long long j = i + 1, h;
		for (long long x = coords[i].first, y = coords[i].second, tt = llabs(x - xs) + llabs(y - ys); (h = tt) <= t && j < coords.size(); ++temp, ++j) tt += llabs(coords[j].first - x) + llabs(coords[j].second - y), x = coords[j].first, y = coords[j].second;
		if (j == coords.size() && h <= t) ++temp;
		ans = max(ans, temp);
		temp = 0, j = i - 1;
		for (long long x = coords[i].first, y = coords[i].second, tt = llabs(x - xs) + llabs(y - ys); (h = tt) <= t && j >= 0; ++temp, --j) tt += llabs(coords[j].first - x) + llabs(coords[j].second - y), x = coords[j].first, y = coords[j].second;
		if (j == -1 && h <= t) ++temp;
		ans = max(ans, temp);
	}
	printf("%d", ans);
	return 0;
}