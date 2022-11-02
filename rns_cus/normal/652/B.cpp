#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, a[N];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n / 2; i ++) {
		printf("%d %d ", a[i], a[n-i+1]);
    }
    if (n & 1) printf("%d\n", a[n/2+1]);
    else puts("");
	return 0;
}