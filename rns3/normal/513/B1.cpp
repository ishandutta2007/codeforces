#include <bits/stdc++.h>

using namespace std;



int n;

long long x;



int a[111];



int main() {

	scanf("%d %I64d", &n, &x);

	long long now = 1ll << (n - 2);

	int le = 1, ri = n;

	for (int i = 1; i < n; i ++) {

		if (x > now) x -= now, a[ri--] = i;

		else a[le++] = i;

		now >>= 1;

	}

	a[le] = n;

	for (int i = 1; i <= n; i ++) printf("%d%c", a[i], i == n ? '\n' : ' ');



	return 0;

}