#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, k, ans = 2000000000;
		scanf("%d %d", &n, &k);
		for (int i = 1; i * i <= n && i <= k; ++i) {
			if (n % i == 0) {
				ans = min(ans, n / i);
				if (n / i <= k) ans = min(ans, i);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}