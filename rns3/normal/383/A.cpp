#include <bits/stdc++.h>
using namespace std;

#define N 200020

int n, a, now;

int main() {
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a);
		now += a;
		ans += (1 - a) * now;
	}
	printf("%I64d\n", ans);
	return 0;
}