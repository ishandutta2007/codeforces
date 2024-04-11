///	C : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;

int n, l, a[111], ans;

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &l);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = l; i <= 100; i ++) {
		int rlt = 0;
		for (int j = 1; j <= n; j ++) rlt += a[j] / i * i;
		ans = max(ans, rlt);
	}
	printf("%d\n", ans);
	return 0;
}