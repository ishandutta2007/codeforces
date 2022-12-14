///	D : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;

int n, m, k, a, b, A, B;

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &k);
	if (k - m >= 0) {
		puts("1"); return 0;
	}
	if (n + k - m < 0) {
		puts("0"); return 0;
	}
	double ans = 1.0;
	for (int i = 1; i <= k + 1; i ++) ans *= 1.0 * (m - i + 1) / (n + i);
	ans = 1 - ans;
	printf("%lf\n", ans);
	return 0;
}