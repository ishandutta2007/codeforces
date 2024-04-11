#include <bits/stdc++.h>
using namespace std;

int n, a[1005], b[1005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++) {
        if (i & 1) b[i] = a[i + 1 >> 1];
        else b[i] = a[n - (i - 1 >> 1)];
        printf("%d ", b[i]);
    }
	return 0;
}