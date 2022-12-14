#include <bits/stdc++.h>
using namespace std;

#define N 500010

int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort (a + 1, a + n + 1);
    int ans = n;
    for (int v = n / 2; v >= 1; v --) {
		if (a[ans] >= a[v] * 2) ans --;
    }
    printf("%d\n", ans);
	return 0;
}