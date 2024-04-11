#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n;
long long a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    if (n == 1) {
		puts("1 1\n1"); puts("1 1\n1");
		printf("1 1\n%lld\n", -a[1] - 2);
		return 0;
    }
    printf("1 %d\n", n - 1);
    for (int i = 1; i < n; i ++) {
		int r = a[i] % n;
		printf("%lld ", 1ll * (n - 1) * r);
		a[i] += 1ll * (n - 1) * r;
    }
    puts("");
    printf("%d %d\n", n, n);
    printf("%lld\n", -a[n]); a[n] = 0;
    printf("1 %d\n", n);
    for (int i = 1; i <= n; i ++) printf("%lld ", -a[i]); puts("");

    return 0;
}