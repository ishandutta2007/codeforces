#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int r, d; scanf("%d %d", &r, &d);
	int n; scanf("%d", &n);
	int layingOnCrust = 0;
	for (int i = 0; i < n; ++i) {
		int xi, yi, ri; scanf("%d %d %d", &xi, &yi, &ri);
		double cdist = hypot(xi, yi);
		if (cdist - ri >= r - d && cdist + ri <= r) {
			++layingOnCrust;
		}
	}
	printf("%d\n", layingOnCrust);
	return 0;
}