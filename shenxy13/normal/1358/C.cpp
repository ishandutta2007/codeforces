#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		long long x1, y1, x2, y2;
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		printf("%lld\n", (x2 - x1 + 2 * y2 - 2 * y1 + 1) * (x2 - x1) / 2 - (x2 - x1 + 1) * (x2 - x1) / 2 + 1);
	}
	return 0;
}