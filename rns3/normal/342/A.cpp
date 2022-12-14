#include <bits/stdc++.h>
using namespace std;

int n, a[8], x;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		a[x] ++;
	}
    if (a[1] * 3 == n && !a[5] && !a[7] && a[2] + a[3] == a[4] + a[6] && a[4] <= a[2]) {
        int u = a[4], w = a[3], v = n / 3 - u - w;
		while (u --) puts("1 2 4");
		while (v --) puts("1 2 6");
		while (w --) puts("1 3 6");
    }
    else {
		puts("-1");
    }
	return 0;
}