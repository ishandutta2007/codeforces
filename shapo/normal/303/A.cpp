#include <cstdio>

using namespace std;

#define maxn 100500

int n, a[maxn];

int main() {
	scanf("%d", &n);
	if (n & 1) {
		for (int i = 0; i < n; ++i)
			printf("%d ", i);
		int cur = (n + n - 2) % n;
		printf("\n");
		for (int i = 0; i < n; ++i) {
			printf("%d ", cur);
			cur = (cur + n - 2) % n;
		}
		cur = (n + n - 2) % n;
		printf("\n");
		for (int i = 0; i < n; ++i) {
			printf("%d ", (i + cur) % n);
			cur = (cur + n - 2) % n;
		}
		printf("\n");
	}
	else printf("-1\n");
	return 0;
}