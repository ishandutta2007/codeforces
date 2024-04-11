#include <bits/stdc++.h>

using namespace std;
int ans = 0, a[20];

int main() {
	long long n;
	scanf("%I64d", &n);
	a[0] = 1;
	a[1] = 0;
	a[2] = 0;
	a[3] = 0;
	a[4] = 1;
	a[5] = 0;
	a[6] = 1;
	a[7] = 0;
	a[8] = 2;
	a[9] = 1;
	a[10] = 1;
	a[11] = 2;
	a[12] = 0;
	a[13] = 1;
	a[14] = 0;
	a[15] = 0;
	do {
		ans += a[n % 16];
		n /= 16;
	} while(n);
	printf("%d\n", ans);
}