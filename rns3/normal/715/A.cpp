#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	puts("2");
	for (int i = 2; i <= n; i ++) {
		printf("%I64d\n", 1ll * i * (i + 1) * (i + 1) - i + 1);
	}
	return 0;
}