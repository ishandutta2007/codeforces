#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	ll prevEnd = 0;
	for (int day = 0; day < n; ++day) {
		ll ai; scanf("%lld", &ai);
		// consider the interval prevEnd + 1 to prevEnd + ai
		// how many multiples of m does it contain?
		printf("%s%lld", (day == 0 ? "" : " "), (prevEnd + ai) / m - (prevEnd) / m);
		prevEnd += ai;
	}
	printf("\n");
	return 0;
}