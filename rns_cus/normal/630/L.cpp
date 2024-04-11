#include <bits/stdc++.h>
using namespace std;

long long n, ans, a[7];

int main() {
//	freopen("l.in", "r", stdin);
	scanf("%I64d", &n);
	for (int i = 5; i >= 1; i --) a[i] = n % 10, n /= 10;
	n = a[1] * 10000 + a[3] * 1000 + a[5] * 100 + a[4] * 10 + a[2];
	ans = 1;
	for (int i = 1; i <= 5; i ++) ans = ans * n % 100000;
	printf("%05I64d\n", ans);
	return 0;
}