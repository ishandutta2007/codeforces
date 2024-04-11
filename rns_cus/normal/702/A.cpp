#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, a[N];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	int ans = 1, rlt = 1;
	for (int i = 2; i <= n; i ++) {
		if (a[i] > a[i-1]) rlt ++;
		else rlt = 1;
		ans = max(ans, rlt);
	}
    printf("%d\n", ans);
	return 0;
}