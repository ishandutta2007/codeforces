#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		long long a, b, c, d;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		if (a > b * c) {
			printf("-1\n");
			continue;
		}
		long long k = a / (b * d);
		long long maxd = (k + 1) * a - k * (k + 1) * b * d / 2;
		printf("%lld\n", maxd);
	}
	return 0;
}