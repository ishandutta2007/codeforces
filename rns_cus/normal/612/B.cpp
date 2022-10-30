#include <bits/stdc++.h>
using namespace std;

int n, a[200200], x;

int main() {
//	freopen("b.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &x), a[x] = i;
    long long ans = 0;
    for (int i = 2; i <= n; i ++) ans += abs(a[i] - a[i-1]);
    printf("%I64d\n", ans);
	return 0;
}