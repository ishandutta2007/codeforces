#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, k;
		scanf("%d %d", &n, &k);
		if (n % 2) {
			if (k % 2) {
				if (n < k) printf("NO\n");
				else {
					printf("YES\n");
					for (int i = 1; i < k; ++i) printf("1 ");
					printf("%d\n", n - k + 1);
				}
			} else printf("NO\n");
		} else {
			if (k % 2) {
				if (n < 2 * k) printf("NO\n");
				else {
					printf("YES\n");
					for (int i = 1; i < k; ++i) printf("2 ");
					printf("%d\n", n - 2 * k + 2);
				}
			} else {
				if (n < k) printf("NO\n");
				else {
					printf("YES\n");
					for (int i = 1; i < k; ++i) printf("1 ");
					printf("%d\n", n - k + 1);
				}
			}
		}
	}
	return 0;
}