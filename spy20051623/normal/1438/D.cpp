#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int s = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		s ^= a[i];
	}
	if (n % 2 == 0 && s) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	printf("%d\n", (n - 1) / 2 * 2);
	for (int i = 2; i + 1 <= n; i += 2) {
		printf("1 %d %d\n", i, i + 1);
	}
	for (int i = 2; i + 1 <= n; i += 2) {
		printf("1 %d %d\n", i, i + 1);
	}
	return 0;
}