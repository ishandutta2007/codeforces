#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int q, n, a, sum;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		sum = 0;
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a);
			sum += a;
		}
		sum = (sum + n - 1) / n;
		printf("%d\n", sum);
	}
	return 0;
}