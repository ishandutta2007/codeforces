#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, a[N], s;
long long sum = 0, b[N];

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), sum += a[i] + 1ll * i * n;
	if (sum <= s) {
		printf("%d %I64d\n", n, sum);
		return 0;
	}
	int st = 0, en = n, mid;
	while (st < en - 1) {
        mid = (st + en) / 2;
		for (int i = 1; i <= n; i ++) b[i] = a[i] + 1ll * mid * i;
		sort (b + 1, b + n + 1);
        sum = 0;
        for (int i = 1; i <= mid; i ++) sum += b[i];
        if (sum <= s) st = mid;
        else en = mid;
	}
    for (int i = 1; i <= n; i ++) b[i] = a[i] + 1ll * st * i;
    sort (b + 1, b + n + 1);
    sum = 0;
    for (int i = 1; i <= st; i ++) sum += b[i];
    printf("%d %I64d\n", st, sum);
	return 0;
}