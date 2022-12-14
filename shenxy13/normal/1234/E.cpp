#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	long long pfxsum[n + 1];
	fill_n(pfxsum, n + 1, 0);
	int prevx, curx;
	scanf("%d", &prevx);
	for (int i = 1; i < m; ++i) {
		scanf("%d", &curx);
		if (curx == prevx) {
			prevx = curx;
			continue;
		}
		pfxsum[0] += abs(curx - prevx);
		pfxsum[min(curx, prevx) - 1] -= abs(curx - prevx);
		pfxsum[min(curx, prevx) - 1] += max(curx, prevx) - 1;
		pfxsum[min(curx, prevx)] -= max(curx, prevx) - 1;
		pfxsum[min(curx, prevx)] += abs(curx - prevx) - 1;
		pfxsum[max(curx, prevx) - 1] -= abs(curx - prevx) - 1;
		pfxsum[max(curx, prevx) - 1] += min(curx, prevx);
		pfxsum[max(curx, prevx)] -= min(curx, prevx);
		pfxsum[max(curx, prevx)] += abs(curx - prevx);
		pfxsum[n] -= abs(curx - prevx);
		prevx = curx;
	}
	for (int i = 1; i <= n; ++i) pfxsum[i] += pfxsum[i - 1];
	for (int i = 0; i < n; ++i) printf("%lld ", pfxsum[i]);
	return 0;
}