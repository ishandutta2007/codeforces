#include <bits/stdc++.h>
using namespace std;

int a, b, k;

int main() {
	scanf("%d %d %d", &k, &a, &b);
	int ans = 0;
	ans = (a / k) + (b / k);
	if ((a < k) && (b % k)) {
		puts("-1");
		return 0;
	}
	if ((b < k) && (a % k)) {
		puts("-1");
		return 0;
	}
	printf("%d\n", ans);

	return 0;
}