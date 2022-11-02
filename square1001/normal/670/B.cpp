#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
int n, m, a[100009];
int main() {
	scanf("%d%d", &n, &m), m--;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n + 1; i++) {
		int r = 1LL * i * (i + 1) / 2;
		if (r > m) {
			int s = 1LL * i * (i - 1) / 2;
			printf("%d\n", a[m - s]);
			break;
		}
	}
	return 0;
}