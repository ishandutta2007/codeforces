#include <bits/stdc++.h>
using namespace std;

#define N 100010

int main() {
    int a[N], n, k, mm;
    scanf("%d %d", &n, &k);
    mm = 1000000000;
    for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		mm = min(a[i], mm);
    }
    int tag = 1;
    long long ans = 0;
    for (int i = 1; i <= n && tag; i ++) {
		if ((a[i] - mm) % k) tag = 0;
		else ans += (a[i] - mm) / k;
    }
    if (tag) printf("%I64d\n", ans);
    else puts("-1");
	return 0;
}