#include <bits/stdc++.h>
using namespace std;

#define N 202020

int a[N], n, k;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	long long rlt = 0;
	for (int i = 1; i <= n; i ++) {
		if (!a[i]) continue;
		int now = (a[i] - 1) / k + 1;
		int tot = now * k;
		a[i+1] = max(0, a[i+1] - (tot - a[i]));
		rlt += now;
	}
	printf("%I64d\n", rlt);

	return 0;
}