#include <cstdio>
#pragma warning(disable : 4996)
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i == 1) puts("2");
		else printf("%lld\n", 1LL * i * i * i + 2LL * i * i + 1);
	}
	return 0;
}