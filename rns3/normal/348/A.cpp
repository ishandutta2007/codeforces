#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, maxx = 0, x;
	long long sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		maxx = max(maxx, x);
		sum += x;
	}
	printf("%I64d\n", max(1ll * maxx, (sum + n - 2)/ (n - 1)));
	return 0;
}