#include <bits/stdc++.h>
using namespace std;

#define N 300001
const int P = 1e9 + 7;

int n, a[N], c[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort (a + 1, a + n + 1);
	c[0] = 1;
	for (int i = 1; i < n; i ++) c[i] = c[i-1] * 2 % P;
	int rlt = 0;
	for (int i = 1; i <= n; i ++) {
		rlt = (rlt + 1ll * a[i] * (P + c[i-1] - c[n-i])) % P;
	}
	printf("%d\n", rlt);
	return 0;
}